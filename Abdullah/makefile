CC = gcc
CFLAGS = -Wall

all: build

build: bitops.o
	$(CC) -o bitops bitops.o

bitops.o: bitops.c
	$(CC) $(CFLAGS) -c bitops.c

test: build
	./run_test.sh

clean:
	rm -f bitops bitops.o
