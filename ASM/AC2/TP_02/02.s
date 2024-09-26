// a. 30 + 10 + 9 + 40 + 20 = 109ns (sin pipeline)
// b. La velocidad esta definida por 1/T. T = 40ns -> 1/T = 25MHz
// c. 40ns * 5 etapas = 200ns (con pipeline). Se ejecuta una nueva instrucción cada 40ns.
// d. ganancia = (109 * 3) / (200 + (40 * 2)) = 327 / 280 = 1.1678571428571428
