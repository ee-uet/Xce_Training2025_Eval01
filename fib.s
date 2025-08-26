.data
n:      .word 10
results: .space 40

.text
.global _start

_start:
    la      a0, n
    lw      a1, 0(a0)
    li      t0, 1
    blt     a1, t0, handle_small_n
    la      a0, results
    li      a2, 0
    li      a3, 1
    sw      a2, 0(a0)
    li      t0, 2
    blt     a1, t0, fib_loop_end
    sw      a3, 4(a0)
    li      t1, 2

fib_loop:
    bge     t1, a1, fib_loop_end
    add     t0, a2, a3
    slli    t2, t1, 2
    add     t2, a0, t2
    sw      t0, 0(t2)
    mv      a2, a3
    mv      a3, t0
    addi    t1, t1, 1
    j       fib_loop

handle_small_n:
    j       fib_loop_end

fib_loop_end:
    li      a0, 10
    li      a1, 0
    ecall
