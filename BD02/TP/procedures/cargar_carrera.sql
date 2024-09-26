USE acad;



DELIMITER //

CREATE FUNCTION verificar_existencia_carrera(_nombre_carrera VARCHAR(100))
RETURNS BOOLEAN
DETERMINISTIC
BEGIN
    DECLARE carrera_existe BOOLEAN;
    
    SELECT COUNT(*) > 0 INTO carrera_existe
    FROM carrera
    WHERE nombre = _nombre_carrera;
    
    RETURN carrera_existe;
END //

DELIMITER ;



DELIMITER //

CREATE PROCEDURE cargar_carrera(IN _nombre_carrera VARCHAR(100), IN _titulo VARCHAR(100))
proc_label:BEGIN

    IF NOT verificar_existencia_carrera(_nombre_carrera) THEN

        INSERT INTO carrera (nombre, titulo) 
        VALUES (_nombre_carrera, _titulo);
        SELECT 'La carrera ha sido agregada exitosamente' AS resultado;
    ELSE

        SELECT 'La carrera ya existe en la base de datos' AS resultado;
    END IF;
END //

DELIMITER ;