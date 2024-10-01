DELIMITER //

CREATE PROCEDURE insertar_datos(
  IN p_apellido VARCHAR(256), 
  IN p_nombre VARCHAR(256), 
  IN p_saldo DECIMAL(11,2), 
  IN p_mail VARCHAR(256) 
  )
BEGIN

  INSERT INTO Datos (apellido, nombre, saldo, mail)
  VALUES (p_apellido, p_nombre, p_saldo, p_mail);

  registrar_operacion(LAST_INSERT_ID(), p_apellido, p_nombre, p_saldo, p_mail, 'I');

END //

DELIMITER ;