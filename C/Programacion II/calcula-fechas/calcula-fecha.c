/*
Escriba un programa que muestre en la pantalla un mensaje de saludo, por ejemplo "Hola",
y luego muestre el mensaje "Por favor introduzca el año en que nació". 

El programa debe leer ese valor y almacenarlo en una variable de tipo entero llamada fecha.

Por último haga que el programa escriba la frase " Si usted nació en <valor de la fecha leída> este año cumple <edad calculada> años.

Es recomendable que vaya escribiendo el programa por pasos (mostrar saludo, pedir fecha, leer fecha,…) 
y compilándolo después de cada paso para comprobar que funciona.

*/


#include <stdio.h>
#include <stdlib.h>

void calculateYears(int fecha);

int main (int argc, char* argv[]){
	
	int fecha; 
	
	printf("Hola \n");
	printf("Por favor, introduzca el ano en que nacio: ");
	
	scanf("%d", &fecha);
	calculateYears(fecha);
	
	return 0;
}

void calculateYears(int fecha){
	
	int actualYear = 2026;
	int userYears = actualYear - fecha;
	
	printf("Si usted nacio en %d este ano cumple %d anos", fecha, userYears);
};