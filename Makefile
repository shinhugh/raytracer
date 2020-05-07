# Master makefile

# Project root directory (containing this Makefile)
PATH_ROOT := $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST)))))
# Linear algebra library path
PATH_LA := $(PATH_ROOT)/la
# Compiler
CC := g++
# Compiler flags
CFLAGS := -I $(PATH_ROOT) -I $(PATH_LA)
# Linker flags
LFLAGS := -L $(PATH_ROOT) -L $(PATH_LA)
# Object files
OBJ := $(PATH_LA)/la_matrix.o $(PATH_ROOT)/test.o
# Executable files
EXE := $(PATH_ROOT)/test

# --------------------------------------------------
# Default target

default:
	@echo "<---------------------------------------"
	@echo "Make: default"
	@echo "Project root: $(PATH_ROOT)"
	@echo "CC: $(CC)"
	@echo "CFLAGS: $(CFLAGS)"
	@echo "TEST: $(CC) $(CFLAGS) -c -o $@ $<"
	@echo "--------------------------------------->"

# --------------------------------------------------
# Build test program

test: $(PATH_ROOT)/test.o $(PATH_LA)/la_matrix.o
	@echo "<---------------------------------------"
	$(CC) $(LFLAGS) -o $@ $^
	@echo "--------------------------------------->"

# --------------------------------------------------
# Build object file

%.o: %.cpp
	@echo "<---------------------------------------"
	$(CC) $(CFLAGS) -c -o $@ $<
	@echo "--------------------------------------->"

# --------------------------------------------------
# Remove build

.PHONY: clean

clean:
	rm -f $(OBJ) $(EXE)
