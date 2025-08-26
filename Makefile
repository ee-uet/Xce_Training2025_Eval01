CC = gcc
CFLAGS = -Wall -Wextra -O2
SRC = bitop.c
BIN = bitop.out
TEST_SCRIPT = run_test.sh

.PHONY: build test clean

build: $(SRC)
	@echo "Compiling $SRC..."
	$(CC) $(CFLAGS) -o $(BIN) $(SRC)
	@echo "Compilation successful"
	
test: build
	@echo "Running tests with $(TEST_SCRIPT)..."
	@chmod +x $(TEST_SCRIPT)
	./$(TEST_SCRIPT)

clean:
	@echo "Cleaning up build artifacts..."
	rm -f $(BIN)

