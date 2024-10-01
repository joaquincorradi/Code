DELIMITER //

CREATE PROCEDURE actualizar_datos (
  IN p_id INT,
  IN p_apellido VARCHAR(256), 
  IN p_nombre VARCHAR(256), 
  IN p_saldo DECIMAL(11,2)
)
BEGIN

  DECLARE v_email VARCHAR(256);

  UPDATE Datos
  SET apellido = p_apellido, nombre = p_nombre, saldo = p_saldo
  WHERE id = p_id;

  SET v_email = obtener_email(p_id);

  registrar_operacion(p_id, p_apellido, p_nombre, p_saldo, v_mail, 'U');

END //

DELIMITER ;