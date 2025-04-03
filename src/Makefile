CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

SRC_DIR = .
BUILD_DIR = ../build

SRC = main.cpp Graph.cpp KP01withCGInstance.cpp Solution.cpp DynamicProgrammingKP01.cpp \
      BacktrackingKP01wCG.cpp BruteForceKP01wCG.cpp
HEADERS = Graph.h KP01withCGInstance.h Solution.h DynamicProgrammingKP01.h \
          BacktrackingKP01wCG.h BruteForceKP01wCG.h

# Convert src/*.cpp -> build/*.o
OBJ = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRC))

EXEC = knapsack_solver

all: $(BUILD_DIR) $(BUILD_DIR)/$(EXEC)

# Link object files into final executable
$(BUILD_DIR)/$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each .cpp file into a .o file in build/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean compiled files
clean:
	rm -rf $(BUILD_DIR)
