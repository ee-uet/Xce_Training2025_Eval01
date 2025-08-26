.global _start

.section .data
n:      .word 5            # number of Fibonacci numbers
.align 3                   #  8-byte alignment for 64-bit stores
fib:    .space 40          # space for 5 Fibonacci numbers (5*8 bytes)

.section .text
_start:
    lw t0, n               # Load n
    li t1, 0               # F0
    li t2, 1               # F1
    la t3, fib             # pointer to fib array

    sd t1, 0(t3)           # store F0
    addi t3, t3, 8         # move pointer
    sd t2, 0(t3)           # store F1
    addi t3, t3, 8         # move pointer
    li t4, 2               # counter = 2 (already have 2 numbers)

fib_loop:
    bge t4, t0, done       # if counter >= n, done
    add t5, t1, t2         # next = F0 + F1
    sd t5, 0(t3)           # store next
    mv t1, t2              # F0 = F1
    mv t2, t5              # F1 = next
    addi t3, t3, 8         # move pointer
    addi t4, t4, 1         # increment counter
    j fib_loop

done:
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

halt:
    j halt

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
