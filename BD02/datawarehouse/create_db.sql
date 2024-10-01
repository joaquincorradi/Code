# SOURCE ~/Code/BD02/datawarehouse/create_db.sql

DROP DATABASE precios_claros;
CREATE DATABASE precios_claros;
USE precios_claros;

CREATE TABLE comercio (
    id_comercio INT,
    id_bandera INT,
    comercio_cuit BIGINT,
    comercio_razon_social VARCHAR(15),
    comercio_bandera_nombre VARCHAR(10),
    comercio_bandera_url VARCHAR(40),
    comercio_ultima_actualizacion TIMESTAMP,
    comercio_version_sepa DECIMAL(2,1),
    PRIMARY KEY (id_comercio, id_bandera)
);

CREATE TABLE sucursal(
    id_sucursal INT,
    id_comercio INT,
    id_bandera INT,
    sucursales_nombre VARCHAR(200),
    sucursales_tipo VARCHAR(50),
    sucursales_calle VARCHAR(200),
    sucursales_numero INT,
    sucursales_latitud DECIMAL(7,5),
    sucursales_longitud DECIMAL(7,5),
    sucursales_observaciones VARCHAR(100),
    sucursales_barrio VARCHAR(100),
    sucursales_codigo_postal INT,
    sucursales_localidad VARCHAR(200),
    sucursales_provincia VARCHAR(100),
    sucursales_lunes_horario_atencion VARCHAR(100),
    sucursales_martes_horario_atencion VARCHAR(100),
    sucursales_miercoles_horario_atencion VARCHAR(100),
    sucursales_jueves_horario_atencion VARCHAR(100),
    sucursales_viernes_horario_atencion VARCHAR(100),
    sucursales_sabado_horario_atencion VARCHAR(100),
    sucursales_domingo_horario_atencion VARCHAR(100),
    PRIMARY KEY (id_sucursal),
    FOREIGN KEY (id_comercio, id_bandera) REFERENCES comercio(id_comercio, id_bandera)
);

CREATE TABLE producto (
    id_producto BIGINT,
    id_sucursal INT,
    productos_ean INT,
    productos_descripcion VARCHAR(300),
    productos_cantidad_presentacion DECIMAL(4,3),
    productos_unidad_medida_presentacion VARCHAR(10),
    productos_marca VARCHAR(30),
    productos_precio_lista DECIMAL(10,2),
    productos_precio_referencia DECIMAL(10,2),
    productos_cantidad_referencia INT,
    productos_unidad_medida_referencia VARCHAR(10),
    productos_precio_unitario_promo1 DECIMAL(10,2),
    productos_leyenda_promo1 VARCHAR(100),
    productos_precio_unitario_promo2 DECIMAL(10,2),
    productos_leyenda_promo2 VARCHAR(100),
    PRIMARY KEY (id_producto, id_sucursal),
    FOREIGN KEY (id_sucursal) REFERENCES sucursal(id_sucursal)
);