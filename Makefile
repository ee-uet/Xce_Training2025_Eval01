CC = gcc
CFLAGS = -Wall -std=c99

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: program

program: $(OBJS)
	$(CC) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) program

.PHONY: all clean