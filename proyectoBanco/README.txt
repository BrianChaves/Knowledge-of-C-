Este es un proyecto concluido de un Banco donde se reciben datos por CSV ,y de ahi se manipulan
este va a tener las siguientes opciones al correr el programa.
1- Encolar todos los clientes
2- Encolar un cliente
3- Atender los siguientes 5 clientes
4- Mostrar el siguiente cliente a ser atendido
5- Simulación de Atención de Clientes
6- Agregar un Cliente Nuevo
7- Salir

La descripcion de las siguientes operaciones es:

Encolar todos los Clientes
Esta opción debe leer los datos del árbol ABB/BST en su totalidad, y de 1 en 1 los debe colocar en una
estructura de tipo Cola Prioritaria (Priority Queue) que debe estar montada sobre un montículo (Heap),
sin embargo, este montículo ordena de forma inversa a la convención, lo que significa que está ordenado
de mayor a menor (en la raíz está el valor más alto).
El criterio de ordenamiento está dado por los porcentajes de influencia para definir la prioridad del cliente,
según los porcentajes de influencia vamos a calcular un número entre 0 y 100, el cual es la llave (key) de
ordenamiento correspondiente.

Encolar un cliente
Esta opción debe recibir vía teclado un número de cédula, el cual se debe buscar en el árbol binario,
para que sus datos sean agregados a la Cola Prioritaria.

Atender los siguientes 5 clientes
Esta opción debe sacar y mostrar en pantalla en orden de prioridad los siguientes 5 clientes de la Cola
Prioritaria.

Mostrar el siguiente cliente a ser atendidos
Esta opción únicamente muestra el siguiente cliente con la prioridad más alta.

Simulación de Atención de Clientes
Esta opción extrae y muestra en pantalla en orden de prioridad TODOS los clientes que estén en ese momento en la Cola Prioritaria. Al final de este proceso la cola queda totalmente vacía.

Agregar un Cliente Nuevo
Esta opción captura vía pantalla todos los datos de un cliente nuevo y lo agrega al árbol ABB donde
se encuentran todos los datos de los clientes del banco.

Salir
Esta opción recorre el árbol ABB de sistema y construye nuevamente el archivo de texto separado por comas
para almacenar los datos, tal y como están al momento de cerrar la aplicación. Es importante que note que
el sistema inicia con 100 clientes, y solamente se puede agregar más clientes, por lo que el archivo de texto
al finalizar debe tener 100 o más datos, en caso de que se haya ingresado nuevos clientes.