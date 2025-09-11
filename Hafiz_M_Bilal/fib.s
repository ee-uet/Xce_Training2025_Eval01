
.data
number: .word 7
array: .word 0, 0, 0, 0, 0, 0, 0
.global _start
 
.section .text
_start:
    #--------------######################---------------------
    #--------------------This is code region------------------
    
    la t0, number
    lw a0, 0(t0) #size

    la a5, array     # address of array 

    li a1, 0     #first number
    li a2, 1     #second number

    li a4, 2     #counter

    lw t1, 0(a5)
    add t2, t1, a1          # Store first number 0
    sw t2, 0(a5)

    addi a5, a5, 4          # point to next address


    lw t1, 0(a5)
    add t2, t1, a2          # Store Second number 1
    sw t2, 0(a5)


loop:

    

    addi a3, a2, 0
    add a2, a2, a1          # Compute next number

    addi a5, a5, 4          # point to next address

    lw t1, 0(a5)            # Load address where result store
    add t2, t1, a2          # Store result in memory
    sw t2, 0(a5)
    
    mv a1, a3

    addi a4, a4, 1          # increment in counter
    blt a4, a0, loop        # Check if counter < Size


    

    #-------------#######################----------------------
    # Code to exit for Spike (DONT REMOVE IT)
    li t0, 1
    la t1, tohost
    sd t0, (t1)
 
    # Loop forever if spike does not exit
1:  j 1b
 
.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0

