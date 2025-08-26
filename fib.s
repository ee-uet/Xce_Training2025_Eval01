.data 
array: .word 0, 0, 0, 0, 0
size: .word 5

.section .text

_start:

	la t0, array
    	li t1, size
    	
    	li t2, 1 # n-1
    	li t3, 1 # n-2
    	li t4, 0 # Element
    	li t5, 0 # Count
    	
    	jal fib           
    	
    	# Code to exit for Spike (DONT REMOVE IT)
	li t0, 1
	la t1, tohost
	sd t0, (t1)
    	
fib:	
	bge t1, 2, first_two
	
	beq t5, 2, done
	
first_two:
	sw t2, t1(t0)
	addi t5, 1
	sw t3, t1(t0)
	addi t5, 1
	jal fib
	

done:
	ret


# Loop forever if spike does not exit
1: j 1b

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0





