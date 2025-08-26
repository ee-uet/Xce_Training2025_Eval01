CC=gcc
CFLAGS=-Wall 
TARGET=out
CFILE=bitops.c
build:
	$(CC) $(CFLAGS) -o $(TARGET) $(CFILE)

test: build
	chmod +x run_tests.sh
	./run_tests.sh

clean:
	rm -f $(TARGET)
