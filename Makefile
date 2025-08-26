CC = gcc
CFLAGS = -Wall
TRGT = 2022ee169_bitop
TEST_TRGT = 2022ee169_run_tests


build: $(TRGT)

$(TRGT): $(TRGT).o
	@echo "building executable..."
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	@echo "compiling file $< ..."
	$(CC) $(CFLAGS) -c $< -o $@
test: $(TRGT)
	./$(TEST_TRGT).sh


clean:
	rm -f $(TRGT) $(TRGT).o