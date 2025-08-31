# Compiler and flags
CXX = g++
CXXFLAGS = -fmodules -O2 -static -std=c++23 -Wall

# Default target - shows usage
.PHONY: help
help:
	@echo "Usage: make <source_name>"
	@echo "Example: make hello (compiles hello.cpp to hello)"

# Pattern rule: compile any .cpp file to executable
%: %.cpp
	mkdir -p build
	$(CXX) $(CXXFLAGS) $< -o build/$@

# Run binary
run:
	./build/%

# Clean up executables (optional)
.PHONY: clean
clean:
	rm -f $(shell find . -maxdepth 1 -type f -executable ! -name ".*" ! -name "Makefile")

# List available source files (optional)
.PHONY: list
list:
	@echo "Available C++ source files:"
	@ls -1 *.cpp 2>/dev/null || echo "No .cpp files found"
