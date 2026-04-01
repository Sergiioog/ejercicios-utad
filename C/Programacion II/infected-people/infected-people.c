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

typedef struct {
	int fila;
	int columna;
	int dia;
} evento_t;

typedef struct {
	evento_t *histInfectados;
	int cantidad;
	int capacidad;
} historial_t;

void muestraMenu();
char** crearCiudad(int n);
void rellenaCiudad(char** ciudad, int n, char valor);
void liberaCiudad(char** ciudad, int n);
void infectarPersona(char** ciudad, int n, historial_t* historial, int fila, int col,int diaActual); 
void muestraCiudad(char** ciudad, int n);
void insertaEvento(historial_t* historial, evento_t nuevoEvento);
int main(int argc, char* argv[]){
	
	//1 Pasamos el tamaño de la matriz n x n por argv, mediante la funcion obligatoria char** crearCiudad(int n)
	
	int tamanoCiudad = atoi(argv[1]);
	int opcion;
	int filaUsuario = 0;
	int columnaUsuario = 0;
	historial_t historialInfectados;
	historialInfectados.cantidad = 0;
	historialInfectados.capacidad = 0;
	historialInfectados.histInfectados = NULL;
	
	if(argc != 2){
		printf("Numero de argumentos incorrectos.\n");
		return 1;
	}
	
	char ** ciudad = crearCiudad(tamanoCiudad);

	//2 Rellenamos la matriz con personas sanas mediante void rellenaCiudad(char** ciudad, int n, char valor) y void liberaCiudad(char** ciudad, int n);
	
	rellenaCiudad(ciudad, tamanoCiudad, 'S');
	
	//3 Iniciamos focos de infección manualmente, para ello implementaremos la función: void infectarPersona(char** ciudad, int n, historial_t* historial, int fila, int col,int diaActual);
	//  que pedirá la fila y columna de la persona a infectar (I) por consola al usuario y guardará el evento de infección en caso de que la persona a infectar esté sana (S).
	
	//4 Tenemos en cuenta que persona ha sido infectada pasando de S -> I y guardando un registro [fila,columna,dia]
	//  Creamos estructura que almacene dinámicamente todos los eventos de infección, que contendrá un array dinámico que deberá crecer con cada nueva infección. void insertaEvento(historial_t* historial, evento_t nuevoEvento);
	//  y void liberaHistorial(historial_t* historial);
	
	
	
	//6 Añadimos logica para avanzar dias void avanzarDia(char** ciudad, int n, historial_t* historial, int diaActual);
	
	//7 Revision para que las nuevas infecciones del dia no provoquen nuevas infecciones en el mismo dia
	
	printf("Bienvenido, seleccione una opcion: \n");
	while(1){
		muestraMenu();
		scanf("%d", &opcion);
		switch(opcion){
			case 1:
				//TODO: Añadir validaciones para cuando no son numeros los que se introducen
				printf("Por favor, inserte la fila:\n");
				scanf("%d", &filaUsuario);
				if(filaUsuario < 0 || filaUsuario >= tamanoCiudad){
					printf("Tamano de fila superior o inferior a tamano de fila de matriz, saliendo...\n");
					return 1;
				}
				
				printf("Por favor, inserte la columna:\n");
				scanf("%d", &columnaUsuario);
				if(columnaUsuario < 0 || columnaUsuario >= tamanoCiudad){
					printf("Tamano de columna superior o inferior a tamano de columna de matriz, saliendo...\n");
					return 1;
				}
				
				infectarPersona(ciudad,tamanoCiudad, &historialInfectados,filaUsuario,columnaUsuario, 1); //TODO: Revisar logica para el dia actual + historial_t
				break;
			case 2:
				printf("Opcion 2 seleccionada\n");
				break;
			case 3:
				muestraCiudad(ciudad,tamanoCiudad);
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

char** crearCiudad(int n){
	//1.1 Creamos array dinamico de n x n
	char **ciudad = (char**)malloc(sizeof(char)* n);
	
	if(ciudad == NULL){
		printf("Fallo creando matriz dinamica, memoria insuficiente.\n");
		return NULL;
	}
	
	for(int i = 0; i < n;  i++){
		ciudad[i] = (char*)malloc(sizeof(char)* n);
		if(ciudad[i] == NULL){
			printf("Fallo creando columna de matriz dinamica, memoria insuficiente.\n");
			return NULL;
		}
	}
	
	return ciudad;
}

void rellenaCiudad(char** ciudad, int n, char valor){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){	
			ciudad[i][j] = valor;
			printf("[%c]", ciudad[i][j]);
		}
		printf("\n");
	}
}

void liberaCiudad(char** ciudad, int n){
	for(int i = 0; i < n; i++){
		free(ciudad[i]);
	}
	free(ciudad);
};

void infectarPersona(char** ciudad, int n, historial_t* historial, int fila, int col,int diaActual){
	//  que pedirá la fila y columna de la persona a infectar (I) por consola al usuario y guardará el evento de infección en caso de que la persona a infectar esté sana (S).
	
	if(ciudad[fila][col] == 'S'){
		ciudad[fila][col] = 'I';
		printf("Persona en [%d][%d] infectada", fila, col);	
		
		//Guardamos el evento llamado a la funcion insertaEvento
		evento_t nuevoEvento;		
		nuevoEvento.dia = diaActual;
		nuevoEvento.fila = fila;
		nuevoEvento.columna = col;
		insertaEvento(historial,nuevoEvento);
	}
};

void insertaEvento(historial_t* historial, evento_t nuevoEvento){
	
	historial->cantidad++;
	historial->histInfectados = (evento_t*)realloc(historial->histInfectados, historial->cantidad * sizeof(evento_t));
	historial->histInfectados[historial->cantidad - 1] = nuevoEvento;
	//TODO: Continuar con liberación + mostrar el historial opcion 4
};

void liberaHistorial(historial_t* historial){
	
};

void muestraCiudad(char** ciudad, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){		
			printf("[%c]", ciudad[i][j]);
		}
		printf("\n");
	}
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
