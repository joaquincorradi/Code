main:
  MOVZ X9, #1024, LSL #0 // N = 1 << 0
  MOV X1, XZR // S = 0
  ADD X2, XZR, XZR // i = 0

loop_2:
  CMP X9, X2
  BEQ loop_out_2
  SUB X3, XZR, XZR // j = 0

loop_1:
  SUB X10, X3, X9
  CBZ X10, loop_out_1
  MUL X4, X2, X9 // i * N
  ADD X4, X4, X3 // i * N + j
  LSL X4, X4, #3 // (i * N + j) * 8
  ADD X4, X4, X0 // [(i * N + j) * 8] + A = &A[i][j]
  LDUR X11, [X4, #0] // X11 = A[i][j]
  ADD X1, X1, X11 // S += A[i][j]
  ADDI X3, X3, #1 // j++
  B loop_1

loop_out_1:
  ADDI X2, X2, #1 // i++
  B loop_2