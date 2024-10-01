DELIMITER //

CREATE PROCEDURE borrar_datos(IN p_id INT)
BEGIN

  DECLARE v_apellido;
  DECLARE v_nombre;
  DECLARE v_saldo;
  DECLARE v_email;

  SET v_apellido = obtener_apellido(p_id);
  SET v_nombre = obtener_nombre(p_id);
  SET v_saldo = obtener_saldo(p_id);
  SET v_email = obtener_email(p_email);

  registrar_operacion(p_id, v_apellido, v_nombre, v_saldo, v_email, 'D');

  DELETE FROM Datos WHERE id = p_id;
END //

DELIMITER ;