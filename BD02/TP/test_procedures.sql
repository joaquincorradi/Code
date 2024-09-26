CALL cargar_carrera('Ingeniería de Sistemas', 'Ingeniero en Sistemas');
CALL cargar_carrera('Ingeniería Electrónica', 'Ingeniero Electrónico');

--

CALL cargar_plan(2016, 'Arquitectura');
CALL cargar_plan(2016, 'Ingeniería de Sistemas');
CALL cargar_plan(2017, 'Ingeniería Electrónica');

--

CALL cargar_materia('Sanguichitos de Miga II', 2006, 'Ingeniería de Sistemas');
CALL cargar_materia('Base de Datos', 1990, 'Ingeniería de Sistemas');
CALL cargar_materia('Base de Datos', 2016, 'Ingeniería de Sistemas');
CALL cargar_materia('Electrónica Analógica', 2016, 'Ingeniería de Sistemas');

--

CALL cargar_matricula(12345678, 2006, 'Ingeniería de Sistemas');
CALL cargar_matricula(43938475, 1990, 'Ingeniería de Sistemas');
CALL cargar_matricula(43938475, 2016, 'Ingeniería de Sistemas');
CALL cargar_matricula(44409856, 2016, 'Ingeniería de Sistemas');

--

CALL cargar_inscripcion_materia(2, '3', 'Base de Datos', 43938475, 2016, 'Ingenierìa de Sistemas');
CALL cargar_inscripcion_materia(2, '2', 'Base de Datos', 12345678, 2016, 'Ingenierìa de Sistemas');
CALL cargar_inscripcion_materia(2, '1', 'Técnicas Digitales', 43938475, 2016, 'Ingenierìa de Sistemas');
CALL cargar_inscripcion_materia(2, '1', 'Arquitectura de Software', 43938475, 2016, 'Ingenierìa de Sistemas');
CALL cargar_inscripcion_materia(2, '1', 'Arquitectura de Software', 45968374, 2016, 'Ingenierìa de Sistemas');
CALL cargar_inscripcion_materia(2, '1', 'Técnicas Digitales', 44409856, 2023, 'Ingenierìa en Computación');
CALL cargar_inscripcion_materia(2, '1', 'Arquitectura de Software', 43938475, 2016, 'Ingenierìa de Sistemas');
CALL cargar_inscripcion_materia(2, '1', 'Arquitectura de Software', 43188161, 2016, 'Ingenierìa de Sistemas');

--

CALL cargar_parcial(12345678, '2016', 'Ingenierìa de Sistemas', '1', 'Arquitectura de Software', '2024-09-12', 7.2, 1);
CALL cargar_parcial(43938475, '2016', 'Ingenierìa de Sistemas', '10', 'Arquitectura de Software', '2024-09-12', 7.2, 1);
CALL cargar_parcial(43938475, '2016', 'Ingenierìa de Sistemas', '1', 'Tècnicas Digitales', '2024-09-12', 7.2, 1);
CALL cargar_parcial(43938475, '2016', 'Ingenierìa de Sistemas', '2', 'Base de Datos', '2024-04-25', 7.2, 1);
CALL cargar_parcial(43938475, '2016', 'Ingenierìa de Sistemas', '1', 'Arquitectura de Software', '2024-09-12', 7.2, 1);
CALL cargar_parcial(44409856, '2023', 'Ingenierìa en Computaciòn', '2', 'Base de Datos', '2024-09-12', 3.1, 1);
CALL cargar_parcial(43938475, '2016', 'Ingenierìa de Sistemas', '1', 'Arquitectura de Software', '2024-09-12', 9.0, 1);
CALL cargar_parcial(43188161, '2016', 'Ingenierìa de Sistemas', '1', 'Arquitectura de Software', '2024-04-21', 10.0, 1);
CALL cargar_parcial(43188161, '2016', 'Ingenierìa de Sistemas', '1', 'Arquitectura de Software', '2024-09-12', 10.0, 1);

--

CALL inscripcion_examen('2024-07-14', '12345678', '2023', 'Ingeniería en Computacion', 'Electrónica Analógica');
CALL inscripcion_examen('2024-12-12', '44409856', '2023', 'Ingeniería en Computacion', 'Electrónica Analógica');
CALL inscripcion_examen('2024-07-14', '44409856', '2023', 'Ingeniería en Computacion', 'Electrónica Analógica');
CALL inscripcion_examen('2024-07-01', '44409856', '2023', 'Ingeniería en Computacion', 'Arquitectura de Software');
CALL inscripcion_examen('2024-07-10', '43938475', '2016', 'Ingeniería de Sistemas', 'Técnicas Digitales');
CALL inscripcion_examen('2024-07-01', '43188161', '2016', 'Ingeniería de Sistemas', 'Arquitectura de Software');

--

CALL registrar_nota_final(8, 1, '2024-07-01', 'Sanguchitos de Miga II', 43938475, 2016, 'Ingenierìa de Sistemas');
CALL registrar_nota_final(8, 1, '2024-07-01', 'Arquitectura de Software', 12345678, 2016, 'Ingenierìa de Sistemas');
CALL registrar_nota_final(8, 1, '2024-07-01', 'Arquitectura de Software', 45968374, 2016, 'Ingenierìa de Sistemas');
CALL registrar_nota_final(-4, 1, '2024-07-01', 'Arquitectura de Software', 43938475, 2016, 'Ingenierìa de Sistemas');
CALL registrar_nota_final(8, 1, '2024-07-01', 'Arquitectura de Software', 43938475, 2016, 'Ingenierìa de Sistemas');