.text
  .global main
  main:
    MOV R0, #TABLA
    MOV R3,               #-1
    MOV R1, #0            @OFFSET
    MOV R2, #250

    LDR R4, [R0, R1]     @Carga el primer valor de la tabla

    CMP R4, #42           @Compara si es igual a 42
    BEQ encontrado        @Si es igual a 42
    ADD R1, R1, #1        @Incrementa el offset
    CMP R1, R2            @Compara si el offset es igual a 250
    BNE main              @Si no es igual a 250 vuelve a cargar el valor de la tabla
    B done                @Si es igual a 250 termina el programa

  encontrado:
    ADD R3, R0, R1
    
  done: