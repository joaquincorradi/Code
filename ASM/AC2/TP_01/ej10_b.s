ADDI X10, XZR, #50            // i = 50
loop: LDUR X1, [X0,#0]        // a = MemArray[o]
ADD X2, X2, X1                // result = result + a
LDUR X1, [X0,#8]              // a = MemArray[1]
ADD X2, X2, X1                // result = result + a = MemArray[0] + MemArray[1]
ADDI X0, X0, #16              // X0 = &MemArray[2]
SUBI X10, X10, #1             // i--
CBNZ X10, loop                // 