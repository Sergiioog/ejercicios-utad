/*
Se desea implementar un programa que simule la propagación de una infección en una ciudad representada mediante una matriz cuadrada dinámica.

La ciudad se modela como una matriz cuadrada de tamaño N x N, donde cada celda representa una persona.

El tamaño N se pasará como parámetro de entrada por argc/argv.

Cada celda puede contener uno de los siguientes valores:
	• S → Persona sana
	• I → Persona infectada
	• R → Persona recuperada

El programa permite iniciar focos de infección y avanzar días, propagándose automáticamente la infección según unas reglas definidas.

Se debe implementar una función que cree un array dinámico bidimensional de tamaño N x N: char** crearCiudad(int n); OBLIGATORIO

Se pide también implementar las funciones para rellenar la matriz creada anteriormente con personas sanas (S) y para liberar la memoria correspondiente:
void rellenaCiudad(char** ciudad, int n, char valor);
void liberaCiudad(char** ciudad, int n);

Cada vez que una persona pase de sana a infectada, se debe guardar un registro con:
	• fila
	• columna
	• día en que se infectó

Además, se debe crear una estructura que almacene dinámicamente todos los eventos de infección. Esta estructura deberá contener un array dinámico que deberá crecer con cada nueva infección.

Se pide implementar:
	void insertaEvento(historial_t* historial, evento_t nuevoEvento);
	void liberaHistorial(historial_t* historial);

El programa permitirá iniciar focos de infección manualmente, para ello se debe implementar la función: void infectarPersona(char** ciudad, int n, historial_t* historial, int fila, int col,int diaActual);
Esta función pedirá la fila y columna de la persona a infectar (I) por consola al usuario y guardará el evento de infección en caso de que la persona a infectar esté sana (S).

El programa permitirá avanzar días.
Al avanzar un día, se aplicarán las siguientes reglas:
	1. Toda persona sana ('S') que tenga al menos un vecino infectado (arriba, abajo, izquierda o derecha) pasara a infectada ('I').
	2. Todas las personas que estaban infectadas ('I') pasaran a recuperadas ('R').
	3. Todas las nuevas infecciones deberán registrarse en el historial dinámico indicando el día correspondiente.
	
La actualización debe realizarse correctamente para que las nuevas infecciones del día no provoquen infecciones adicionales en el mismo día.
Se recomienda utilizar una estructura auxiliar (por ejemplo, otra matriz) para realizar la actualización.

Pista: guardar en la matriz auxiliar las nuevas infecciones, después en el tablero actualizar a recuperado (R) las personas infectadas (I) y seguidamente volcar las personas infectadas de la matriz auxiliar en el tablero.

Se debe implementar:
	void avanzarDia(char** ciudad, int n, historial_t* historial, int diaActual);

El programa debe presentar un menú con las siguientes opciones:
1. Anadir foco de infección
2. Avanzar día
3. Mostrar ciudad
4. Mostrar historial de infecciones
5. Salir

Sólo está permitido el uso de las librerías stdio.h y stdlib.h. Está permitido el uso de la función atoi -> HECHO
*/

#include <stdio.h>
#include <stdlib.h>

void muestraMenu();
int main(int argc, char* argv[]){
	
	int opcion;
	
	printf("Bienvenido, seleccione una opcion: \n");
	while(1){
		muestraMenu();
		scanf("%d", &opcion);
		switch(opcion){
			case 1:
				printf("Opcion 1 seleccionada\n");
				break;
			case 2:
				printf("Opcion 2 seleccionada\n");
				break;
			case 3:
				printf("Opcion 3 seleccionada\n");
				break;
			case 4:
				printf("Opcion 4 seleccionada\n");
				break;
			case 5:
				printf("Opcion 5 seleccionada, saliendo... \n");
				return 0;
			default:
				printf("Opcion no valida, saliendo... \n");
				return 0;
		}
		
	}
	return 0;
}

void muestraMenu(){
	printf("-----------------------\n");
	printf("1. Anadir foco de infeccion\n");
	printf("2. Avanzar dia\n");
	printf("3. Mostrar ciudad\n");
	printf("4. Mostrar historial de infecciones\n");
	printf("5. Salir\n");
	printf("-----------------------\n");
}
