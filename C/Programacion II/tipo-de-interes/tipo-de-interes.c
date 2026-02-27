/*

Escriba un programa que calcule el interés que se obtiene por un determinado dinero depositado en un banco. 
Para ello el programa preguntará por el capital inicial y por el tipo de interés.
*/

#include <stdlib.h>
#include <stdio.h>

float calculateInterest(float initialCapital, float interestType);

int main(int argc, char* argv[]) {
	
	float initialCapital;
	float interestType;
	
	printf("Bienvenido a la calculadora de interes.\n");
	printf("Por favor introduzca el capital inicial y el tipo de interes: \n");
	scanf("%f %f", &initialCapital, &interestType);
	
	int interest = calculateInterest(initialCapital, interestType);	
	printf("El interes seria de: %d euros\n", interest);
	return 0;
}

float calculateInterest(float initialCapital, float interestType){
	return (initialCapital * (interestType / 100)); 
}