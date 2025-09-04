.global _start

.section .data
n:                  .word 10
fib_array:          .space 40

.section .text
_start:

    la t1, n
    lw t0, 0(t1)          

    la t2, fib_array      
    li t3, 0
    sw t3, 0(t2)          

    li t3, 1
    sw t3, 4(t2)        

    li t4, 2             

fib_loop:
    bge t4, t0, fib_done  

    slli t5, t4, 2        
    add t6, t2, t5       

    addi a1, t5, -4
    add a2, t2, a1
    lw a3, 0(a2)          

    addi a1, t5, -8
    add a2, t2, a1
    lw a4, 0(a2)          # fib[i-2]

    add a5, a3, a4
    sw a5, 0(t6)          # fib[i] = fib[i-1] + fib[i-2]

    addi t4, t4, 1
    j fib_loop

fib_done:
    # Spike exit code (do not remove)
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

1:
    j 1b

.section .tohost
.align 3
tohost:   .dword 0
fromhost: .dword 0
