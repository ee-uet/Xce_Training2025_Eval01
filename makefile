EXE = Task1.1

SRC = Task1.1.c

build:
	gcc -o $(EXE) $(SRC)

test: build
	./Task1.2.sh
clean:
	rm -f $(EXE)

