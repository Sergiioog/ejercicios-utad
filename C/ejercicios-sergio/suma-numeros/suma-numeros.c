/*
Escriba un programa en el que se declaren tres variables, a, b y c y se asigne a esas variables los valores 5, 7 y 9 respectivamente. 

El programa deberá entonces calcular su suma y mostrar el resultado. 

Modifíquelo para que los valores de las variables sean introducidos por el usuario.
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
	
	int a = 5;
	int b = 7;
	int c = 9;
	
	printf("La suma de las variables a, b y c es: %d \n", a+b+c);
	
	printf("Introduzca ahora los valores para las variables a b y c \n");
	
	printf("Valor de a:\n");
	scanf("%d", &a);
	
	printf("Valor de b:\n");
	scanf("%d", &b);
	
	printf("Valor de c:\n");
	scanf("%d", &c);
	
	printf("La suma de las variables introducidas por el usuario es: %d \n", a+b+c);
	return 0;
}