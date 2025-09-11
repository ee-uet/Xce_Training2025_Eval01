CC = gcc
CFLAGS = -Wall 
TARGET = program
OBJS = evaluation.o

all: $(TARGET) 

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

evaluation.o: evaluation.c
	$(CC) $(CFLAGS) -c evaluation.c



clean:
	rm -f $(TARGET) $(OBJS)
