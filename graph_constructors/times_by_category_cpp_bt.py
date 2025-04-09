import pandas as pd
import matplotlib.pyplot as plt
from pathlib import Path

# Set up directories
SCRIPT_DIR = Path(__file__).resolve().parent
CSV_DIR = SCRIPT_DIR.parent / 'csv_data'
IMG_DIR = SCRIPT_DIR.parent / 'graph_images'
IMG_DIR.mkdir(exist_ok=True)

# Load the CSV
bt_df = pd.read_csv(CSV_DIR / "cpp_bt_results.csv")

# Filter out DNF and convert TimeTaken(s) to float
bt_df = bt_df[bt_df['TimeTaken(s)'] != 'DNF'].copy()
bt_df['TimeTaken(s)'] = bt_df['TimeTaken(s)'].astype(float)

# Categorize each row
def categorize(path):
    if "star" in path:
        return "Star"
    elif "cycle" in path:
        return "Cycle"
    elif "no_conflict" in path:
        return "No Conflict"
    else:
        return "Other"

bt_df['Category'] = bt_df['InstancePath'].apply(categorize)

# Only keep the three desired categories
bt_df = bt_df[bt_df['Category'].isin(['Star', 'Cycle', 'No Conflict'])]

# Group by NumItems and Category, calculate mean time
grouped = bt_df.groupby(['NumItems', 'Category'])['TimeTaken(s)'].mean().unstack()

# Sort by NumItems
grouped = grouped.sort_index()

# Avoid log(0)
epsilon = 1e-2
grouped = grouped.applymap(lambda x: x if x > 0 else epsilon)

# Plotting
plt.figure(figsize=(12, 7))

for category in ['Star', 'Cycle', 'No Conflict']:
    if category in grouped.columns:
        plt.plot(grouped.index, grouped[category], label=category, marker='o', zorder=3)

plt.yscale('log')
plt.ylim(bottom=epsilon)

# X-ticks every 10 units
min_n = grouped.index.min()
max_n = grouped.index.max()
plt.xticks(range(min_n, max_n + 1, 10))

plt.xlabel('NumItems (n)')
plt.ylabel('Tiempo promedio de ejecucion (s) [Escala Log]')
plt.title('Tiempos promedio por estructura')
plt.legend()

plt.grid(True, which="both", ls="--", linewidth=0.5, zorder=0)

plt.tight_layout()
plt.savefig(IMG_DIR / 'cpp_bt_structures_times_graph.png', dpi=300)
plt.show()
print(bt_df.head())
print(bt_df['Category'].value_counts())
