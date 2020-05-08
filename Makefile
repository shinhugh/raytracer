# Master makefile
#
# Build core API: make
# Build sample program: make raytracer
# Clean build: make clean

# --------------------------------------------------

# Project root directory path (containing this Makefile)
PATH_ROOT := $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST)))))
# Core API source code path
PATH_SRC := $(PATH_ROOT)/src
# Core API header files path (interfaces for user)
PATH_INT := $(PATH_SRC)/interface
# Linear algebra library path
PATH_LA := $(PATH_ROOT)/la
# LU decomposition library path
PATH_LUD := $(PATH_LA)/ext
# Sample program path
PATH_SAMP := $(PATH_ROOT)/sample
# FreeImage path
PATH_FI := $(PATH_ROOT)/FreeImage

# Object files
OBJ := $(PATH_ROOT)/*.o $(PATH_SRC)/*.o $(PATH_INT)/*.o $(PATH_LA)/*.o \
$(PATH_LUD)/*.o $(PATH_SAMP)/*.o
# Libraries
LIB := $(PATH_LA)/libla.a $(PATH_ROOT)/librt.a
# Executable files
EXE := $(PATH_ROOT)/raytracer $(PATH_ROOT)/debug $(PATH_ROOT)/la_test

# Compiler
CC := g++
# Compiler flags
CFLAGS := -g -Wall -I $(PATH_INT) -I $(PATH_LA) -I $(PATH_LUD) -I $(PATH_SAMP) \
-I $(PATH_FI)
# Linker flags
LFLAGS := -L $(PATH_LA) -L $(PATH_ROOT) -L $(PATH_FI)

# --------------------------------------------------
# Default target

default: $(PATH_ROOT)/librt.a

# --------------------------------------------------
# Build debug program

debug: \
$(PATH_ROOT)/debug.o $(PATH_ROOT)/librt.a
	@echo "<---------------------------------------"
	@echo "Building debug program."
	@$(CC) $(LFLAGS) -o $@ $< -l rt -l freeimageplus
	@echo "--------------------------------------->"
	@echo

# --------------------------------------------------
# Build sample program

raytracer: \
$(PATH_SAMP)/sample_program.o $(PATH_SAMP)/config_parse.o $(PATH_ROOT)/librt.a
	@echo "<---------------------------------------"
	@echo "Building sample raytracer program."
	@$(CC) $(LFLAGS) -o $@ $(PATH_SAMP)/sample_program.o \
	$(PATH_SAMP)/config_parse.o -l rt -l freeimageplus
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
# Build static library rt (raytracer core API)

$(PATH_ROOT)/librt.a: \
$(PATH_SRC)/rt_raytracer.o $(PATH_SRC)/rt_scene.o \
$(PATH_SRC)/rt_shape.o $(PATH_SRC)/rt_triangle.o $(PATH_SRC)/rt_sphere.o \
$(PATH_SRC)/rt_light.o $(PATH_SRC)/rt_light_pt.o $(PATH_SRC)/rt_light_dir.o \
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
