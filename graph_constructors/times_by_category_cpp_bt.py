import pandas as pd
import matplotlib.pyplot as plt
from pathlib import Path

# MAS cosas de paths
SCRIPT_DIR = Path(__file__).resolve().parent
CSV_DIR = SCRIPT_DIR.parent / 'csv_data'
IMG_DIR = SCRIPT_DIR.parent / 'graph_images'
IMG_DIR.mkdir(exist_ok=True)


bt_df = pd.read_csv(CSV_DIR / "cpp_bt_results.csv")

bt_df = bt_df[bt_df['TimeTaken(s)'] != 'DNF'].copy()
bt_df['TimeTaken(s)'] = bt_df['TimeTaken(s)'].astype(float)


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

bt_df = bt_df[bt_df['Category'].isin(['Star', 'Cycle', 'No Conflict'])]
grouped = bt_df.groupby(['NumItems', 'Category'])['TimeTaken(s)'].mean().unstack()

# ordenar por n
grouped = grouped.sort_index()

# evitar log(o) y q quede mas lindo
epsilon = 1e-2
grouped = grouped.applymap(lambda x: x if x > 0 else epsilon)


plt.figure(figsize=(12, 7))

for category in ['Star', 'Cycle', 'No Conflict']:
    if category in grouped.columns:
        plt.plot(grouped.index, grouped[category], label=category, marker='o', zorder=3)

plt.yscale('log')
plt.ylim(bottom=epsilon)


min_n = grouped.index.min()
max_n = grouped.index.max()
plt.xticks(range(min_n, max_n + 1, 10))

plt.xlabel('NumItems (n)')
plt.ylabel('Tiempo promedio de ejecucion (s) [Escala Log]')
plt.title('Tiempos promedio por estructura C++ BT')
plt.legend()

plt.grid(True, which="both", ls="--", linewidth=0.5, zorder=0)

plt.tight_layout()
plt.savefig(IMG_DIR / 'cpp_bt_structures_times_graph.png', dpi=300)
plt.show()
print(bt_df.head())
print(bt_df['Category'].value_counts())
