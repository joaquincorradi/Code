USE acad;

DELIMITER //

CREATE FUNCTION get_matriculacion_id(_dni_alumno INT, _plan_año YEAR, _carrera_nombre VARCHAR(100))
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE v_matriculacion_id INT;

    SELECT matriculacion_id INTO v_matriculacion_id
    FROM matriculacion
    JOIN plan ON matriculacion.plan_id = plan.plan_id
    JOIN carrera ON plan.carrera_id = carrera.carrera_id
    JOIN alumno ON matriculacion.alumno_id = alumno.alumno_id
    WHERE alumno.dni = _dni_alumno AND plan.año = _plan_año AND carrera.nombre = _carrera_nombre;

    RETURN v_matriculacion_id;
END //

CREATE FUNCTION get_final_id(_fecha DATE, _materia_id INT)
RETURNS INT
DETERMINISTIC
BEGIN
	DECLARE v_final_id INT;
    
    SELECT f.final_id INTO v_final_id
    FROM final f
    WHERE f.fecha = _fecha and f.materia_id = _materia_id;
    
    RETURN v_final_id;
    
END //


CREATE FUNCTION get_materia_id(_nombre VARCHAR(100))
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE v_materia_id INT;

    SELECT materia_id INTO v_materia_id
    FROM materia
    WHERE nombre = _nombre;

    RETURN v_materia_id;

END //

CREATE FUNCTION verificar_existencia_inscripcion_final(_final_id integer, _matriculacion_id integer)
RETURNS BOOLEAN
DETERMINISTIC
BEGIN
    DECLARE inscripcion_final_existe BOOLEAN;

    SELECT COUNT(*) > 0 INTO inscripcion_final_existe
    FROM final_matricula
    WHERE final_id = _final_id AND matriculacion_id = _matriculacion_id AND nota IS NULL AND presente IS NULL;
    
    RETURN inscripcion_final_existe;

END //

CREATE FUNCTION get_regularidad(_materia_id integer, _matriculacion_id integer)
RETURNS VARCHAR(100)
DETERMINISTIC
BEGIN

	DECLARE v_regularidad VARCHAR(100);
    
    SELECT c.regularidad INTO v_regularidad
    FROM cursada c
    LEFT JOIN comision co ON c.comision_id = co.comision_id
    LEFT JOIN matriculacion m ON c.matriculacion_id = m.matriculacion_id
    WHERE co.materia_id = _materia_id and m.matriculacion_id = _matriculacion_id;
    
    RETURN v_regularidad;

END //

CREATE PROCEDURE inscripcion_examen(
	IN _fecha DATE,
    IN _dni INT,
	IN _plan YEAR, 
    IN _carrera VARCHAR(100), 
    IN _materia_nombre VARCHAR(100)
    )
proc_label:BEGIN

	DECLARE v_matriculacion_id integer;
    DECLARE v_materia_id integer;
	DECLARE v_regularidad varchar(100);
    DECLARE v_final_id INT;
    
    SET v_matriculacion_id = get_matriculacion_id(_dni, _plan, _carrera);
    SET v_materia_id = get_materia_id(_materia_nombre);
    SET v_regularidad = get_regularidad(v_materia_id, v_matriculacion_id);
    SET v_final_id = get_final_id(_fecha, v_materia_id);
    
    IF v_final_id IS NULL THEN
		
        SELECT 'El final seleccionado no existe en la base de datos' AS resultado;
        LEAVE proc_label;
        
	END IF;
    
    IF v_matriculacion_id IS NULL THEN
		
        SELECT 'El alumno no está inscripto al plan seleccionado' AS resultado;
        LEAVE proc_label;
        
	END IF;
    
    IF NOT verificar_existencia_inscripcion_final(v_final_id, v_matriculacion_id) THEN
    
		IF v_regularidad = 'Regular' THEN
			
            INSERT INTO final_matricula(final_id, matriculacion_id, nota, presente) 
			VALUES(v_final_id, v_matriculacion_id, NULL, NULL);
            SELECT 'El alumno se inscribió exitosamente en condición de Regular' AS resultado;
			LEAVE proc_label;
            
		ELSE
        
			SELECT 'El alumno no se encuentra en condición de Regular para inscribirse' AS resultado;
			LEAVE proc_label;
		
        END IF;
        
	ELSE
    
		SELECT 'El alumno tiene una inscripcion previa a este examen' AS resultado;
        LEAVE proc_label;
	
    END IF;
    
END //

DELIMITER ;

-- DROP FUNCTION get_matriculacion_id;
-- DROP FUNCTION get_final_id;
-- DROP FUNCTION get_materia_id;
-- DROP FUNCTION verificar_existencia_inscripcion_final;
-- DROP FUNCTION get_regularidad;
-- DROP PROCEDURE inscripcion_examen;