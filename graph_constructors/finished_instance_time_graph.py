import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from pathlib import Path

# Get the directory of the current script (graph_constructors/)
SCRIPT_DIR = Path(__file__).resolve().parent

# Path to the csv_data folder relative to the script
CSV_DIR = SCRIPT_DIR.parent / 'csv_data'

# Load CSV files
bf_df = pd.read_csv(CSV_DIR / "cpp_bf_results.csv")
bt_df = pd.read_csv(CSV_DIR / "cpp_bt_results.csv")

# Remove DNF entries and convert TimeTaken(s) to float
bf_df = bf_df[bf_df['TimeTaken(s)'] != 'DNF'].copy()
bt_df = bt_df[bt_df['TimeTaken(s)'] != 'DNF'].copy()
bf_df['TimeTaken(s)'] = bf_df['TimeTaken(s)'].astype(float)
bt_df['TimeTaken(s)'] = bt_df['TimeTaken(s)'].astype(float)

# Merge on InstancePath to keep only entries that both completed
merged_df = pd.merge(bf_df, bt_df, on='InstancePath', suffixes=('_bf', '_bt'))

# Group by NumItems
grouped = merged_df.groupby('NumItems_bf').agg({
    'TimeTaken(s)_bf': 'mean',
    'TimeTaken(s)_bt': 'mean'
}).reset_index()

# Sort by NumItems
grouped = grouped.sort_values('NumItems_bf')

# Y-axis minimum (log scale)
min_time = min(grouped['TimeTaken(s)_bf'].min(), grouped['TimeTaken(s)_bt'].min())

# Avoid log(0) and make small values visible
epsilon = 1e-2  # small bump so points are visible above x-axis
bf_times = grouped['TimeTaken(s)_bf'].apply(lambda x: x if x > 0 else epsilon)
bt_times = grouped['TimeTaken(s)_bt'].apply(lambda x: x if x > 0 else epsilon)

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(grouped['NumItems_bf'], bf_times, label='Brute Force', marker='o', zorder=3)
plt.plot(grouped['NumItems_bf'], bt_times, label='Backtracking', marker='s', zorder=3)

plt.yscale('log')
plt.ylim(bottom=epsilon)

# Set x-ticks for each integer in the range
min_n = grouped['NumItems_bf'].min()
max_n = grouped['NumItems_bf'].max()
plt.xticks(range(min_n, max_n + 1, 1))

plt.xlabel('NumItems (n)')
plt.ylabel('Tiempo promedio de ejecucion (s) [Escala Log]')
plt.title('Tiempos de ejecucion (Escala Log) por Algoritmo')
plt.legend()

# Make grid go behind the data points
plt.grid(True, which="both", ls="--", linewidth=0.5, zorder=0)

IMG_DIR = SCRIPT_DIR.parent / 'graph_images'
IMG_DIR.mkdir(exist_ok=True)  # Create it if it doesn't exist

plt.tight_layout()
plt.savefig(IMG_DIR/'cpp_bt_cpp_bf_times_graph.png', dpi=300)
plt.show()
