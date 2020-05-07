# Master makefile

# Project root directory path (containing this Makefile)
PATH_ROOT := $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST)))))
# Linear algebra library path
PATH_LA := $(PATH_ROOT)/la
# LU decomposition library path
PATH_LUD := $(PATH_LA)/ext

# Object files
OBJ := $(PATH_LA)/la_matrix.o $(PATH_LUD)/lu_decomposition.o $(PATH_ROOT)/test.o
# Libraries
LIB := $(PATH_LA)/libla.a
# Executable files
EXE := $(PATH_ROOT)/test

# Compiler
CC := g++
# Compiler flags
CFLAGS := -g -Wall -I $(PATH_ROOT) -I $(PATH_LA) -I $(PATH_LUD)
# Linker flags
LFLAGS := -L $(PATH_LA)

# --------------------------------------------------
# Default target

default: test

# --------------------------------------------------
# Build test program

test: $(PATH_ROOT)/test.o $(PATH_LA)/libla.a
	@echo "<---------------------------------------"
	@echo "Building test program."
	@$(CC) $(LFLAGS) -o $@ $^ -l la
	@echo "--------------------------------------->"
	@echo

# --------------------------------------------------
# Build static library la (linear algebra)

$(PATH_LA)/libla.a: $(PATH_LA)/la_matrix.o $(PATH_LUD)/lu_decomposition.o
	ar rcs $@ $^

# --------------------------------------------------
# Build object file (.cpp)

%.o: %.cpp
	@echo "<---------------------------------------"
	@echo "Building $@."
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "--------------------------------------->"
	@echo

# --------------------------------------------------
# Build object file (.c)

%.o: %.c
	@echo "<---------------------------------------"
	@echo "Building $@."
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "--------------------------------------->"
	@echo

# --------------------------------------------------
# Remove build

.PHONY: clean

clean:
	@echo "<---------------------------------------"
	@echo "Removing build."
	@rm -f $(OBJ) $(LIB) $(EXE)
	@echo "--------------------------------------->"
	@echo
