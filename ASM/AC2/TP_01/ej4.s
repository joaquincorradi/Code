ADDI X9, X6, #8           // X9 = &A[1] ya que se suma 8 bytes a X6 y un elemento de A ocupa 8 bytes = 0x108
ADD X10, X6, XZR          // X10 = &A[0] = 0x100
STUR X10, [X9, #0]        // M[A[1]] = &A[0] = 0x100
LDUR X9, [X9, #0]         // X9 = A[1] = &A[0] 
ADD X0, X9, X10           // f = &A[0] + &A[0] = 2 * &A[0] = 2 * 0x100 = 0x200