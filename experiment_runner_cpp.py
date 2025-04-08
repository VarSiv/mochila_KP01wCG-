import os
import subprocess
import time
import csv


algo = "dp"

CSV_FILENAME = "cpp_"+algo+"_results.csv"

def list_files_in_instances():
    instances_folder = "instances"
    
    if not os.path.exists(instances_folder):
        print(f"Folder '{instances_folder}' does not exist.")
        return

    # Write CSV header
    with open(CSV_FILENAME, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(["NumItems", "TimeTaken(s)", "InstancePath"])
   

    for root, _, files in os.walk(instances_folder):
        for file in files:
            file_path = os.path.join(root, file)
            execute_knapsack_solver(file_path)

def get_num_items_from_file(path):
    try:
        with open(path, 'r') as f:
            first_line = f.readline()
            return int(first_line.strip())
    except Exception as e:
        print(f"Error reading NumItems from {path}: {e}")
        return "Unknown"

def execute_knapsack_solver(instance_path):
    #solving algorithm here
    command = ["build/knapsack_solver", algo, instance_path]
    has_conflict = "no_conflict" not in os.path.basename(instance_path)
    num_items = get_num_items_from_file(instance_path)
    print(f"Using: {algo}")
    print(f"Executing {instance_path}")

    start_time = time.time()
    try:
        result = subprocess.run(command, timeout=600, capture_output=True, text=True)
        elapsed_time = time.time() - start_time
        print(f"Executed {instance_path} in {elapsed_time:.2f} seconds")

        with open(CSV_FILENAME, mode='a', newline='') as file:
            writer = csv.writer(file)
            writer.writerow([num_items, f"{elapsed_time:.2f}", instance_path])

    except subprocess.TimeoutExpired:
        print(f"{instance_path}: DNF (Did Not Finish)")
        with open(CSV_FILENAME, mode='a', newline='') as file:
            writer = csv.writer(file)
            writer.writerow([num_items, "DNF", instance_path])

if __name__ == "__main__":
    list_files_in_instances()
