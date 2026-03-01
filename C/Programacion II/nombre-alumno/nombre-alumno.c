/*
Escribir por pantalla el nombre completo de un alumno en formato <nombre> <primer apellido> <segundo apellido>
El nombre completo en formato <apellido1> <apellido2>, <nombre> se pasa desde el main
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){

	/*char *nombre = argv[1];
	char *apellido1 = argv[2];
	char *apellido2 = argv[3];*/
	
	char letra;
	char apellidos[200];
	char *nombre;
	int contArray = 0;
		
	for(int i = 1; i < argc; i++) {
		int j = 0;
		letra = argv[i][j];
		
		while(letra != '\0'){
			//printf("Letra: %c\n", letra);			
			if(letra == ','){
				nombre = argv[i+1];
				exit;
			}else{
				if(letra == ' '){
					apellidos[contArray] = ' ';
				}else{
					apellidos[contArray] = letra;

				}
			}
				
			contArray++;
			j++;
			letra = argv[i][j];
			
		}
		
	}
	apellidos[contArray++] = '\0';
	
	printf("El nombre es %s \n", nombre);
	printf("Los apellidos son %s ", apellidos);
	
	//printf("El nombre y apellidos del usuario es: %s %s %s", nombre, apellido1, apellido2);
	return 0;
}