.data

n:      .word 10             
fib:    .space 40 

.global _start

.section .text
_start:
    # Any code here
    la t0, n                   
    lw t1, 0(t0)                
    la t2, fib                  
    li t3, 0                    
    li t4, 0                    
    li t5, 1                    

loop:
    beq t3, t1, end             
    beqz t3, store_zero         
    li t6, 1
    beq t3, t6, store_one       
    add t6, t4, t5              
    sw t6, 0(t2)                
    mv t4, t5                   
    mv t5, t6                              
    j loop

store_zero:
    sw t4, 0(t2)              
    addi t2, t2, 4
    addi t3, t3, 1
    j loop
store_one:
    sw t5, 0(t2)              
    addi t2, t2, 4
    addi t3, t3, 1
    j loop

end:
    li a7, 10
 
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
