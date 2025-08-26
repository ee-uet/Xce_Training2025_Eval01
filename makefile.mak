CC = gcc
CFLAGS = -Wall
SRC = bitops.c
EXE = bitops
.PHONY: all build test clean
all: build

build: $(SRC)
	$(CC) (CFLAGS) -o $(EXE) $(SRC)
	@echo "Build Complete $(EXE)"

test: build
     @echo "Running tests"
	 ./run_tests.sh
	 
clean:
	rm -f $(EXE)
	rm -f *.o
	@echo "Clean Complete"
