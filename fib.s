.data
sequence_length: .word 7
fibonacci_array: .word 0, 0, 0, 0, 0, 0, 0

.global _start

.section .text
_start:
    la t0, sequence_length
    lw s0, 0(t0)
    la s1, fibonacci_array

    li t1, 0
    li t2, 1
    
    sw t1, 0(s1)
    sw t2, 4(s1)

    li t3, 2

fibonacci_loop:
    bge t3, s0, loop_exit

    add t4, t1, t2
    
    slli t5, t3, 2
    add t6, s1, t5
    sw t4, 0(t6)

    mv t1, t2
    mv t2, t4

    addi t3, t3, 1
    j fibonacci_loop

loop_exit:
    li t0, 1
    la t1, tohost
    sd t0, (t1)

end_loop:
    j end_loop

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0
