.global _start

.section .data
n: .word 7
array: .space 1024  #1KB space

.section .text

_start:
    la t0,array     # starting address of array
    li t1,0         # t1 = 0
    sw t1,0(t0)     # fib seq starts with 0
    addi t1,t1,1
    mv t2,t0        # copy starting address to t2
    addi t2,t2,4    
    sw t1,0(t2)     # fib seq second entry is 1.
    la t3,n         # address of n
    lw t3,0(t3)     # t3 = n
    li t4,3         # counter for loop starts from 3 because fist two entries of fib seq have already been stored        

loop:
    bgt t4,t3,exit

    mv t5,t4
    addi t6,t5,-1
    addi a0,t5,-2   
    slli t6,t6,2    # address are multiple of 4
    slli a0,a0,2
    add t6,t6,t0    
    add a0,a0,t0    # addresses of last 2 elements are calculated

    lw a1,0(t6)     # last element  
    lw a2,0(a0)     # 2nd last element

    add a3,a1,a2    # value of current element
    addi a4,t6,4    # address of current element

    sw a3,0(a4)     # storing current element in array

    addi t4,t4,1
    j loop



exit:
    # Code to exit for Spike (DONT REMOVE IT)
    li t0, 1
    la t1, tohost
    sd t0, (t1)

# Loop forever if spike does not exit
1: j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0

