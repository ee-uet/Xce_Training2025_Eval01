.globl _start
.section .text

_start:
    la x1,integer  # address of integer
    la x7,array   # address of array
    lb x2, 0(x1)   # load integer in x2
    li x3,0 # output
    li x4,1 
    li x5,0 # counter 
    li x6,0 
loop:
   # done with the swapping
    beq x5,x2,done
    sb x3, 0(x7)  # storing each fibonacci value (x3 = fibanacci value)
    addi x7,x7,1
    add x6,x3,x4
    mv x3,x4   
    mv x4,x6
    addi x5,x5,1
    j loop
done:
    
    # Exit Spike
    li   t0, 1
    la   t1, tohost
    sd   t0, 0(t1)
    nop
.section .data
integer:   .byte 5
array: .space  5

.section .tohost
.align 3
tohost:   .dword 0
fromhost: .dword 0