    .data
    num: .word 7
    array: .word 0, 0, 0, 0, 0, 0, 0
    .global _start
 
.section .text
_start:
    la s1, length
    lw s0, 0(s1)            # load total count

    

    la t3, buffer           # base address of array

    li t0, 0                # prev value
    li t1, 1                # curr value

    li t2, 2                # index tracker

    lw s2, 0(t3)
    add s3, s2, t0          # first element = 0
    sw s3, 0(t3)

    addi t3, t3, 4          # move to next slot

    lw s2, 0(t3)
    add s3, s2, t1          # second element = 1
    sw s3, 0(t3)


loop_gen:

    addi s4, t1, 0          # backup current value
    add t1, t1, t0          # compute next fib number

    addi t3, t3, 4          # advance array pointer

    lw s2, 0(t3)            # load slot
    add s3, s2, t1          # store next fib number
    sw s3, 0(t3)
    
    mv t0, s4               # shift window

    addi t2, t2, 1          # increment counter
    blt t2, s0, loop_gen    # loop until full length



    

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
