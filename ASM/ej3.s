@R0 = G, R1 = H
@ if(R0>=R1)
@     R0 = R0 + R1;
@ else
@     R0 = R0 - R1;
.text
  .global main
  main:
    CMP R2, R0, R1 @Encender bandera si R0 >= R1
    ADDGE R0, R0, R1 @Si la bandera esta encendida, sumar R0 y R1
    SUBLT R0, R0, R1 @Si la bandera esta apagada, restar R0 y R1
