    .data
n:      .word 10
fib:    .space 1000

    .text
    .globl _start

_start:
    la t0, n
    lw t1, 0(t0)
    la t2, fib

    li t3, 0
    sw t3, 0(t2)
    addi t2, t2, 4

    li t3, 1
    sw t3, 0(t2)
    addi t2, t2, 4

    li t4, 2

fib_loop:
    bge t4, t1, end
    lw t5, -4(t2)
    lw t6, -8(t2)
    add t5, t5, t6
    sw t5, 0(t2)
    addi t2, t2, 4
    addi t4, t4, 1
    j fib_loop

end:
    # Exit for Spike (RV64)
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

1:  j 1b

    .section .tohost
    .align 3
tohost:   .dword 0
fromhost: .dword 0
