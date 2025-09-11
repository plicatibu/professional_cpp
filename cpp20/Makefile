# Compiler and flags
CXX = g++
#CXXFLAGS = -fmodules -g -static -std=c++23 -Wall -Wextra -Wpedantic -Weffc++ -fanalyzer -fsanitize=address 
CXXFLAGS = -fmodules -g -std=c++23 -Wall -Wextra -Wpedantic -Weffc++ -fanalyzer -fsanitize=address -Wl,-rpath=/usr/local/gcc-15-git/lib64

# Default target - shows usage
.PHONY: help
help:
	@echo "Usage:"
	@echo "  make <source_name>   # compiles <source_name>.cpp to ./build/<source_name>"
	@echo "  make run NAME=prog   # runs ./build/prog"
	@echo "  make clean           # remove binaries"

# Pattern rule: compile any .cpp file to executable
%: %.cpp
	mkdir -p build
	$(CXX) $(CXXFLAGS) $< -o build/$@

# Run binary (requires NAME=...)
.PHONY: run
run:
	@if [ -z "$(NAME)" ]; then \
		echo "Error: missing NAME. Usage: make run NAME=program"; \
		exit 1; \
	fi
	./build/$(NAME)

# Clean up executables (optional)
.PHONY: clean
clean:
	rm -f $(shell find . -maxdepth 2 -type f -executable ! -name ".*" ! -name "Makefile")

# List available source files (optional)
.PHONY: list
list:
	@echo "Available C++ source files:"
	@ls -1 *.cpp 2>/dev/null || echo "No .cpp files found"

