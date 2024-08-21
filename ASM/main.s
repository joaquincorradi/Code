.data
  size: .word 8
  array: .word 1, 2, -3, 4, -5, 6, 7, 0

.text
  .globl main
  main:
    LDR R0, =size @ Cargar la dirección de memoria de size en R0
    LDR R1, [R0] @ Cargar el valor de size en R1
    LDR R2, =array @ Cargar la dirección de memoria de array en R2

  loop:
    CMP R1, #0 @ Comparar R1 con 0 para saber si se llegó al final del array