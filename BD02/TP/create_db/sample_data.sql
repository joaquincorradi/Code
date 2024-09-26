-- source /Users/joaquin/Code/BD01/TP_01/sample_data.sql

INSERT INTO alumno (nombre, apellido, dni)
VALUES
    ('Juan', 'Pérez', 43938475),
    ('María', 'González', 44409856),
    ('Ana', 'Rodríguez', 45968374);

INSERT INTO alumno (nombre, apellido, dni)
VALUES
    ('Joaquin', 'Corradi', 43188161);

INSERT INTO carrera (nombre, titulo)
VALUES
    ('Ingeniería de Sistemas', 'Ingeniero de Sistemas'),
    ('Ingeniería en Computación', 'Ingeniero en Computación');

INSERT INTO plan (año, carrera_id)
VALUES
    (2016, 1),
    (2023, 2);

INSERT INTO matriculacion (fecha, estado, alumno_id, plan_id)
VALUES
    ('2024-03-01', 1, 1, 1),
    ('2024-03-01', 1, 2, 2),
    ('2024-03-01', 1, 3, 1);

INSERT INTO matriculacion (fecha, estado, alumno_id, plan_id)
VALUES
    ('2024-03-01', 1, 4, 1);

INSERT INTO materia (nombre)
VALUES
    ('Arquitectura de Software'),
    ('Base de Datos'),
    ('Electrónica Analógica'),
    ('Técnicas Digitales');

INSERT INTO materia_plan (materia_id, plan_id)
VALUES
    (1, 1),
    (2, 1),
    (3, 2),
    (4, 2);

INSERT INTO profesor (nombre, apellido, dni)
VALUES
    ('Carlos', 'Sánchez', 23849506),
    ('Laura', 'Martínez', 12948574);

INSERT INTO facultad (nombre)
VALUES
    ('Facultad de Ingeniería');

INSERT INTO aula (numero, facultad_id)
VALUES
    (2, 1),
    (14, 1);

INSERT INTO catedra (nombre)
VALUES
    ('A'),
    ('B');

INSERT INTO comision (nombre, hora_inicio, hora_fin, dia_semana, catedra_id, profesor_id, materia_id, aula_id)
VALUES
    ('1', '16:00:00', '18:00:00', 'Lunes', 1, 1, 1, 1),
    ('2', '14:00:00', '16:00:00', 'Martes', 2, 2, 2, 2),
    ('1', '18:00:00', '20:00:00', 'Miércoles', 1, 2, 4, 1),
    ('1','16:00:00', '18:00:00', 'Jueves', 1, 1, 3, 1);

INSERT INTO cursada (semestre, año, regularidad, comision_id, matriculacion_id)
VALUES
    (2, 2024, 'Cursando', 1, 1),
    (2, 2024, 'Cursando', 2, 2),
    (2, 2023, 'Libre', 1, 3),
    (2, 2024, 'Recursando', 1, 3),
    (1, 2024, 'Regular', 3, 1),
    (1, 2024, 'Regular', 4, 2);

INSERT INTO parcial (fecha, comision_id)
VALUES
    ('2024-04-21', 1),
    ('2024-04-25', 2),
    ('2024-04-25', 3),
    ('2024-09-12', 1),
    ('2024-09-12', 2),
    ('2024-09-12', 3);

INSERT INTO parcial_cursada (parcial_id, cursada_id, nota, presente)
VALUES
    (1, 1, 4.0, 1),
    (2, 2, NULL, 0),
    (3, 5, 8.0, 1);

INSERT INTO turno (fecha_inicio, fecha_fin)
VALUES
    ('2024-06-24', '2024-07-27'),
    ('2024-11-21', '2024-12-18');

INSERT INTO materia_turno (materia_id, turno_id)
VALUES
    (1, 1);

INSERT INTO mesa (fecha_inicio, fecha_fin, turno_id)
VALUES
    ('2024-06-24', '2024-07-05', 1);

INSERT INTO final (fecha, mesa_id, profesor_id, materia_id, aula_id)
VALUES
    ('2024-07-01', 1, 1, 1, 1),
    ('2024-07-14', 1, 2, 3, 1),
    ('2024-07-10', 1, 1, 4, 1);

INSERT INTO final_matricula (final_id, matriculacion_id, nota, presente)
VALUES
    (1, 1, 7.50, 1),
    (2 ,2, NULL, NULL);