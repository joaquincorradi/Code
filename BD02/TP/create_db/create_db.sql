-- source /Users/joaquin/Code/BD01/TP_01/create_db.sql

CREATE TABLE alumno (
    alumno_id int NOT NULL AUTO_INCREMENT,
    nombre varchar(100) NOT NULL,
    apellido varchar(100) NOT NULL,
    dni int NOT NULL,
    PRIMARY KEY (alumno_id),
    UNIQUE (dni)
);

CREATE INDEX index_alumno ON alumno(apellido, nombre);

CREATE TABLE carrera (
    carrera_id int NOT NULL AUTO_INCREMENT,
    nombre varchar(100) NOT NULL,
    titulo varchar(100),
    PRIMARY KEY (carrera_id),
    UNIQUE (nombre)
);

CREATE INDEX index_carrera ON carrera(nombre);

CREATE TABLE plan (
    plan_id int NOT NULL AUTO_INCREMENT,
    año int NOT NULL,
    carrera_id int NOT NULL,
    PRIMARY KEY (plan_id),
    FOREIGN KEY (carrera_id) REFERENCES carrera(carrera_id)
);

CREATE INDEX index_plan ON plan(año);

CREATE TABLE matriculacion (
    matriculacion_id int NOT NULL AUTO_INCREMENT,
    fecha date NOT NULL,
    estado bool NOT NULL DEFAULT 1,
    alumno_id int NOT NULL,
    plan_id int NOT NULL,
    PRIMARY KEY (matriculacion_id),
    FOREIGN KEY (alumno_id) REFERENCES alumno(alumno_id),
    FOREIGN KEY (plan_id) REFERENCES plan(plan_id)
);

CREATE INDEX index_matriculacion ON matriculacion(fecha, estado);

CREATE TABLE materia (
    materia_id int NOT NULL AUTO_INCREMENT,
    nombre varchar(100) NOT NULL,
    PRIMARY KEY (materia_id)
);

CREATE INDEX index_materia ON materia(nombre);

CREATE TABLE materia_plan (
    materia_id INT NOT NULL,
    plan_id INT NOT NULL,
    PRIMARY KEY (plan_id, materia_id),
    FOREIGN KEY (plan_id) REFERENCES plan(plan_id),
    FOREIGN KEY (materia_id) REFERENCES materia(materia_id)
);

CREATE TABLE profesor (
	profesor_id int NOT NULL AUTO_INCREMENT,
    nombre varchar(100) NOT NULL,
    apellido varchar(100) NOT NULL,
    dni int NOT NULL,
    PRIMARY KEY (profesor_id),
    UNIQUE (dni)
);

CREATE INDEX index_profesor ON profesor(apellido, nombre);

CREATE TABLE facultad (
    facultad_id int NOT NULL AUTO_INCREMENT,
    nombre varchar(100) NOT NULL,
    PRIMARY KEY (facultad_id)
);

CREATE INDEX index_facultad ON facultad(nombre);

CREATE TABLE aula (
    aula_id int NOT NULL AUTO_INCREMENT,
    numero int NOT NULL,
    facultad_id int NOT NULL ,
    PRIMARY KEY (aula_id),
    FOREIGN KEY (facultad_id) REFERENCES facultad(facultad_id)
);

CREATE INDEX index_aula ON aula(numero);

CREATE TABLE catedra (
    catedra_id int NOT NULL AUTO_INCREMENT,
    nombre varchar(100) NOT NULL,
    PRIMARY KEY (catedra_id)
);

CREATE INDEX index_catedra ON catedra(nombre);

CREATE TABLE comision (
    comision_id int NOT NULL AUTO_INCREMENT,
    nombre varchar(100) NOT NULL,
    hora_inicio time,
    hora_fin time,
    dia_semana varchar(100),
    catedra_id int NOT NULL,
    profesor_id int NOT NULL,
    materia_id int NOT NULL,
    aula_id int NOT NULL,
    PRIMARY KEY (comision_id),
    FOREIGN KEY (catedra_id) REFERENCES catedra(catedra_id),
    FOREIGN KEY (profesor_id) REFERENCES profesor(profesor_id),
    FOREIGN KEY (materia_id) REFERENCES materia(materia_id),
    FOREIGN KEY (aula_id) REFERENCES aula(aula_id)
);

CREATE INDEX index_comision ON comision(nombre, dia_semana);

CREATE TABLE cursada (
    cursada_id int NOT NULL AUTO_INCREMENT,
    semestre int NOT NULL,
    año int NOT NULL,
    regularidad varchar(100) NOT NULL DEFAULT 'Cursando',
    comision_id int NOT NULL,
    matriculacion_id int NOT NULL,
    PRIMARY KEY (cursada_id),
    FOREIGN KEY (comision_id) REFERENCES comision(comision_id),
    FOREIGN KEY (matriculacion_id) REFERENCES matriculacion(matriculacion_id)
);

CREATE INDEX index_cursada ON cursada(año, semestre, regularidad);

CREATE TABLE parcial (
    parcial_id int NOT NULL AUTO_INCREMENT,
    fecha date,
    comision_id int NOT NULL,
    PRIMARY KEY (parcial_id),
    FOREIGN KEY (comision_id) REFERENCES comision(comision_id)
);

CREATE INDEX index_parcial ON parcial(fecha);

CREATE TABLE parcial_cursada (
    parcial_id int NOT NULL,
    cursada_id int NOT NULL,
    nota decimal(5, 2),
    presente bool NOT NULL,
    PRIMARY KEY (parcial_id, cursada_id),
    FOREIGN KEY (parcial_id) REFERENCES parcial(parcial_id),
    FOREIGN KEY (cursada_id) REFERENCES cursada(cursada_id)
);

CREATE INDEX index_parcial_cursada ON parcial_cursada(nota, presente);

CREATE TABLE turno (
	turno_id int NOT NULL AUTO_INCREMENT,
    fecha_inicio date NOT NULL,
    fecha_fin date NOT NULL,
    PRIMARY KEY (turno_id)
);

CREATE INDEX index_turno ON turno(fecha_inicio, fecha_fin);

CREATE TABLE materia_turno (
	materia_id int NOT NULL ,
    turno_id int NOT NULL,
    PRIMARY KEY (materia_id, turno_id),
    FOREIGN KEY (materia_id) REFERENCES materia(materia_id),
    FOREIGN KEY (turno_id) REFERENCES turno(turno_id)
);

CREATE TABLE mesa (
    mesa_id int NOT NULL AUTO_INCREMENT,
    fecha_inicio date NOT NULL,
    fecha_fin date NOT NULL,
    turno_id int NOT NULL,
    PRIMARY KEY (mesa_id),
    FOREIGN KEY (turno_id) REFERENCES turno(turno_id)
);

CREATE INDEX index_mesa ON mesa(fecha_inicio, fecha_fin);

CREATE TABLE final (
    final_id int NOT NULL AUTO_INCREMENT,
    fecha date NOT NULL,
    mesa_id int NOT NULL,
    profesor_id int NOT NULL,
    materia_id int NOT NULL,
    aula_id int NOT NULL,
    PRIMARY KEY (final_id),
    FOREIGN KEY (mesa_id) REFERENCES mesa(mesa_id),
    FOREIGN KEY (profesor_id) REFERENCES profesor(profesor_id),
    FOREIGN KEY (materia_id) REFERENCES materia(materia_id),
    FOREIGN KEY (aula_id) REFERENCES aula(aula_id)
);

CREATE INDEX index_final ON final(fecha);

CREATE TABLE final_matricula (
    final_id int NOT NULL,
    matriculacion_id int NOT NULL,
    nota decimal(5,2),
    presente bool,
    PRIMARY KEY (final_id, matriculacion_id),
    FOREIGN KEY (final_id) REFERENCES final(final_id),
    FOREIGN KEY (matriculacion_id) REFERENCES matriculacion(matriculacion_id)
);

CREATE INDEX index_final_matricula ON final_matricula(nota, presente);