# TareaProgramada4-C16882
Hermes Josué Rojas Sancho

Este programa permite administrar de manera altamente basica una tienda en general, utiliza una interfaz de usuario basada en widgets la cual habilita al usuario a interactuar con la tienda. El programa permite asignar, editar la información general de la Tienda (Nombre, Dirección de internet, Dirección física y teléfono) y además permite agregar productos a la tienda(agregándolos a una lista) con su respectivo ID, nombre y cantidad de existencias, estos son atributos que se pueden editar.
Por otra parte, también tiene una función para guardar la información de esta tienda en un archivo binario como para cargar los datos desde un archivo hacia el programa.

Estructura de la informacion general de la tienda (en archivo binario):

| Campo              | Tamaño en bytes | Offset |
| ----------         | --------------- | ------ | 
| nombre             | 15              | 0  |
| direccion internet | 24              | 15 |
| direccion fisica   | 24              | 39 |
| telefono           | 8               | 63 |

Estructura de cada producto (en archivo binario):

| Campo              | Tamaño en bytes | Offset |
| ----------         | --------------- | ------ | 
| id                 | 4               | 0  |
| nombre             | 20              | 4  |
| existencias        | 4               | 24 |

Instrucciones para compilar y ejecutar el programa:

Debe haber una carpeta que contenga la biblioteca que se utilizó para el proyecto, que en este caso ya se encuentra en la carpeta del proyecto por defecto.
Debe entrar al ambiente de Qt Creator y abrir el proyect desde el menu Archivo. Luego el programa se compilará y ejecutará al presionar el botón de "RUN" en la parte inferior izquierda.

Se utilizó la versón 6.2.3 de Qt y la versión 7.0.2 de Qt Creator para desarrollar el programa.
