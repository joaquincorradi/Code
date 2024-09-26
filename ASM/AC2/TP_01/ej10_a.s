ADD X10, XZR, XZR               // i = 0
loop: LDUR X1, [X0,#0]          // a = MemArray[0]
ADD X2, X2, X1                  // result = result + a
ADDI X0, X0, #8                 // X0 = &MemArray[1]
ADDI X10, X10, #1               // i = i + 1
CMPI X10, #100                  // Compara i con 100
B.LT loop                       // Si i < 100, salta a loop
// Este codigo realiza la suma de los primeros 100 elementos de un arreglo