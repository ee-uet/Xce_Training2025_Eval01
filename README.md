# Bitwise Operations Utility

This repository contains a collection of bitwise operation functions implemented in C, accompanied by a bash test script and a Makefile to automate building and testing.

---

## Project Structure

- `bitops.c`  
  Implements various bitwise operations, including:
  - Counting set bits using Kernighan's algorithm
  - Reversing bits
  - Checking if a number is a power of two
  - Setting, clearing, and toggling specific bits
  - Extracting a range of bits

- `test_ispowerof2.sh`  
  Bash script to test the `ispowerof2` function in `bitops.c`.  
  It runs multiple test cases against the executable to verify correctness.

- `Makefile`  
  Provides commands to:
  - Build the executable (`make build`)
  - Run tests (`make test`)
  - Clean build artifacts (`make clean`)

---

## Requirements

- GCC compiler  
- Bash shell 
- Git 

---

## How to Use

### Build the project

Compile the program using:

```bash
make build
