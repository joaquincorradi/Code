DELIMITER //

CREATE FUNCTION registrar_operacion(
  p_id INT, 
  p_apellido VARCHAR(256), 
  p_nombre VARCHAR(256), 
  p_saldo DECIMAL(11,2), 
  p_mail VARCHAR(256), 
  p_operacion CHAR(1)
  )
RETURNS NULL
DETERMINISTIC

BEGIN

  INSERT INTO log_datos (id, apellido, nombre, saldo, mail, operacion)
  VALUES (p_id, p_apellido, p_nombre, p_saldo, p_mail, p_operacion);

  RETURN NULL;

END //

--

CREATE FUNCTION obtener_apellido(p_id INT)
RETURNS VARCHAR(256)
DETERMINISTIC

BEGIN
  DECLARE v_apellido VARCHAR(256);

  SELECT apellido
  INTO v_apellido
  FROM Datos
  WHERE id = p_id;

  RETURN v_apellido

END //

--

CREATE FUNCTION obtener_nombre(p_id INT)
RETURNS VARCHAR(256)
DETERMINISTIC

BEGIN
  DECLARE v_nombre VARCHAR(256);

  SELECT nombre
  INTO v_nombre
  FROM Datos
  WHERE id = p_id;

  RETURN v_nombre

END //

--

CREATE FUNCTION obtener_saldo(p_id INT)
RETURNS DECIMAL(11,2)
DETERMINISTIC

BEGIN
  DECLARE v_saldo VARCHAR(256);

  SELECT saldo
  INTO v_saldo
  FROM Datos
  WHERE id = p_id;

  RETURN v_saldo

END //

--

CREATE FUNCTION obtener_email(p_id INT)
RETURNS VARCHAR(256)
DETERMINISTIC

BEGIN
  DECLARE v_email VARCHAR(256);

  SELECT email
  INTO v_email
  FROM Datos
  WHERE id = p_id;

  RETURN v_email

END //

DELIMITER ;