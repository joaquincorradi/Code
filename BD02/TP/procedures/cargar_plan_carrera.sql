USE acad;



DELIMITER //

CREATE FUNCTION obtener_carrera_id(_nombre VARCHAR(100))
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE v_carrera_id INT;

    SELECT carrera_id INTO v_carrera_id
    FROM carrera
    WHERE nombre = _nombre;

    RETURN v_carrera_id;

END //

DELIMITER ;



DELIMITER //

CREATE FUNCTION verificar_existencia_plan_carrera(_año integer, _carrera_id integer)
RETURNS BOOLEAN
DETERMINISTIC
BEGIN
    DECLARE plan_carrera_existe BOOLEAN;

    SELECT COUNT(*) > 0 INTO plan_carrera_existe
    FROM plan
    WHERE año = _año AND carrera_id = _carrera_id;
    
    RETURN plan_carrera_existe;

END //

DELIMITER ;



DELIMITER //

CREATE PROCEDURE cargar_plan(IN _año integer, IN _carrera_nombre VARCHAR(100))
proc_label:BEGIN

	DECLARE v_carrera_id integer;
    
    SET v_carrera_id = obtener_carrera_id(_carrera_nombre);

	IF v_carrera_id IS NULL THEN
		
        SELECT 'La carrera no existe en la base de datos' AS resultado;
        LEAVE proc_label;
        
	END IF;

	IF NOT verificar_existencia_plan_carrera(_año, v_carrera_id) THEN

		INSERT INTO plan (año, carrera_id) 
		VALUES (_año, v_carrera_id);
		SELECT 'El plan de carrera ha sido agregado exitosamente' AS resultado;

	ELSE

		SELECT 'El plan para esta carrera en ese año ya existe en la base de datos' AS resultado;

	END IF;

END //

DELIMITER ;