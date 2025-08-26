    .section .text
    .global _start
_start:
    # Load n
    la t0, n
    lw t1, 0(t0)          # t1 = n

    # Base Fibonacci numbers
    li t2, 0              # fib0
    li t3, 1              # fib1

    # Pointer to array
    la t4, fib_array

    # Store first two numbers
    sw t2, 0(t4)
    addi t4, t4, 4
    sw t3, 0(t4)
    addi t4, t4, 4

    li t5, 2              # i = 2

fib_loop:
    bge t5, t1, done      # if i >= n, exit

    # Compute next Fibonacci number
    add t6, t2, t3        # fib[i] = fib[i-2] + fib[i-1]

    # Store it
    sw t6, 0(t4)
    addi t4, t4, 4        # move pointer

    # Update previous two numbers
    mv t2, t3
    mv t3, t6

    addi t5, t5, 1
    j fib_loop

done:
    # Signal completion to Spike
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

1:  j 1b                  # infinite loop

    .section .data
n:          .word 10
fib_array:  .space 40       # enough for 10 unsigned ints

    .section .tohost
    .align 3
tohost:     .dword 0
fromhost:   .dword 0

