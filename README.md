# proyecto1B36853

Proyecto 1 B36853; Laboratorio de Programación; José Ricardo Soro

Instrucciones Makefile:

1. make: Compilacion general del proyecto
2. make run: Ejecucion del proyecto
3. make unittest: Compilacion de las Unit Test
4. make run_unittest: Ejecucion de las Unit Test
5. make times: compila y ejecuta las pruebas de tiempo y genera en carpeta principal un archivo de tiempos.
6. make stress: uno de los unit test pero este es ejecutado por aparte pues consiste en agregar nodos al arbol hasta que la memoria de la computadora no pueda poner mas.
6. make help: Muestra archivo de ayuda

Unit Tests:
Se realizan 4 pruebas unitarias al proyecto:
1. Pruebas positivas: Demuestran el correcto funcionamiento de cada funcion pública ante entradas correctas.
2. Pruebas Negativas: Demuestran que el programa no detiene su ejecución ante entradas incorrectas; sino que es capaz de continuar y reconocer los errores.
3. Estructura: Esta prueba crea un arbol pequeño y procede a imprimir la informacion de cada nodo para permitirle al usuario chequear que haya sido correctamente construido.
4. Stress Test: Es una prueba de Stress donde se agregan nodos hasta que la memoria de la computadora no pueda soportar más; esto para encontrar cuantos nodos se pueden tener cargados


Funciones:
1. insert():
2. createTree():
3. getSize(int *salida):
4. getHeight(int *salida):
5. salidasArbol():
6. limpiarMemoria():
