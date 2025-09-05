.global _start
 
.section .text
_start:
    
    la a1, array_size #a1 = address if array_size
    lw a1, 0(a1) #a1 = value of array_size
    jal ra,cal_fib

    # Signal test pass to Spike
    li t0, 1
    la t1, tohost
    sd t0, (t1)
 
    # Loop forever
1:  j 1b

cal_fib:
    la t0, array # address of array 1st element
    addi a0, t0, 0 # ptr --> 1st element
    
    addi a1, t0, 4 #ptr --> 2nd element
    li t1, 2 # start from 3rd element 
    la t2, store_array
    li t6, 1
    sw t6, 0(t2)
    addi t2, t2, 4
    sw t6, 0(t2)
    addi t2, t2, 4 # ptr to store result (3rd element)
    
while:
    beq t1, a1, return
    li t5, 0; # initialize t5 = 0 on every iteration
    lw t3, 0(a0) #value of next to prev element in array
    lw t4, 0(a1) # value of prev element in array
    add t5, t3, t4 # sum of two values
    sw t5, 0(t2)
    addi a0, a0, 4 #jump to address of next element
    addi t0, t0, 4
    addi t2, t2, 4
    addi t1, t1, 1
    j while

    

return:
    ret



.section .data
zero: .word 0
array: .word 1,2,3,4,5
array_size: .word 5
store_array: .word 0,0,0,0,0

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0

 
