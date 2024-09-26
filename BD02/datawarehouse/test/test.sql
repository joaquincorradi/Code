SELECT sucursal.sucursales_nombre AS sucursal
FROM sucursal
JOIN producto ON sucursal.id_sucursal = producto.id_sucursal
WHERE producto.id_producto=26647 and producto.id_sucursal=121;

SELECT comercio.comercio_bandera_nombre AS nombre_comercio
FROM comercio
JOIN producto ON comercio.id_comercio = producto.id_comercio AND comercio.id_bandera = producto.id_bandera
WHERE producto.id_producto=26647 and producto.id_sucursal=121;