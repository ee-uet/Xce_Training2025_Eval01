.global _start
    .section .text
_start:
      lw x1 , n  #num
      li x2 , 0  #a
      li x3 , 1  #b
      la x4 , arr #array

      sw x2 , 0(x4) #store a
      addi x4 , x4 ,4 
      addi x1 , x1 ,-1 #i
      beqz x1, done 

      sw x3 , 0(x4)  #store b
      addi x4 , x4 ,4 
      addi x1 , x1 ,-1 

loop:
     add x5, x2, x3 
     sw x5, 0(x4)
     mv x2 , x3 
     mv x3 , x5 
     addi x4 , x4 , 4
     addi x1 , x1 , -1
     bnez x1, loop
done:
    li x1, 1
    la x2, tohost
    sd x1, 0(x2)
1:  j 1b                     

.section .data
.align 3
n : .word 5
arr : .space 40             

.section .tohost
.align 3
tohost:   .dword 0
fromhost: .dword 0