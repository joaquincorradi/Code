@Multiplicar un numero por 35 en dos ciclos de reloj sin MUL
.text
  .global main
  main:
    MOV R0, #10 @R0 = 10
    ADD R1, R0, R0, LSL #5 @R1 = R0 + R0 * 2^5 = 10 + (10 * 32) = 330 -> R1 = 330
    ADD R0, R1, R0, LSL #1 @R0 = R1 + R0 * 2 = 330 + (10 * 2) = 350 -> R0 = 350
    