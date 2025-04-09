import pandas as pd
import matplotlib.pyplot as plt
from pathlib import Path

# Set up directories
SCRIPT_DIR = Path(__file__).resolve().parent
CSV_DIR = SCRIPT_DIR.parent / 'csv_data'
IMG_DIR = SCRIPT_DIR.parent / 'graph_images'
IMG_DIR.mkdir(exist_ok=True)

# Load CSV files
cpp_dp_df = pd.read_csv(CSV_DIR / "cpp_dp_results.csv")
py_dp_df = pd.read_csv(CSV_DIR / "py_dp_results.csv")

# Remove DNF entries and convert TimeTaken(s) to float
cpp_dp_df = cpp_dp_df[cpp_dp_df['TimeTaken(s)'] != 'DNF'].copy()
py_dp_df = py_dp_df[py_dp_df['TimeTaken(s)'] != 'DNF'].copy()
cpp_dp_df['TimeTaken(s)'] = cpp_dp_df['TimeTaken(s)'].astype(float)
py_dp_df['TimeTaken(s)'] = py_dp_df['TimeTaken(s)'].astype(float)

# Merge on InstancePath to keep only entries that both completed
merged_df = pd.merge(cpp_dp_df, py_dp_df, on='InstancePath', suffixes=('_cpp', '_py'))

# Group by NumItems
grouped = merged_df.groupby('NumItems_cpp').agg({
    'TimeTaken(s)_cpp': 'mean',
    'TimeTaken(s)_py': 'mean'
}).reset_index()

# Sort by NumItems
grouped = grouped.sort_values('NumItems_cpp')

# Avoid log(0)
epsilon = 1e-2
cpp_times = grouped['TimeTaken(s)_cpp'].apply(lambda x: x if x > 0 else epsilon)
py_times = grouped['TimeTaken(s)_py'].apply(lambda x: x if x > 0 else epsilon)

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(grouped['NumItems_cpp'], cpp_times, label='DP (C++)', marker='o', zorder=3)
plt.plot(grouped['NumItems_cpp'], py_times, label='DP (Python)', marker='s', zorder=3)

plt.yscale('log')
plt.ylim(bottom=epsilon)

# Set x-ticks for each integer in the range
min_n = grouped['NumItems_cpp'].min()
max_n = grouped['NumItems_cpp'].max()
plt.xticks(range(min_n, max_n + 1, 10))

plt.xlabel('NumItems (n)')
plt.ylabel('Tiempo promedio de ejecucion (s) [Escala Log]')
plt.title('Tiempos de ejecucion de DP (Python vs C++)')
plt.legend()

plt.grid(True, which="both", ls="--", linewidth=0.5, zorder=0)

plt.tight_layout()
plt.savefig(IMG_DIR / 'cpp_py_dp_times_graph.png', dpi=300)
plt.show()
