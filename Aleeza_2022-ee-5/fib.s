    .section .text
    .global _start
_start:
    # Load n
    la t0, n
    lw t1, 0(t0)        

    li t2, 0         
    li t3, 1           
    la t4, fib_array
    sw t2, 0(t4)
    addi t4, t4, 4
    sw t3, 0(t4)
    addi t4, t4, 4

    li t5, 2       

fib_loop:
    bge t5, t1, done   
    add t6, t2, t3      

    # Store it
    sw t6, 0(t4)
    addi t4, t4, 4     

    mv t2, t3
    mv t3, t6

    addi t5, t5, 1
    j fib_loop

done:
    li t0, 1
    la t1, tohost
    sd t0, 0(t1)

1:  j 1b             

    .section .data
n:          .word 10
fib_array:  .space 40      

    .section .tohost
    .align 3
tohost:     .dword 0
fromhost:   .dword 0

