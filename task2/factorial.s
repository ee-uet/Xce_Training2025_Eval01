.data
word: .word 3

.text
.global _start
_start:
  lw t0, word
  li t1,1
  li t2,0
  li t3,1
loop:
  bgt t0,t1, Fibonacci
  j end

Fibonacci:
  add t2, t2,t3
  addi t3,t2,0
  sub t0, t0,t1
  j loop

end:
  la t3, tohost
  sd t1,0(t3)

.section .tohost
.align 3
tohost: .dword 0
fromhost: .dword 0