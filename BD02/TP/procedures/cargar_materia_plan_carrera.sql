USE acad;



DELIMITER //

CREATE FUNCTION obtener_plan_id(_plan_anio integer, _carrera_nombre VARCHAR(100))
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE v_plan_id INT;

    SELECT plan_id INTO v_plan_id
    FROM plan
    INNER JOIN carrera ON plan.carrera_id = carrera.carrera_id
    WHERE plan.año = _plan_anio AND carrera.nombre = _carrera_nombre;

    RETURN v_plan_id;

END //

DELIMITER ;



DELIMITER //

CREATE FUNCTION obtener_materia_id(_nombre VARCHAR(100))
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE v_materia_id INT;

    SELECT materia_id INTO v_materia_id
    FROM materia
    WHERE nombre = _nombre;

    RETURN v_materia_id;

END //

DELIMITER ;



DELIMITER //

CREATE FUNCTION verificar_existencia_materia_plan(_materia_id integer, _plan_id integer)
RETURNS BOOLEAN
DETERMINISTIC
BEGIN
    DECLARE materia_plan_existe BOOLEAN;

    SELECT COUNT(*) > 0 INTO materia_plan_existe
    FROM materia_plan
    WHERE materia_id = _materia_id AND plan_id = _plan_id;
    
    RETURN materia_plan_existe;

END //

DELIMITER ;



DELIMITER //

CREATE PROCEDURE cargar_materia(IN _nombre_materia varchar(100), IN _plan_anio integer, IN _carrera_nombre VARCHAR(100))
proc_label:BEGIN

	DECLARE v_materia_id integer;
    DECLARE v_plan_id integer;
    
    SET v_materia_id = obtener_materia_id(_nombre_materia);
    
    IF v_materia_id IS NULL THEN
		
        SELECT 'La materia no existe en la base de datos' AS resultado;
        LEAVE proc_label;
        
	END IF;
    
    SET v_plan_id = obtener_plan_id(_plan_anio, _carrera_nombre);

	IF v_plan_id IS NULL THEN
		
        SELECT 'El plan para esta carrera en ese año no existe en la base de datos' AS resultado;
        LEAVE proc_label;
        
	END IF;

	IF NOT verificar_existencia_materia_plan(v_materia_id, v_plan_id) THEN

		INSERT INTO materia_plan (materia_id, plan_id) 
		VALUES (v_materia_id, v_plan_id);
		SELECT 'La materia ha sido agregada exitosamente al plan de esa carrera' AS resultado;

	ELSE

		SELECT 'La materia ya está asociada al plan' AS resultado;

	END IF;

END //

DELIMITER ;