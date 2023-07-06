# Proyecto de Portafolio en C++

Este repositorio contiene varios proyectos implementados en C++. A continuación, se proporciona una breve descripción de cada proyecto incluido en este portafolio.

## Árbol Multi-Camino 2-4
Este proyecto es una implementación de un árbol multi-camino 2-4. Se presenta un menú en inglés y las clases contienen comentarios en inglés. Las opciones del menú incluyen:

1. Insertar n enteros aleatorios.
2. Realizar 2n operaciones con probabilidad.
3. Imprimir en orden.
4. Ver el árbol nivel por nivel.
5. Insertar un elemento.
6. Eliminar un elemento.
7. Encontrar un elemento.
8. Manual de usuario.
0. Salir.

El proyecto incluye un manual que explica cada una de las opciones del menú con más detalle.

## Juego de la Torre de Hanoi con Templates, Nodos y Listas
Este proyecto es la conclusión de un examen de estructuras de datos en el que se implementó el juego de la Torre de Hanoi utilizando templates, nodos y listas. Al ejecutar la aplicación, se muestra el siguiente menú:

1. Ingresar al juego.
2. Mostrar el número mínimo de movimientos para ganar.
3. Mostrar el algoritmo completo paso a paso de la solución.
0. Salir.

Cuando se selecciona la opción 1, se inicia el juego y se muestra cada movimiento con los valores correspondientes. La opción 2 muestra el número mínimo de movimientos requeridos para ganar el juego, y la opción 3 muestra los pasos detallados para completar el juego con los movimientos mínimos.

## Banco con Manipulación de Datos en CSV
Este proyecto es la implementación de un banco donde los datos se reciben a través de un archivo CSV y se manipulan en diferentes estructuras de datos. El programa ofrece las siguientes opciones:

1. Encolar todos los clientes.
2. Encolar un cliente.
3. Atender los siguientes 5 clientes.
4. Mostrar el siguiente cliente a ser atendido.
5. Simulación de Atención de Clientes.
6. Agregar un Cliente Nuevo.
7. Salir.

Las operaciones mencionadas anteriormente se describen a continuación:

- **Encolar todos los clientes**: Esta opción lee los datos del árbol ABB/BST y los encola uno por uno en una cola prioritaria (priority queue) implementada como un montículo (heap). El montículo está ordenado de mayor a menor, según los porcentajes de influencia de cada cliente.

- **Encolar un cliente**: Esta opción permite ingresar el número de cédula de un cliente desde el teclado. Luego, busca los datos correspondientes en el árbol binario y los agrega a la cola prioritaria.

- **Atender los siguientes 5 clientes**: Esta opción muestra en orden de prioridad los siguientes 5 clientes de la cola prioritaria.

- **Mostrar el siguiente cliente a ser atendido**: Esta opción muestra únicamente el siguiente cliente con la prioridad más alta.

- **Simulación de Atención de Clientes**: Esta opción extrae y muestra en orden de prioridad TODOS los clientes que estén actualmente en la cola prioritaria. Al finalizar este proceso, la cola queda vacía.

- **Agregar un Cliente Nuevo**: Esta opción permite capturar todos los datos de un nuevo cliente desde la pantalla y lo agrega al árbol A

BB que contiene los datos de los clientes del banco.

- **Salir**: Esta opción recorre el árbol ABB y reconstruye el archivo CSV para almacenar los datos tal como están al momento de cerrar la aplicación. Es importante destacar que el sistema inicia con 100 clientes y solo se pueden agregar más clientes, por lo que al finalizar, el archivo de texto debe tener 100 o más datos si se han ingresado nuevos clientes.

Espero que este resumen te brinde una visión general de los proyectos incluidos en este portafolio. Cada proyecto está ubicado en una carpeta separada dentro del repositorio, donde encontrarás más detalles y la implementación completa de cada uno.
