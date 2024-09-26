USE acad;



DELIMITER //

CREATE FUNCTION obtener_alumno_id(_dni integer)
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE v_alumno_id INT;

    SELECT alumno_id INTO v_alumno_id
    FROM alumno
    WHERE dni = _dni;

    RETURN v_alumno_id;

END //

DELIMITER ;



DELIMITER //

CREATE FUNCTION obtener_plan_id_2(_plan_anio integer, _carrera_nombre VARCHAR(100))
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

CREATE FUNCTION verificar_existencia_matricula(_alumno_id integer, _plan_id integer)
RETURNS BOOLEAN
DETERMINISTIC
BEGIN
    DECLARE matricula_existe BOOLEAN;

    SELECT COUNT(*) > 0 INTO matricula_existe
    FROM matriculacion
    WHERE alumno_id = _alumno_id AND plan_id = _plan_id;
    
    RETURN matricula_existe;

END //

DELIMITER ;



DELIMITER //

CREATE PROCEDURE cargar_matricula(IN _alumno_dni integer, IN _plan_anio integer, IN _carrera_nombre VARCHAR(100))
proc_label:BEGIN

	DECLARE v_alumno_id integer;
    DECLARE v_plan_id integer;
    
    SET v_alumno_id = obtener_alumno_id(_alumno_dni);
    
    IF v_alumno_id IS NULL THEN
		
        SELECT 'El alumno no existe en la base de datos' AS resultado;
        LEAVE proc_label;
        
	END IF;
    
    SET v_plan_id = obtener_plan_id_2(_plan_anio, _carrera_nombre);

	IF v_plan_id IS NULL THEN
		
        SELECT 'El plan para esta carrera en ese año no existe en la base de datos' AS resultado;
        LEAVE proc_label;
        
	END IF;

	IF NOT verificar_existencia_matricula(v_alumno_id, v_plan_id) THEN

		INSERT INTO matriculacion (fecha, estado, alumno_id, plan_id) 
		VALUES (now(), 1, v_alumno_id, v_plan_id);
		SELECT 'La matricula ha sido agregada exitosamente al plan de esa carrera' AS resultado;

	ELSE

		SELECT 'El alumno ya está asociado al plan' AS resultado;

	END IF;

END //

DELIMITER ;