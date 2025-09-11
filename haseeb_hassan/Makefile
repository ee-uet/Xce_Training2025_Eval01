
CC = gcc
CFLAGS = -Wall -O2

TARGET = bitops


build: $(TARGET)


$(TARGET): bitops.c
	$(CC) $(CFLAGS) -o $(TARGET) bitops.c

test: build
	bash ./run_tests.sh

clean:
	rm -f $(TARGET)
