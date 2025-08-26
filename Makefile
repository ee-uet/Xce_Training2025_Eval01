CC = gcc
CFLAGS = -Wall -Wextra -O2

SRC ?= bitops1.c
OUT ?= bitops1

all: build

$(OUT): $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o $(OUT)

build: $(OUT)

test: $(OUT) run_tests.sh
	@chmod +x run_tests.sh
	@./run_tests.sh

clean:
	@rm -f $(OUT)
