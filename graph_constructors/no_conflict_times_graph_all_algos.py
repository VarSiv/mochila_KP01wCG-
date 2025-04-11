import pandas as pd
import matplotlib.pyplot as plt
from pathlib import Path

# set up directories
SCRIPT_DIR = Path(__file__).resolve().parent
CSV_DIR = SCRIPT_DIR.parent / 'csv_data'
IMG_DIR = SCRIPT_DIR.parent / 'graph_images'
IMG_DIR.mkdir(exist_ok=True)


cpp_dp_df = pd.read_csv(CSV_DIR / "cpp_dp_results.csv")
py_dp_df = pd.read_csv(CSV_DIR / "py_dp_results.csv")
cpp_bt_df = pd.read_csv(CSV_DIR / "cpp_bt_results.csv")
py_bt_df = pd.read_csv(CSV_DIR / "py_bt_results.csv")

# Csacar dnfs y poner tiempo como float
def clean_df(df):
    df = df[df['TimeTaken(s)'] != 'DNF'].copy()
    df['TimeTaken(s)'] = df['TimeTaken(s)'].astype(float)
    return df

cpp_dp_df = clean_df(cpp_dp_df)
py_dp_df = clean_df(py_dp_df)
cpp_bt_df = clean_df(cpp_bt_df)
py_bt_df = clean_df(py_bt_df)


merged_df = cpp_dp_df.merge(py_dp_df, on='InstancePath', suffixes=('_cpp_dp', '_py_dp')) \
                     .merge(cpp_bt_df, on='InstancePath') \
                     .merge(py_bt_df, on='InstancePath', suffixes=('_cpp_bt', '_py_bt'))

merged_df['NumItems'] = merged_df['NumItems_cpp_dp']


grouped = merged_df.groupby('NumItems').agg({
    'TimeTaken(s)_cpp_dp': 'mean',
    'TimeTaken(s)_py_dp': 'mean',
    'TimeTaken(s)_cpp_bt': 'mean',
    'TimeTaken(s)_py_bt': 'mean'
}).reset_index()


grouped = grouped.sort_values('NumItems')

epsilon = 1e-2
cpp_dp_times = grouped['TimeTaken(s)_cpp_dp'].apply(lambda x: x if x > 0 else epsilon)
py_dp_times = grouped['TimeTaken(s)_py_dp'].apply(lambda x: x if x > 0 else epsilon)
cpp_bt_times = grouped['TimeTaken(s)_cpp_bt'].apply(lambda x: x if x > 0 else epsilon)
py_bt_times = grouped['TimeTaken(s)_py_bt'].apply(lambda x: x if x > 0 else epsilon)


plt.figure(figsize=(12, 7))
plt.plot(grouped['NumItems'], cpp_dp_times, label='DP (C++)', marker='o', zorder=3)
plt.plot(grouped['NumItems'], py_dp_times, label='DP (Python)', marker='s', zorder=3)
plt.plot(grouped['NumItems'], cpp_bt_times, label='BT (C++)', marker='^', zorder=3)
plt.plot(grouped['NumItems'], py_bt_times, label='BT (Python)', marker='x', zorder=3)

plt.yscale('log')
plt.ylim(bottom=epsilon)


min_n = grouped['NumItems'].min()
max_n = grouped['NumItems'].max()
plt.xticks(range(min_n, max_n + 1, 10))

plt.xlabel('NumItems (n)')
plt.ylabel('Tiempo promedio de ejecucion (s) [Escala Log]')
plt.title('Tiempos de ejecucion por algoritmo y lenguaje (solo instancias completadas por todos)')
plt.legend()

plt.grid(True, which="both", ls="--", linewidth=0.5, zorder=0)

plt.tight_layout()
plt.savefig(IMG_DIR / 'all_algorithms_times_graph.png', dpi=300)
plt.show()
