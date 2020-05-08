# Master makefile
#
# Build core API: make
# Build sample program: make raytracer
# Clean build: make clean

# --------------------------------------------------

# Project root directory path (containing this Makefile)
PATH_ROOT := $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST)))))
# Raytracer source code path
PATH_SRC := $(PATH_ROOT)/src
# Linear algebra library path
PATH_LA := $(PATH_ROOT)/la
# LU decomposition library path
PATH_LUD := $(PATH_LA)/ext

# Object files
OBJ := $(PATH_LA)/la_matrix.o $(PATH_LUD)/lu_decomposition.o \
$(PATH_SRC)/rt_raytracer.o $(PATH_SRC)/rt_scene.o \
$(PATH_SRC)/rt_shape.o $(PATH_SRC)/rt_triangle.o $(PATH_SRC)/rt_sphere.o \
$(PATH_ROOT)/config_parse.o $(PATH_ROOT)/sample_program.o $(PATH_LA)/la_test.o
# Libraries
LIB := $(PATH_LA)/libla.a $(PATH_ROOT)/librt.a
# Executable files
EXE := $(PATH_ROOT)/la_test $(PATH_ROOT)/raytracer

# Compiler
CC := g++
# Compiler flags
CFLAGS := -g -Wall -I $(PATH_ROOT) -I $(PATH_SRC) -I $(PATH_LA) -I $(PATH_LUD)
# Linker flags
LFLAGS := -L $(PATH_LA) -L $(PATH_ROOT)

# --------------------------------------------------
# Default target

default: $(PATH_ROOT)/librt.a

# --------------------------------------------------
# Build sample program

raytracer: \
$(PATH_ROOT)/sample_program.o $(PATH_ROOT)/config_parse.o $(PATH_ROOT)/librt.a
	@echo "<---------------------------------------"
	@echo "Building sample raytracer program."
	@$(CC) $(LFLAGS) -o $@ $(PATH_ROOT)/sample_program.o \
	$(PATH_ROOT)/config_parse.o -l rt
	@echo "--------------------------------------->"
	@echo

# --------------------------------------------------
# Build linear algebra test program

la_test: \
$(PATH_LA)/la_test.o $(PATH_LA)/libla.a
	@echo "<---------------------------------------"
	@echo "Building linear algebra test program."
	@$(CC) $(LFLAGS) -o $@ $(PATH_LA)/la_test.o -l la
	@echo "--------------------------------------->"
	@echo

# --------------------------------------------------
# Build static library rt (raytracer)

$(PATH_ROOT)/librt.a: \
$(PATH_SRC)/rt_raytracer.o $(PATH_SRC)/rt_scene.o \
$(PATH_SRC)/rt_shape.o $(PATH_SRC)/rt_triangle.o $(PATH_SRC)/rt_sphere.o \
$(PATH_LA)/libla.a
	@echo "<---------------------------------------"
	@echo "Building static library for raytracer routines."
	@ar rcs $@ $^
	@echo "--------------------------------------->"
	@echo

# --------------------------------------------------
# Build static library la (linear algebra)

$(PATH_LA)/libla.a: \
$(PATH_LA)/la_matrix.o $(PATH_LUD)/lu_decomposition.o
	@echo "<---------------------------------------"
	@echo "Building static library for linear algebra routines."
	@ar rcs $@ $^
	@echo "--------------------------------------->"
	@echo

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
