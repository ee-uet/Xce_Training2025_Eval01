# General Makefile for single C file
CC = gcc
CFLAGS = -Wall -Wextra -O2

# If you run "make", it will compile 'a.c' by default
SRC ?= struct_e.c
OUT ?= struct_e

all: $(OUT)

$(OUT): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(OUT)

build: $(OUT)
	@./$(OUT)

clean:
	@rm -f $(OUT)
