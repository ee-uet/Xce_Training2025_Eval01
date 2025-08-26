CC = gcc
CFLAGS = -Wall
TRGT = 2022ee169_bitop
TEST_TRGT = 2022ee169_run_tests

# Compiler and emulator
AS = riscv64-unknown-elf-as
LD = riscv64-unknown-elf-ld
SPIKE = spike
PROG = fib

build: $(TRGT)

$(TRGT): $(TRGT).o
	@echo "building executable..."
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	@echo "compiling file $< ..."
	$(CC) $(CFLAGS) -c $< -o $@
test: $(TRGT)
	./$(TEST_TRGT).sh

# Rule to assemble and link
all: $(PROG)

$(PROG): $(PROG).s
	@echo "Compiling ...."
	$(AS) -o $(PROG).o $<
	@echo "Linking ...."
	$(LD) -T link.ld -o $@ $(PROG).o
 
# Rule to run with Spike
run: $(PROG)
	$(SPIKE) $(PROG)
 
# Rule to debug with Spike
debug: $(PROG)
	$(SPIKE) -d --log-commits $(PROG) > fib.log


clean:
	rm -f $(TRGT) $(TRGT).o $(PROG).o $(PROG)