//a. nro instuccion   operando    hazard?
//   1 - 2            X10         Si
//   1 - 3            X10         Si

//    1   2   3   4   5   6   7
//1   IF  ID  EX  MEM WB
//2       IF  ID  EX  MEM WB
//3           IF  ID  EX  MEM WB

// Es necesario hacer forwarding para que la instruccion 3 pueda ejecutarse correctamente
// Para eso se necesita hacer forwarding de la instruccion 1 a la 3 desde la etapa MEM a la etapa EX