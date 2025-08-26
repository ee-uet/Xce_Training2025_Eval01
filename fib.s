.global _start
    .section .text
_start:
      lw t1 , n  # t1 = number of Fibonacci numbers
      li t2 , 0  # t2 = fib0
      li t3 , 1  # t3 = fib1
      la t4 , arr # t4 points to start of arr

      sw t2 , 0(t4) # arr[0] = 0
      addi t4 , t4 ,4 # move pointer to next element
      addi t1 , t1 ,-1 # decrement counter
      beqz t1, done # if n == 1 done

      sw t3 , 0(t4)  # arr[1] = 1
      addi t4 , t4 ,4 # move pointer to next element
      addi t1 , t1 ,-1 # decrement counter

loop:
     add t5, t2, t3 # t5 = t2 + t3
     sw t5, 0(t4) # store t5 in arr
     mv t2 , t3  # t2 = previous Fibonacci
     mv t3 , t5  # t3 = current Fibonacci
     addi t4 , t4 , 4 # move pointer to next array element
     addi t1 , t1 , -1 # decrement counter
     bnez t1, loop # repeat loop if t1 != 0
done:
    li t1, 1
    la t2, tohost
    sd t1, 0(t2)
1:  j 1b                     

.section .data
.align 3
n : .word 5
arr : .space 40             

.section .tohost
.align 3
tohost:   .dword 0
fromhost: .dword 0