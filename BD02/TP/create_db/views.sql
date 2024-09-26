-- source /Users/joaquin/Code/BD01/TP_01/views.sql

-- 1
CREATE VIEW inscriptos_por_carrera AS
SELECT t1.nombre, COUNT(t3.alumno_id) AS CANTIDAD_ALUMNOS
FROM carrera t1
LEFT JOIN plan t2 ON t1.carrera_id = t2.carrera_id
LEFT JOIN matriculacion t3 ON t2.plan_id = t3.plan_id
GROUP BY t1.carrera_id;

-- SELECT * FROM inscriptos_por_carrera;

-- 2
CREATE VIEW inscriptos_por_plan AS
SELECT t1.año, COUNT(t2.alumno_id) AS CANTIDAD_ALUMNOS
FROM plan t1
LEFT JOIN matriculacion t2 ON t1.plan_id = t2.plan_id
GROUP BY t1.plan_id;

-- SELECT * FROM inscriptos_por_plan;

-- 3
CREATE VIEW alumnos_activos_plan AS
SELECT t1.año, COUNT(t2.alumno_id) AS CANTIDAD_ALUMNOS
FROM plan t1
LEFT JOIN matriculacion t2 ON t1.plan_id = t2.plan_id
WHERE t2.estado = 1
GROUP BY t1.plan_id;

-- SELECT * FROM alumnos_activos_plan;

-- 4
CREATE VIEW listado_inscriptos_cursando AS
SELECT t1.nombre, t4.alumno_id, t3.regularidad AS estado
FROM materia t1
LEFT JOIN comision t2 ON t2.materia_id = t1.materia_id
LEFT JOIN cursada t3 ON t3.comision_id = t2.comision_id
LEFT JOIN matriculacion t4 ON t4.matriculacion_id = t3.matriculacion_id
WHERE t3.año = 2024 AND t3.semestre = 1;

-- SELECT * FROM listado_inscriptos_cursando;

-- 5
CREATE VIEW alumnos_regulares_materia AS
SELECT t1.nombre, count(*) AS alumnos_regular
FROM materia t1
LEFT JOIN comision t2 ON t2.materia_id = t1.materia_id
LEFT JOIN cursada t3 ON t3.comision_id = t2.comision_id
LEFT JOIN matriculacion t4 ON t4.matriculacion_id = t3.matriculacion_id
WHERE t3.regularidad = "Regular"
GROUP BY t1.nombre;

-- SELECT * FROM alumnos_regulares_materia;

CREATE VIEW alumnos_libres_materia AS
SELECT t1.nombre, count(*) AS alumnos_libres
FROM materia t1
LEFT JOIN comision t2 ON t2.materia_id = t1.materia_id
LEFT JOIN cursada t3 ON t3.comision_id = t2.comision_id
LEFT JOIN matriculacion t4 ON t4.matriculacion_id = t3.matriculacion_id
WHERE t3.regularidad = "Libre"
GROUP BY t1.nombre;

-- SELECT * FROM alumnos_libres_materia;

-- 6
CREATE VIEW examenes_aprobados AS
SELECT m.nombre, count(*) AS parciales_aprobados
FROM parcial_cursada pc
LEFT JOIN parcial p ON pc.parcial_id = p.parcial_id
LEFT JOIN comision c ON p.comision_id = c.comision_id
LEFT JOIN materia m ON c.materia_id = m.materia_id
where pc.nota >= 4
group by m.materia_id;

-- SELECT * FROM examenes_aprobados;


CREATE VIEW examenes_rendidos AS
SELECT m.nombre, count(*) AS parciales_rendidos
FROM parcial_cursada pc
LEFT JOIN parcial p ON pc.parcial_id = p.parcial_id
LEFT JOIN comision c ON p.comision_id = c.comision_id
LEFT JOIN materia m ON c.materia_id = m.materia_id
where pc.nota is not NULL
group by m.materia_id;

-- SELECT * FROM examenes_rendidos;