SUBIS XZR, X9, #0                 // Compara a X9 con 0
B.GE else                         // Si X9 >= 0, salta a else
B done                            // Si X9 < 0, salta a done
else: ORRI X10, XZR, #2           // X10 = 0 OR 2 = 2
done: