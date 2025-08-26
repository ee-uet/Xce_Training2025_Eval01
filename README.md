# Evaluation 1

This project has two parts:

1. **Bit manipulation utilities in C** (`bitops.c`) with an automated test harness.  
2. ** (`fib.s`) that generates Fibonacci numbers and runs on Spike with logging.  

---

## Bit Manipulation in C

### Implemented Operations
- **Count Set Bits** → clear lowest set bit trick (`num & (num-1)`).
- **Reverse Bits (32-bit)** → check each bit, place it in mirrored position.
- **Check Power of Two** → `num && !(num & (num-1))`.
- **Set / Clear / Toggle Bit at position `k`** → standard bitmasking (`|`, `&~`, `^`).
- **Extract Range of Bits** → demo mask-and-shift logic.
-

---

### Build & Run (Part 1)
- **Makefile** automates:
  - 'make build' → compiles `bitops.c` into `bitops`.
  - `make test` → runs the test harness (`run_test.sh`).  
  - `make clean` → removes build files.
### Build & Run (Part 2)
- **Use Spike** :
  - 'riscv64-unknown-elf-as -o fib.o fib.s'
  - 'riscv64-unknown-elf-ld -T link.ld -o fib fib.o'
  - 'spike --log-commits fib > fib.log 2>&1'
-
