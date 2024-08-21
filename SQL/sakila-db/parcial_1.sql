USE parcial01;

CREATE TABLE aeropuertos(
    id_aeropuerto INT PRIMARY KEY AUTO_INCREMENT,
    codigo VARCHAR(3),
    nombre VARCHAR(50),
    ciudad VARCHAR(50),
    pais VARCHAR(50)
);

CREATE TABLE pilotos(
    id_piloto INT PRIMARY KEY AUTO_INCREMENT,
    nombre VARCHAR(50),
    apellido VARCHAR(50),
    fecha_nacimiento DATE,
    sexo CHAR(1),
    nacionalidad VARCHAR(50)
);

CREATE TABLE vuelos(
    id_vuelo INT PRIMARY KEY AUTO_INCREMENT,
    id_aeropuerto_origen INT,
    id_aeropuerto_destino INT,
    id_piloto INT,
    fecha DATE,
    aerolinea VARCHAR(50),
    distancia_recorrida DECIMAL(10,2),
    FOREIGN KEY (id_piloto) REFERENCES pilotos(id_piloto),
    FOREIGN KEY (id_aeropuerto_origen) REFERENCES aeropuertos(id_aeropuerto),
    FOREIGN KEY (id_aeropuerto_destino) REFERENCES aeropuertos(id_aeropuerto)
);

CREATE TABLE pasajeros(
    id_pasajero INT PRIMARY KEY AUTO_INCREMENT,
    nombre VARCHAR(50),
    apellido VARCHAR(50),
    fecha_nacimiento DATE,
    sexo CHAR(1),
    nacionalidad VARCHAR(50)
);

CREATE TABLE boletos(
    id_boleto INT PRIMARY KEY AUTO_INCREMENT,
    id_pasajero INT,
    id_vuelo INT,
    clase VARCHAR(50),
    fecha_compra DATE,
    monto_abonado DECIMAL(10,2),
    FOREIGN KEY (id_pasajero) REFERENCES pasajeros(id_pasajero),
    FOREIGN KEY (id_vuelo) REFERENCES vuelos(id_vuelo)
);

-- Ejercicio 1:
-- Listar los aeropuertos que no han sido utilizados como aeropuerto de origen en ningun vuelo de la aerolinea LATAM
SELECT nombre,
       codigo
FROM aeropuertos
WHERE id_aeropuerto NOT IN (
    SELECT id_aeropuerto_origen
    FROM vuelos
    WHERE aerolinea = 'LATAM');

-- Ejercicio 2
-- Listar las rutas de la aerolinea BETA (mostrar origen y destino) cuya distancia recorrida es superior al promedio de la distancia recorrida por todas las rutas de al menos una aerolinea
SELECT a1.nombre AS origen,
       a2.nombre AS destino
FROM vuelos
INNER JOIN aeropuertos AS a1 ON vuelos.id_aeropuerto_origen = a1.id_aeropuerto
INNER JOIN aeropuertos AS a2 ON vuelos.id_aeropuerto_destino = a2.id_aeropuerto
WHERE aerolinea = 'BETA' AND
      distancia_recorrida > (
        SELECT AVG(distancia_recorrida)
        FROM vuelos);

-- Ejercicio 3
-- Listar los pilotos de nacionalidad 'argentina' que hasta la hoy nunca volaron hacia aeropuertos en Suiza o Rusia
SELECT pilotos.nombre,
       pilotos.apellido
FROM pilotos
INNER JOIN vuelos ON pilotos.id_piloto = vuelos.id_piloto
INNER JOIN aeropuertos ON vuelos.id_aeropuerto_destino = aeropuertos.id_aeropuerto
WHERE pilotos.nacionalidad = 'argentina' AND
      aeropuertos.pais NOT IN ('Suiza', 'Rusia');


-- Ejercico 04
-- ¿Cuantos boletos se han vendido de cada aerolinea en 2023 excepto LATAM? Ordenar por cantidad de boletos vendidos descendente y excluir aerolineas con menos de 7 vuelos
SELECT vuelos.aerolinea,
       COUNT(*) AS cantidad_boletos
FROM boletos
INNER JOIN vuelos ON boletos.id_vuelo = vuelos.id_vuelo
WHERE YEAR(fecha_compra) = 2023 AND
      aerolinea != 'LATAM'
GROUP BY aerolinea
HAVING COUNT(*) >= 7
ORDER BY cantidad_boletos DESC;