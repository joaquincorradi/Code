import pandas as pd
import mysql.connector
from mysql.connector import Error

# Función para conectar a la base de datos
def create_connection():
    connection = None
    try:
        connection = mysql.connector.connect(
            host='localhost',  # Cambia esto si es necesario
            user='tu_usuario',
            password='tu_contraseña',
            database='precios_claros'
        )
        print("Conexión a MySQL exitosa")
    except Error as e:
        print(f"Error: '{e}'")
    return connection

# Función para cargar el CSV a la base de datos
def load_csv_to_db(file_path):
    # Cargar el CSV en un DataFrame
    df = pd.read_csv(file_path, delimiter=';')

    # Conectar a la base de datos
    connection = create_connection()

    # Insertar datos en la base de datos
    if connection:
        cursor = connection.cursor()
        for index, row in df.iterrows():
            sql = """
            INSERT INTO comercio (id_comercio, id_bandera, comercio_cuit, comercio_razon_social, 
                                  comercio_bandera_nombre, comercio_bandera_url, 
                                  comercio_ultima_actualizacion, comercio_version_sepa) 
            VALUES (%s, %s, %s, %s, %s, %s, %s, %s)
            """
            values = (
                row['id_comercio'],
                row['id_bandera'],
                row['comercio_cuit'],
                row['comercio_razon_social'],
                row['comercio_bandera_nombre'],
                row['comercio_bandera_url'],
                row['comercio_ultima_actualizacion'],
                row['comercio_version_sepa']
            )
            try:
                cursor.execute(sql, values)
                connection.commit()
            except Error as e:
                print(f"Error al insertar: {e}")
        
        cursor.close()
        connection.close()

# Ruta al archivo CSV
load_csv_to_db('~/Documents/data/comercio.csv')