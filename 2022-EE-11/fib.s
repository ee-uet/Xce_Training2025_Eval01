.data 
array: .word 0, 0, 0, 0, 0
size: .word 5

.section .text

_start:
    la t0, array      # Base address of array
    lw t1, size       # Load actual size value (5)
    li t2, 0          # Current index
    li t3, 0          # First Fibonacci number (F0)
    li t4, 1          # Second Fibonacci number (F1)
    
    jal fib           
    
    # Code to exit for Spike (DONT REMOVE IT)
    li t0, 1
    la t1, tohost
    sd t0, (t1)

fib:
    # Check if we've generated all n numbers
    bge t2, t1, done
    
    # Handle first two cases specially
    beq t2, x0, store_first   # if index == 0
    li t5, 1
    beq t2, t5, store_second  # if index == 1
    
    # For index >= 2, calculate next Fibonacci number
    add t5, t3, t4    # t5 = F(n-2) + F(n-1)
    mv t3, t4         # F(n-2) = F(n-1)  
    mv t4, t5         # F(n-1) = F(n)
    
    # Store the calculated value
    slli t6, t2, 2    # Convert index to byte offset (index * 4)
    add t6, t0, t6    # Add to base address
    sw t5, 0(t6)      # Store Fibonacci number
    
    addi t2, t2, 1    # Increment index
    jal fib           # Recursive call
    
store_first:
    sw t3, 0(t0)      # Store F(0) = 0
    addi t2, t2, 1    # Increment index
    jal fib
    
store_second:
    sw t4, 4(t0)      # Store F(1) = 1
    addi t2, t2, 1    # Increment index  
    jal fib

done:
    ret

# Loop forever if spike does not exit
1: j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0