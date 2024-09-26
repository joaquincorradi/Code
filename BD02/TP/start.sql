-- SOURCE /Users/joaquin/Code/BD02/start.sql;

CREATE DATABASE acad;
USE acad;

SOURCE /Users/joaquin/Code/BD02/create_db/create_db.sql;
SOURCE /Users/joaquin/Code/BD02/create_db/sample_data.sql;
SOURCE /Users/joaquin/Code/BD02/create_db/views.sql;

--

SOURCE /Users/joaquin/Code/BD02/procedures/cargar_carrera.sql;
SOURCE /Users/joaquin/Code/BD02/procedures/cargar_plan_carrera.sql;
SOURCE /Users/joaquin/Code/BD02/procedures/cargar_materia_plan_carrera.sql;
SOURCE /Users/joaquin/Code/BD02/procedures/cargar_matricula.sql;
SOURCE /Users/joaquin/Code/BD02/procedures/inscripcion_materia.sql;
SOURCE /Users/joaquin/Code/BD02/procedures/cargar_parciales.sql;
SOURCE /Users/joaquin/Code/BD02/procedures/inscripcion_examen.sql;
SOURCE /Users/joaquin/Code/BD02/procedures/registrar_nota_final.sql;