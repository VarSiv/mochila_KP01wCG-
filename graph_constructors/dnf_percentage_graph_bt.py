import csv
import matplotlib.pyplot as plt
from pathlib import Path

# Get the directory of the current script (graph_constructors/)
SCRIPT_DIR = Path(__file__).resolve().parent

# Path to the csv_data folder relative to the script
CSV_DIR = SCRIPT_DIR.parent / 'csv_data'
def calculate_finished_percentage(file_path):
    with open(file_path, newline='') as csvfile:
        reader = csv.reader(csvfile)
        next(reader)  # Skip header
        rows = list(reader)
        total = len(rows)
        finished = sum(1 for row in rows if row[1] != 'DNF')
        return (finished / total) * 100 if total > 0 else 0

# File names and labels
files = {
    CSV_DIR / "cpp_bf_results.csv": "C++ Brute Force",
    CSV_DIR / "cpp_bt_results.csv": "C++ Backtracking",
    CSV_DIR / "py_bt_results.csv": "Python Backtracking",
}

# Calculate percentages
labels = []
percentages = []

for filename, label in files.items():
    percent = calculate_finished_percentage(filename)
    labels.append(label)
    percentages.append(percent)

# Plotting
plt.figure(figsize=(8, 5))
bars = plt.bar(labels, percentages, color=['skyblue', 'lightgreen', 'plum'])

# Add percentage labels on top of bars
for bar, percentage in zip(bars, percentages):
    yval = bar.get_height()
    plt.text(bar.get_x() + bar.get_width()/2, yval + 1, f'{percentage:.1f}%', ha='center', va='bottom')

plt.ylabel('Porcentaje de instancias terminadas (%)')
plt.title('Porcentaje de todas las instancias terminadas')
plt.ylim(0, 100)
plt.grid(axis='y', linestyle='--', alpha=0.7)
plt.tight_layout()
IMG_DIR = SCRIPT_DIR.parent / 'graph_images'
# Save plot
plt.savefig(IMG_DIR/"all_instance_finish_percentages.png")
plt.close()
