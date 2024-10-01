DELIMITER //

CREATE PROCEDURE alta_socio(
  IN p_apellido VARCHAR(256),
  IN p_nombre VARCHAR(256),
  IN p_fecha_ingreso DATE,
  IN p_actividad VARCHAR(256),
  IN p_estado VARCHAR(256)
)
BEGIN

  INSERT INTO socio(apellido, nombre, fecha_ingreso, actividad, estado)
  VALUES (p_apellido, p_nombre, p_fecha_ingreso, p_actividad, p_estado);

END //

DELIMITER ;