SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin
DATA_DIR = data

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)
EXE = $(BIN_DIR)/main

CXX ?= g++
CFLAGS = -std=c++11 -Wall -g
LFLAGS =
FILE =

install: setup clean $(EXE)

setup:
	echo -n ===SETTING UP ' '
	mkdir -p $(SRC_DIR) $(BIN_DIR) $(INCLUDE_DIR) $(DATA_DIR)
	echo OK

clean:
	echo -n ===CLEANING $(BIN_DIR)/ ' '
	rm -f $(BIN_DIR)/*.o $(EXE)
	echo OK

$(EXE): $(OBJ)
	echo -n ===LINKING ' '
	$(CXX) $^ -o $@ $(LFLAGS)
	echo OK

$(OBJ): $(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	echo -n ===COMPILING $< ' '
	$(CXX) -c $< -o $@ $(CFLAGS)
	echo OK

run:
	./$(EXE) $(FILE)

test:
	for file in $(DATA_DIR)/* ; do echo ===TESTING $${file} ; ./$(EXE) $${file} ; done

debug:
	echo $(SRC)
	echo $(OBJ)
	echo $(EXE)

.PHONY: install setup clean $(EXE) $(OBJ) run test
.SILENT: install setup clean $(EXE) $(OBJ) run test
