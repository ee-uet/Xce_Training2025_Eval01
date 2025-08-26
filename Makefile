CC=gcc
CFLAGS=-Wall -O2
TARGET=bittops
build: $(TARGET)
$(TARGET): bittops.c
	$(CC) $(CFLAGS) -o $(TARGET) bittops.c
test: build
	./run_tests.sh
clean:
	rm -f $(TARGET)

