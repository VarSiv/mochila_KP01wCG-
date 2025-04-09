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
        rows = [
            row for row in reader 
            if 'no_conflict' in row[2]  # Only include rows with 'no_conflict' in InstancePath
        ]
        total = len(rows)
        finished = sum(1 for row in rows if row[1] != 'DNF')
        return (finished / total) * 100 if total > 0 else 0

# File names and labels
files = {
    CSV_DIR / "cpp_bf_results.csv": "C++ Brute Force",
    CSV_DIR / "cpp_bt_results.csv": "C++ Backtracking",
    CSV_DIR / "py_bt_results.csv": "Python Backtracking",
    CSV_DIR / "cpp_dp_results.csv": "C++ Dynamic Programming",
    CSV_DIR / "py_dp_results.csv": "Python Dynamic Programming"
}
# Assign group-based colors
color_map = {
    "C++ Brute Force": "skyblue",
    "C++ Backtracking": "lightgreen",
    "Python Backtracking": "lightgreen",
    "C++ Dynamic Programming": "plum",
    "Python Dynamic Programming": "plum"
}

# Calculate percentages
labels = []
percentages = []
colors = []

for filename, label in files.items():
    percent = calculate_finished_percentage(filename)
    labels.append(label)
    percentages.append(percent)
    colors.append(color_map[label])

# Plotting
plt.figure(figsize=(10, 6))
bars = plt.bar(labels, percentages, color=colors)

# Add percentage labels on top of bars
for bar, percentage in zip(bars, percentages):
    yval = bar.get_height()
    plt.text(bar.get_x() + bar.get_width()/2, yval + 1, f'{percentage:.1f}%', ha='center', va='bottom')

plt.ylabel('Percentage of Finished Runs (%)')
plt.title('Percentage of Finished Runs by Method (No Conflict Instances Only)')
plt.ylim(0, 115)  # Give some space above 100%
plt.grid(axis='y', linestyle='--', alpha=0.7)
plt.tight_layout()

IMG_DIR = SCRIPT_DIR.parent / 'graph_images'
# Save plot
plt.savefig(IMG_DIR/"no_conflict_instance_finish_percentages.png")
plt.close()
