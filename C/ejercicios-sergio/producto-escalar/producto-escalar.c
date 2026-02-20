/*
Desarrollar un programa que calcule el producto escalar y el producto vectorial de
los vectores v1=<1,2,3> y v2=<3,2,1>.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int coordX;
	int coordY;
	int coordZ;
} Vector;

int main(int argc, char* argv[]) {
	
	Vector vector1;
	Vector vector2;
	
	vector1.coordX = 1;
	vector1.coordY = 2;
	vector1.coordZ = 3;
	vector2.coordX = 3;
	vector2.coordY = 2;
	vector2.coordZ = 1;
	
	int scalarProduct = (vector1.coordX * vector2.coordX) + (vector1.coordY * vector2.coordY) + (vector1.coordZ * vector2.coordZ);
	
	printf("El primer vector v1 es -> <1,2,3> y el segundo vector es -> <3,2,1> \n");
	printf("El producto escalar es %d \n", scalarProduct);
	return 0;
}