import csv
import matplotlib.pyplot as plt
from pathlib import Path

# cosas de paths
SCRIPT_DIR = Path(__file__).resolve().parent

CSV_DIR = SCRIPT_DIR.parent / 'csv_data'
def calculate_finished_percentage(file_path):
    with open(file_path, newline='') as csvfile:
        reader = csv.reader(csvfile)
        next(reader)  # Skip header
        rows = [
            row for row in reader 
            if 'no_conflict' in row[2]  # solo incluir cosos con no conflict
        ]
        total = len(rows)
        finished = sum(1 for row in rows if row[1] != 'DNF')
        return (finished / total) * 100 if total > 0 else 0


files = {
    CSV_DIR / "cpp_bf_results.csv": "C++ BF",
    CSV_DIR / "cpp_bt_results.csv": "C++ BT",
    CSV_DIR / "py_bt_results.csv": "Python BT",
    CSV_DIR / "cpp_dp_results.csv": "C++ DP",
    CSV_DIR / "py_dp_results.csv": "Python DP"
}

color_map = {
    "C++ BF": "skyblue",
    "C++ BT": "lightgreen",
    "Python BT": "lightgreen",
    "C++ DP": "plum",
    "Python DP": "plum"
}


labels = []
percentages = []
colors = []

for filename, label in files.items():
    percent = calculate_finished_percentage(filename)
    labels.append(label)
    percentages.append(percent)
    colors.append(color_map[label])


plt.figure(figsize=(10, 6))
bars = plt.bar(labels, percentages, color=colors)

# porcentajes sobre barrtas
for bar, percentage in zip(bars, percentages):
    yval = bar.get_height()
    plt.text(bar.get_x() + bar.get_width()/2, yval + 1, f'{percentage:.1f}%', ha='center', va='bottom')

plt.ylabel('Porcentaje de instancias terminadas (%)')
plt.title('Porcentaje de las instancias sin conflictos terminadas')
plt.ylim(0, 115)  # para q el 100% no llegue hasta el techo
plt.grid(axis='y', linestyle='--', alpha=0.7)
plt.tight_layout()

IMG_DIR = SCRIPT_DIR.parent / 'graph_images'

plt.savefig(IMG_DIR/"no_conflict_instance_finish_percentages.png")
plt.close()
