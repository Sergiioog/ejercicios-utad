/*
Crear un programa de consola que muestre exactamente todos los argumentos recibidos por línea de comandos, 
incluido el nombre del ejecutable, indicando para cada uno su índice y su valor textual en el orden en que fueron proporcionados. 

Debe usar el prototipo de main que admite argumentos de línea de órdenes. 

Uso de int main(int argc, char *argv[]) o equivalente (char **argv).

Comprensión de que argc ≥ 1 y que todos los argumentos son cadenas.

Entrada por CLI: una secuencia de 0..N argumentos separados por espacios después del nombre del programa.

No lee stdin.

Los argumentos se tratan textualmente (no hay conversión numérica)
*/

#include <stdio.h>
#include <stdlib.h>
#define INVALID_INPUT() printf("Lo sentimos, el numero minimo de caracteres es invalido \n");

void main (int argc, char* argv[]) {
	
	if(argc > 1) {
		for(int i = 0; i < argc; i++) {
			printf("Argumento %d : %s\n", i, argv[i]);
		}
	}else {
		INVALID_INPUT();
	}
	
}