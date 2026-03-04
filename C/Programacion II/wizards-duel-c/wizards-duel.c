/*
Programa que simule un duelo de magos (usuario y máquina).
-------------------------------------------------------------

El programa deberá además permitir mostrar la energía en distintas unidades mediante una función de conversión.

El programa se ejecutará desde línea de comandos de la siguiente forma:
./magos.exe Gandalf,20,fuego Saruman,15,hielo kJ

El programa recibirá tres argumentos:
	1. Datos del mago del usuario en formato: NOMBRE,POTENCIA,ELEMENTO
	2. Datos del mago de la máquina en el mismo formato.
	3. Unidad para mostrar la energía: "J" o "kJ"

Cada mago tendrá:
	• Nombre (hasta 10 caracteres)
	• Potencia (entero positivo)
	• Elemento (fuego o hielo)
	• Vida (inicialmente 100)
	• Energía (inicialmente 500 J)

El combate se desarrolla por turnos hasta que uno de los magos quede sin vida (vida ≤ 0).

En cada turno el usuario podrá elegir:
1. Atacar
	o Consume 100 J.
	o El daño se calculará mediante la función obligatoria calcular_danio().
	o Si el mago no tiene suficiente energía para atacar, se mostrará un mensaje de error y se deberá elegir otra opción.

2. Recargar energía
	o Recupera 150 J (no puede superar los 500 J la energía del mago).

3. Mostrar estado
	o Muestra vida y energía (la energía se mostrará en la unidad indicada por el tercer argumento usando la función convertir_energia()).

La máquina actuará con probabilidad:
	• 60% atacar (si tiene energía suficiente; en caso contrario recargará)
	• 40% recargar

Para la toma de decisiones de la máquina deberá utilizarse aleatoriedad (rand()), inicializada adecuadamente.

Deben utilizarse las estructuras, enumerados (y otros tipos si se consideran necesarios) para modelar los datos del problema.

Funciones obligatorias
1. Conversión de energía:
	double convertir_energia(ConversionInfo_t conversion);

La estructura de conversión deberá incluir:
	• el dato a convertir
	• la unidad de entrada
	• la unidad de salida

Equivalencia:
• 1 kJ = 1000 J

2. Cálculo de daño:
	int calcular_danio(Mago_t atacante);

La función devolverá el daño causado según el elemento:
• FUEGO → potencia + 5
• HIELO → potencia * 2
*/


//Nombre del alumno: Sergio García
//Asignatura: Introducción a la Programación II
//Fecha: 03/03/2026

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

void ensenaMenu();
int main(int argc, char* argv[]){
	
	//1. Introducimos parámetros por argv y verificamos si son correctos en cuanto a cantidad y sintaxis
	
	if(argc != 4){
		printf("Numero incorrecto de argumentos.");
		return 1;
	}
	
	char nombreUsuario1[50];
	char ataqueUsuario1[10];
	char elementoUsuario1[50];
	
	char nombreUsuario2[50];
	char ataqueUsuario2[10];
	char elementoUsuario2[50];
	
	char energia [10];
	
	for(int i = 1; i < argc; i++){
		char *entrada = argv[i];
		char cont = 0;
		char numeroBucle = 0;
		char buffer[200];
		
		for(int j = 0; entrada[j] != ' ' && entrada[j] != '\0'; j++){
			printf("entrada[j] -> %c \n", entrada[j]);
			
			if(entrada[j] == ','){
				printf("Coma encontrada \n");
				cont++;
				if(cont == 1 && numeroBucle == 0){
					for(int a = 0; a < j; a++){
						printf("Letra -> %c ", entrada[a]);
						nombreUsuario1[a] = entrada[a];
					}
					printf("Primera coma encontrada \n");
				}
			}
		}
		
		//printf("Entrada -> %s\n", entrada);
	}
	
	printf("Nombre de usuario -> %s \n", nombreUsuario1);
	
	/*for(int i = 1; i < argc; i++){
		
		char *entrada = argv[i];
		char buffer[100];
		char index = 0;
		
		for(int j = 0; entrada[j] != '\0'; j++){
			
			//Revisar por que no vuelve cuando encuentra una ,
			if(entrada[j] != ','){
				buffer[index] = entrada[j];
				index++;
			}else {
				buffer[index] = '\0';
			}
			
		}
		
		printf("buffer -> %s ",  buffer);
	}*/
	
	//ensenaMenu();
	
	
	//printf("Primer parametro -> %s \n Segundo parametro -> %s \n Tercer parametro -> %s", primerArgumento, segundoArgumento, tercerArgumento);
	
	//2. Inicializamos struct de magos
	
	//3. Creación del panel e introducción del mismo en un bucle
	
	//4. Inicialización de las funciones obligatorias por cada opción + energia
	
	//5. Inicialización de función random para el ataque de la maquina
	
	//6. Resto de lógica

	return 0;
}

void ensenaMenu(){
	printf("1) atacar \n");
	printf("2) recargar energia \n");
	printf("3) mostrar estado \n");
}
