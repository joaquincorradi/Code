LDUR X4, [X6, #32]      // X4 = MEM[X6 + 32]
ADD X0, X1, X4          // X0 = X1 + X4
SUB X0, XZR, X0         // X0 = 0 - X0