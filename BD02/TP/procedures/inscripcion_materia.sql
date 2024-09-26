USE acad;



DELIMITER //

CREATE FUNCTION obtener_comision_id(_comision_nombre varchar(100), _materia_nombre varchar(100))
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE v_comision_id INT;

    SELECT comision_id INTO v_comision_id
    FROM comision
    INNER JOIN materia ON comision.materia_id = materia.materia_id
    WHERE comision.nombre = _comision_nombre AND materia.nombre = _materia_nombre;

    RETURN v_comision_id;

END //

DELIMITER ;



DELIMITER //

CREATE FUNCTION obtener_matriculacion_id(_alumno_dni integer, _plan_anio integer, _carrera_nombre VARCHAR(100))
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE v_matriculacion_id INT;

    SELECT matriculacion_id INTO v_matriculacion_id
    FROM matriculacion
    INNER JOIN plan ON matriculacion.plan_id = plan.plan_id
    INNER JOIN carrera ON plan.carrera_id = carrera.carrera_id
    INNER JOIN alumno ON matriculacion.alumno_id = alumno.alumno_id
    WHERE alumno.dni = _alumno_dni AND plan.año = _plan_anio AND carrera.nombre = _carrera_nombre;

    RETURN v_matriculacion_id;

END //

DELIMITER ;



DELIMITER //

CREATE FUNCTION verificar_materia_plan(_materia_nombre varchar(100), _plan_anio integer, _carrera_nombre varchar(100))
RETURNS BOOLEAN
DETERMINISTIC
BEGIN
    DECLARE materia_plan_existe BOOLEAN;

    SELECT COUNT(*) > 0 INTO materia_plan_existe
    FROM materia_plan
    INNER JOIN plan ON materia_plan.plan_id = plan.plan_id
    INNER JOIN carrera ON plan.carrera_id = carrera.carrera_id
    INNER JOIN materia ON materia_plan.materia_id = materia.materia_id
    WHERE materia.nombre = _materia_nombre AND plan.año = _plan_anio AND carrera.nombre = _carrera_nombre;
    
    RETURN materia_plan_existe;

END //

DELIMITER ;



DELIMITER //

CREATE FUNCTION verificar_existencia_cursada(_comision_id integer, _matriculacion_id integer)
RETURNS BOOLEAN
DETERMINISTIC
BEGIN
    DECLARE cursada_existe BOOLEAN;

    SELECT COUNT(*) > 0 INTO cursada_existe
    FROM cursada
    WHERE comision_id = _comision_id AND matriculacion_id = _matriculacion_id;
    
    RETURN cursada_existe;

END //

DELIMITER ;



DELIMITER //

CREATE FUNCTION verificar_regularidad_cursada(_comision_id integer, _matriculacion_id integer)
RETURNS BOOLEAN
DETERMINISTIC
BEGIN
    DECLARE regularidad_cursando_o_regular BOOLEAN;

    SELECT COUNT(*) > 0 INTO regularidad_cursando_o_regular
    FROM cursada
    WHERE comision_id = _comision_id AND matriculacion_id = _matriculacion_id AND (regularidad = 'Cursando' OR regularidad = 'Regular');
    
    RETURN regularidad_cursando_o_regular;

END //

DELIMITER ;



DELIMITER //

CREATE PROCEDURE cargar_inscripcion_materia(IN _semestre integer, IN _comision_nombre varchar(100), IN _materia_nombre varchar(100), IN _alumno_dni integer, IN _plan_anio integer, IN _carrera_nombre varchar(100))
proc_label:BEGIN

	DECLARE v_comision_id integer;
    DECLARE v_matriculacion_id integer;
    
    SET v_comision_id = obtener_comision_id(_comision_nombre, _materia_nombre);
    
    IF v_comision_id IS NULL THEN
		
        SELECT 'La comision de la materia seleccionada no existe en la base de datos' AS resultado;
        LEAVE proc_label;
        
	END IF;
    
    SET v_matriculacion_id = obtener_matriculacion_id(_alumno_dni, _plan_anio, _carrera_nombre);

	IF v_matriculacion_id IS NULL THEN
		
        SELECT 'El alumno no está inscripto al plan seleccionado' AS resultado;
        LEAVE proc_label;
        
	END IF;
    
    SET v_matriculacion_id = obtener_matriculacion_id(_alumno_dni, _plan_anio, _carrera_nombre);

	IF NOT verificar_materia_plan(_materia_nombre, _plan_anio, _carrera_nombre) THEN
		
        SELECT 'La materia no está en el plan seleccionado' AS resultado;
        LEAVE proc_label;
        
	END IF;

	IF NOT verificar_existencia_cursada(v_comision_id, v_matriculacion_id) THEN

		INSERT INTO cursada (semestre, año, regularidad, comision_id, matriculacion_id) 
		VALUES (_semestre, year(curdate()), 'Cursando', v_comision_id, v_matriculacion_id);
		SELECT 'La inscripcion a la materia ha sido agregada exitosamente' AS resultado;

	ELSE
    
		IF NOT verificar_regularidad_cursada(v_comision_id, v_matriculacion_id) THEN

			INSERT INTO cursada (semestre, año, regularidad, comision_id, matriculacion_id) 
			VALUES (_semestre, year(curdate()), 'Cursando', v_comision_id, v_matriculacion_id);
			SELECT 'La inscripcion a la materia ha sido agregada exitosamente (Ya tenia una inscipciòn: Libre)' AS resultado;
            LEAVE proc_label;
		
        ELSE
        
			SELECT 'Ya se encuentra inscripto a la materia seleccionada (Cursando o Regular)' AS resultado;
		
        END IF;

	END IF;

END //

DELIMITER ;