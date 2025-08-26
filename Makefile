CC = gcc
CFLAGS = -Wall 
TARGET = Aftab
TEST_SCRIPT = test_ispowerof2.sh

.PHONY: all build test clean

all: build

build: $(TARGET)

$(TARGET): Aftab.c
	$(CC) $(CFLAGS) -o $(TARGET) Aftab.c

test: build
	@chmod +x $(TEST_SCRIPT)
	bash ./$(TEST_SCRIPT)

clean:
	rm -f $(TARGET)
