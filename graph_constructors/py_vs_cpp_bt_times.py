import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from pathlib import Path

# Get the directory of the current script (graph_constructors/)
SCRIPT_DIR = Path(__file__).resolve().parent

# Path to the csv_data folder relative to the script
CSV_DIR = SCRIPT_DIR.parent / 'csv_data'

# Load correct CSV files
py_df = pd.read_csv(CSV_DIR / "py_bt_results.csv")
cpp_df = pd.read_csv(CSV_DIR / "cpp_bt_results.csv")

# Remove DNF entries and convert TimeTaken(s) to float
py_df = py_df[py_df['TimeTaken(s)'] != 'DNF'].copy()
cpp_df = cpp_df[cpp_df['TimeTaken(s)'] != 'DNF'].copy()
py_df['TimeTaken(s)'] = py_df['TimeTaken(s)'].astype(float)
cpp_df['TimeTaken(s)'] = cpp_df['TimeTaken(s)'].astype(float)

# Merge on InstancePath to keep only entries that both completed
merged_df = pd.merge(py_df, cpp_df, on='InstancePath', suffixes=('_py', '_cpp'))

# Group by NumItems
grouped = merged_df.groupby('NumItems_py').agg({
    'TimeTaken(s)_py': 'mean',
    'TimeTaken(s)_cpp': 'mean'
}).reset_index()

# Sort by NumItems
grouped = grouped.sort_values('NumItems_py')

# Avoid log(0)
epsilon = 1e-2
py_times = grouped['TimeTaken(s)_py'].apply(lambda x: x if x > 0 else epsilon)
cpp_times = grouped['TimeTaken(s)_cpp'].apply(lambda x: x if x > 0 else epsilon)

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(grouped['NumItems_py'], py_times, label='Python Backtracking', marker='o', zorder=3)
plt.plot(grouped['NumItems_py'], cpp_times, label='C++ Backtracking', marker='s', zorder=3)

plt.yscale('log')
plt.ylim(bottom=epsilon)

min_n = grouped['NumItems_py'].min()
max_n = grouped['NumItems_py'].max()
plt.xticks(range(min_n, max_n + 1, 5))

plt.xlabel('NumItems (n)')
plt.ylabel('Tiempo promedio de ejecucion (s) [Escala Log]')
plt.title('Tiempos de ejecucion (Escala Log) - Python vs C++ Backtracking')
plt.legend()
plt.grid(True, which="both", ls="--", linewidth=0.5, zorder=0)

# Save to image
IMG_DIR = SCRIPT_DIR.parent / 'graph_images'
IMG_DIR.mkdir(exist_ok=True)

plt.tight_layout()
plt.savefig(IMG_DIR / 'py_vs_cpp_bt_times.png', dpi=300)
plt.show()
