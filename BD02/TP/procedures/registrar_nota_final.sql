USE acad;

DELIMITER //

CREATE FUNCTION obtener_final_id(_fecha date, _materia_nombre varchar(100))
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE v_final_id INT;

    SELECT final_id INTO v_final_id
    FROM final
    INNER JOIN materia ON final.materia_id = materia.materia_id
    WHERE final.fecha = _fecha AND materia.nombre = _materia_nombre;

    RETURN v_final_id;

END //

--

CREATE FUNCTION obtener_matriculacion_id_2(_alumno_dni integer, _plan_anio integer, _carrera_nombre VARCHAR(100))
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

--

CREATE FUNCTION verificar_existencia_inscripcion_final_2(_final_id integer, _matriculacion_id integer)
RETURNS BOOLEAN
DETERMINISTIC
BEGIN
    DECLARE inscripcion_final_existe BOOLEAN;

    SELECT COUNT(*) > 0 INTO inscripcion_final_existe
    FROM final_matricula
    WHERE final_id = _final_id AND matriculacion_id = _matriculacion_id;
    
    RETURN inscripcion_final_existe;

END //

--

CREATE PROCEDURE registrar_nota_final(
	IN _nota decimal(5,2),
    IN _presente bool,
    IN _fecha date,
    IN _materia_nombre varchar(100), 
    IN _alumno_dni integer, 
    IN _plan_anio integer, 
    IN _carrera_nombre varchar(100))
proc_label:BEGIN

	DECLARE v_final_id integer;
    DECLARE v_matriculacion_id integer;
    
    SET v_final_id = obtener_final_id(_fecha, _materia_nombre);
    
    IF v_final_id IS NULL THEN
		
        SELECT 'El final seleccionado no existe en la base de datos' AS resultado;
        LEAVE proc_label;
        
	END IF;
    
    SET v_matriculacion_id = obtener_matriculacion_id_2(_alumno_dni, _plan_anio, _carrera_nombre);

	IF v_matriculacion_id IS NULL THEN
		
        SELECT 'El alumno no está inscripto al plan seleccionado' AS resultado;
        LEAVE proc_label;
        
	END IF;

	IF NOT verificar_existencia_inscripcion_final_2(v_final_id, v_matriculacion_id) THEN

		SELECT 'La inscripcion del alumno al final seleccionado no existe en la base de datos' AS resultado;
        LEAVE proc_label;

	ELSE
		
        IF (_nota >= 0 AND _nota <= 10) THEN

			UPDATE final_matricula
			SET nota = _nota, presente = _presente
			WHERE final_id = v_final_id AND matriculacion_id = v_matriculacion_id;
			SELECT 'Se cargo la nota del examen final junto con la asistencia del alumno' AS resultado;
			LEAVE proc_label;
		
        ELSE
        
			SELECT 'La nota no se encuentra dentro de la escala de calificacion (0-10)' AS resultado;
			LEAVE proc_label;

		END IF;
    
    END IF;

END //

DELIMITER ;



-- DROP FUNCTION obtener_final_id;
-- DROP FUNCTION obtener_matriculacion_id_2;
-- DROP FUNCTION verificar_existencia_inscripcion_final_2;
-- DROP PROCEDURE registrar_nota_final;