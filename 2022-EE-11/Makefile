# Makefile for bitops.c

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2
DEBUG_FLAGS = -g -DDEBUG

# Target executable name
TARGET = bitops

# Source files
SOURCES = bitops.c

# Object files (automatically generated from sources)
OBJECTS = $(SOURCES:.c=.o)

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Run tests
test: $(TARGET)
	@echo "Running tests..."
	./run_tests.sh

# Clean up generated files
clean:
	rm -f $(TARGET) $(OBJECTS) *.o *.exe core.*


# Help target
help:
	@echo "Available targets:"
	@echo "  all       - Build the executable (default)"
	@echo "  test      - Run tests using run_tests.sh"
	@echo "  clean     - Remove generated files"

# Declare phony targets (targets that don't create files)
.PHONY: all test clean