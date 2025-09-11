#Create a Makefile with targets:
#make build → Compile the C program.
#make test → Run Bash tests.
#make clean → Remove build artifacts.

CC = gcc
CFLAGS = -Wall  -g
TARGET = bitops
SRC = bitops.c	
TEST_SCRIPT = run_Tests.sh
OBJ = $(SRC:.c=.o) # automatically replace ho gaya ha .c files k nam into .o files 
.PHONY: all build test clean 
all: build test
build: $(TARGET)
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
test: $(TARGET)
	bash $(TEST_SCRIPT)
clean:
	rm -f $(OBJ) $(TARGET)