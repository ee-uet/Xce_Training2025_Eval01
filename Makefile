# General Makefile for single C file
CC = gcc
CFLAGS = -Wall -Wextra -O2

# If you run "make", it will compile 'a.c' by default
SRC ?= bitops.c
OUT ?= bitops

all: $(OUT)

$(OUT): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(OUT)

build: $(OUT)
	@./$(OUT)

test:run_test.sh
	@chmod +x run_test.sh
	@./run_test.sh

clean:
	@rm -f $(OUT) 
