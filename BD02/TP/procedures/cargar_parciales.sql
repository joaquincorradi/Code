DELIMITER //

CREATE FUNCTION verificar_matriculacion(
    p_dni_alumno INT,
    p_plan_año YEAR,
    p_carrera_nombre VARCHAR(100)
)
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE v_matriculacion_id INT;

    SELECT matriculacion_id
    INTO v_matriculacion_id
    FROM matriculacion
    JOIN plan ON matriculacion.plan_id = plan.plan_id
    JOIN carrera ON plan.carrera_id = carrera.carrera_id
    JOIN alumno ON matriculacion.alumno_id = alumno.alumno_id
    WHERE alumno.dni = p_dni_alumno
      AND plan.año = p_plan_año
      AND carrera.nombre = p_carrera_nombre;

    RETURN v_matriculacion_id;
END //

--

CREATE FUNCTION verificar_comision(
    p_comision_nombre VARCHAR(100),
    p_materia_nombre VARCHAR(100)
)
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE v_comision_id INT;

    SELECT comision_id
    INTO v_comision_id
    FROM comision
    JOIN materia ON comision.materia_id = materia.materia_id
    WHERE comision.nombre = p_comision_nombre
      AND materia.nombre = p_materia_nombre;

    RETURN v_comision_id;
END //

--

CREATE FUNCTION verificar_parcial(
    p_parcial_fecha DATE,
    p_comision_nombre VARCHAR(100),
    p_materia_nombre VARCHAR(100)
)
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE v_parcial_id INT;

    SELECT parcial_id
    INTO v_parcial_id
    FROM parcial
    JOIN comision ON parcial.comision_id = comision.comision_id
    JOIN materia ON comision.materia_id = materia.materia_id
    WHERE parcial.fecha = p_parcial_fecha
      AND comision.nombre = p_comision_nombre
      AND materia.nombre = p_materia_nombre;

    RETURN v_parcial_id;
END //

--

CREATE FUNCTION verificar_regularidad_cursando(
    p_comision_id INT,
    p_matriculacion_id INT
)
RETURNS BOOL
DETERMINISTIC
BEGIN
    DECLARE v_regularidad_cursando BOOL;

    SELECT COUNT(*) > 0
    INTO v_regularidad_cursando
    FROM cursada
    WHERE comision_id = p_comision_id
      AND matriculacion_id = p_matriculacion_id
      AND regularidad = 'Cursando';

    RETURN v_regularidad_cursando;
END //

--

CREATE FUNCTION obtener_cursada_ID(
    p_matriculacion_id INT,
    p_comision_id INT
)
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE v_cursada_id INT;

    SELECT cursada.cursada_id
    INTO v_cursada_id
    FROM cursada
    WHERE matriculacion_id = p_matriculacion_id
      AND comision_id = p_comision_id;

    RETURN v_cursada_id;
END //

--

CREATE FUNCTION contar_parciales_aprobados(
    p_cursada_id INT
)
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE v_parciales_aprobados INT;

    SELECT COUNT(*)
    INTO v_parciales_aprobados
    FROM parcial_cursada
    WHERE cursada_id = p_cursada_id
      AND nota >= 4.0
      AND presente = TRUE;

    RETURN v_parciales_aprobados;
END //

--

CREATE FUNCTION contar_parciales_no_aprobados(
    p_cursada_id INT
)
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE v_parciales_no_aprobados INT;

    SELECT COUNT(*)
    INTO v_parciales_no_aprobados
    FROM parcial_cursada
    WHERE cursada_id = p_cursada_id
      AND (nota < 4.0
      OR presente = FALSE);

    RETURN v_parciales_no_aprobados;
END //

--

CREATE PROCEDURE cargar_parcial(
    IN p_dni_alumno INT,
    IN p_plan_año YEAR,
    IN p_carrera_nombre VARCHAR(100),
    IN p_comision_nombre VARCHAR(100),
    IN p_materia_nombre VARCHAR(100),
    IN p_parcial_fecha DATE,
    IN p_parcial_nota DECIMAL(5, 2),
    IN p_parcial_presente BOOL
)
PROC_LABEL:BEGIN
    DECLARE v_matriculacion_id INT;
    DECLARE v_comision_id INT;
    DECLARE v_parcial_id INT;
    DECLARE v_cursada_id INT;

    SET v_matriculacion_id = verificar_matriculacion(p_dni_alumno, p_plan_año, p_carrera_nombre);

    IF v_matriculacion_id IS NULL THEN
        SELECT 'El alumno no está inscripto al plan seleccionado.' AS resultado;
        LEAVE PROC_LABEL;
    END IF;

    SET v_comision_id = verificar_comision(p_comision_nombre, p_materia_nombre);

    IF v_comision_id IS NULL THEN
        SELECT 'La comisión de la materia seleccionada no existe.' AS resultado;
        LEAVE PROC_LABEL;
    END IF;

    SET v_parcial_id = verificar_parcial(p_parcial_fecha, p_comision_nombre, p_materia_nombre);

    IF v_parcial_id IS NULL THEN
        SELECT 'El parcial en la fecha seleccionada no existe.' AS resultado;
        LEAVE PROC_LABEL;
    END IF;

    IF NOT verificar_regularidad_cursando(v_comision_id, v_matriculacion_id) THEN
        SELECT 'El alumno no se encuentra cursando la materia seleccionada.' AS resultado;
        LEAVE PROC_LABEL;
    ELSE
        SET v_cursada_id = obtener_cursada_ID(v_matriculacion_id, v_comision_id);
        IF v_cursada_id IS NULL THEN
            SELECT 'El alumno no se encuentra inscripto a la comision seleccionada' AS resultado;
            LEAVE PROC_LABEL;
        END IF;
        INSERT INTO parcial_cursada(parcial_id, cursada_id, nota, presente)
        VALUES
            (v_parcial_id, v_cursada_id, p_parcial_nota, p_parcial_presente);
    END IF;

    IF contar_parciales_aprobados(v_cursada_id) = 2 THEN
        UPDATE cursada
        SET regularidad = 'Regular'
        WHERE cursada_id = v_cursada_id;
        SELECT 'Se cambió la regularidad por <Regular>' AS resultado;
    ELSEIF contar_parciales_no_aprobados(v_cursada_id) = 2 THEN
        UPDATE cursada
        SET regularidad = 'Libre'
        WHERE cursada_id = v_cursada_id;
        SELECT 'Se cambió la regularidad por <Libre>' AS resultado;
    END IF;

END //

DELIMITER ;