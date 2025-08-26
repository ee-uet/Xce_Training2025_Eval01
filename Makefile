# Variables
CC = gcc
CFLAGS = -Wall -Werror
TARGET = bitops
SRC = bitops.c
TEST_SCRIPT = run_tests.sh

# Default target
all: build

# Compile the C program
build:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Run Bash tests
test: build
	chmod +x $(TEST_SCRIPT)
	./$(TEST_SCRIPT)

# Clean build artifacts
clean:
	rm -f $(TARGET)

