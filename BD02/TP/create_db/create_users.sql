CREATE USER 'decano'@'localhost' IDENTIFIED BY 'decano';
GRANT ALL PRIVILEGES ON *.* TO 'decano'@'localhost' WITH GRANT OPTION;

CREATE USER 'director'@'localhost' IDENTIFIED BY 'director';
GRANT SELECT, INSERT, UPDATE, DELETE ON acad.carrera TO 'director'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON acad.plan TO 'director'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON acad.matriculacion TO 'director'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON acad.materia_plan TO 'director'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON acad.turno TO 'director'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON acad.mesa TO 'director'@'localhost';

CREATE USER 'secretaria'@'localhost' IDENTIFIED BY 'secretaria';
GRANT SELECT, INSERT, UPDATE, DELETE ON acad.cursada TO 'secretaria'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON acad.comision TO 'secretaria'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON acad.final TO 'secretaria'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON acad.final_matricula TO 'secretaria'@'localhost';
GRANT SELECT ON acad.materia TO 'secretaria'@'localhost';
GRANT SELECT ON acad.catedra TO 'secretaria'@'localhost';
GRANT SELECT ON acad.alumno TO 'secretaria'@'localhost';
GRANT SELECT ON acad.profesor TO 'secretaria'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON acad.parcial TO 'secretaria'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON acad.parcial_cursada TO 'secretaria'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON acad.final TO 'secretaria'@'localhost';
GRANT SELECT, INSERT, UPDATE, DELETE ON acad.final_matricula TO 'secretaria'@'localhost';

CREATE USER 'profesor'@'localhost' IDENTIFIED BY 'profesor';
GRANT SELECT ON acad.profesor TO 'profesor'@'localhost';
GRANT SELECT ON acad.aula TO 'profesor'@'localhost';
GRANT SELECT ON acad.comision TO 'profesor'@'localhost';
GRANT SELECT ON acad.catedra TO 'profesor'@'localhost';
GRANT SELECT ON acad.materia TO 'profesor'@'localhost';
GRANT SELECT ON acad.parcial TO 'profesor'@'localhost';
GRANT SELECT ON acad.parcial_cursada TO 'profesor'@'localhost';
GRANT SELECT ON acad.turno TO 'profesor'@'localhost';
GRANT SELECT ON acad.mesa TO 'profesor'@'localhost';
GRANT SELECT ON acad.final TO 'profesor'@'localhost';
GRANT SELECT ON acad.final_matricula TO 'profesor'@'localhost';

CREATE USER 'alumno'@'localhost' IDENTIFIED BY 'alumno';
GRANT SELECT ON acad.alumno TO 'alumno'@'localhost';
GRANT SELECT ON acad.matriculacion TO 'alumno'@'localhost';
GRANT SELECT ON acad.plan TO 'alumno'@'localhost';
GRANT SELECT ON acad.materia TO 'alumno'@'localhost';
GRANT SELECT ON acad.profesor TO 'alumno'@'localhost';
GRANT SELECT ON acad.cursada TO 'alumno'@'localhost';
GRANT SELECT ON acad.final_matricula TO 'alumno'@'localhost';
GRANT SELECT ON acad.parcial_cursada TO 'alumno'@'localhost';
GRANT SELECT ON acad.catedra TO 'alumno'@'localhost';
GRANT SELECT ON acad.comision TO 'alumno'@'localhost';
GRANT SELECT ON acad.aula TO 'alumno'@'localhost';

FLUSH PRIVILEGES;

