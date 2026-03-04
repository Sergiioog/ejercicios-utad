/*

Crear el DNI de un ciudadano concatenando un numero de 8 cifras que se le pasa como parámetro del main y la letra correspondiente

Para obterner la letra es necesario dividir el numero del DNI entre 23 y en lugar de calcular los decimales, nos fijaremos en el resto que ofrece la solución.

Luego comparar el resto con el codigo TRWAGMYFPDXBNJZSQVHLCKE

El numero obtenido marcara la posicion de la letra en el codigo.
Es decir, si el resto es 3, la letra del dni sera la W

*/


#include <stdlib.h>
#include <stdio.h>

int calculaNumero(int numero);

int main(int argc, char* argv[]){
	
	char letraFinal;
	char codigo[23] = "TRWAGMYFPDXBNJZSQVHLCKE";
	
	//Obtenemos el numero pasado por argv
	int numero = atoi(argv[1]);
	
	//Dividimos el numero (en funcion) entre 23 (modulo)
	int resto = calculaNumero(numero);
	
	//Nos fijamos en el resto
	printf("Resto %d \n", resto);

	//Comparamos con el codigo TRWAGMYFPDXBNJZSQVHLCKE
	//Obtenemos la letra en funcion del resto

	for(int i = 0; codigo[i] != '\0'; i++){
		if(i == resto){
			letraFinal = codigo[i];
		}
	}
	
	//Concatenamos y mostramos por consola
	char DNI[9];
	for(int j = 0; j <= 7; j++)
		DNI[j] = argv[1][j];
	}
	
	DNI[8] = letraFinal;
	DNI[9] = '\0';
	printf("DNI: %s", DNI);
	return 0;
}

int calculaNumero(int numero){
	int resultado = numero % 23;
	return resultado;	
}