import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from pathlib import Path

SCRIPT_DIR = Path(__file__).resolve().parent

CSV_DIR = SCRIPT_DIR.parent / 'csv_data'


bf_df = pd.read_csv(CSV_DIR / "cpp_bf_results.csv")
bt_df = pd.read_csv(CSV_DIR / "cpp_bt_results.csv")

# Rsacar las q no terminaron
bf_df = bf_df[bf_df['TimeTaken(s)'] != 'DNF'].copy()
bt_df = bt_df[bt_df['TimeTaken(s)'] != 'DNF'].copy()
bf_df['TimeTaken(s)'] = bf_df['TimeTaken(s)'].astype(float)
bt_df['TimeTaken(s)'] = bt_df['TimeTaken(s)'].astype(float)

# quedarse solo donde terminaron ambas
merged_df = pd.merge(bf_df, bt_df, on='InstancePath', suffixes=('_bf', '_bt'))


grouped = merged_df.groupby('NumItems_bf').agg({
    'TimeTaken(s)_bf': 'mean',
    'TimeTaken(s)_bt': 'mean'
}).reset_index()


grouped = grouped.sort_values('NumItems_bf')


min_time = min(grouped['TimeTaken(s)_bf'].min(), grouped['TimeTaken(s)_bt'].min())

#evitar log(0) y para q no este pegado al piso
epsilon = 1e-2  
bf_times = grouped['TimeTaken(s)_bf'].apply(lambda x: x if x > 0 else epsilon)
bt_times = grouped['TimeTaken(s)_bt'].apply(lambda x: x if x > 0 else epsilon)


plt.figure(figsize=(10, 6))
plt.plot(grouped['NumItems_bf'], bf_times, label='Brute Force', marker='o', zorder=3)
plt.plot(grouped['NumItems_bf'], bt_times, label='Backtracking', marker='s', zorder=3)

plt.yscale('log')
plt.ylim(bottom=epsilon)

min_n = grouped['NumItems_bf'].min()
max_n = grouped['NumItems_bf'].max()
plt.xticks(range(min_n, max_n + 1, 1))

plt.xlabel('NumItems (n)')
plt.ylabel('Tiempo promedio de ejecucion (s) [Escala Log]')
plt.title('Tiempos de ejecucion (Escala Log) por Algoritmo')
plt.legend()


plt.grid(True, which="both", ls="--", linewidth=0.5, zorder=0)

IMG_DIR = SCRIPT_DIR.parent / 'graph_images'
IMG_DIR.mkdir(exist_ok=True) 

plt.tight_layout()
plt.savefig(IMG_DIR/'cpp_bt_cpp_bf_times_graph.png', dpi=300)
plt.show()


