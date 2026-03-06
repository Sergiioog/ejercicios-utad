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

typedef struct {
	char nombre[10];
	int potencia; //Revisar logica para potencia negativa
	char elemento[5];
	int vida;
	int energia; //Revisar que está inicializada a 500J
} Mago;

void ensenaMenu();
int main(int argc, char* argv[]){
	
	//1. Introducimos parámetros por argv y verificamos si son correctos en cuanto a cantidad y sintaxis
	
	if(argc != 4){
		printf("Numero incorrecto de argumentos.");
		return 1;
	}
	
	char nombreUsuario1[10];
	char ataqueUsuario1[10];
	char elementoUsuario1[50];
	
	char nombreUsuario2[50];
	char ataqueUsuario2[10];
	char elementoUsuario2[50];
	
	char energia [10];
	
	char buffer[200];
	int pos = 0;
	
	//Variables de la palabra 1 string 1
	int contadorDePalabras = 0;
	int contLetrasPrimeraPalabra = 0; 
	int finPalabra1;
	
	//Variables de la palabra 2 string 1
	int inicioSegundaPalabra;
	int contLetrasSegundaPalabra = 0; 
	int finPalabra2;
	
	//Variables de la palabra 3 string 1
	int inicioTerceraPalabra;
	int contLetrasTerceraPalabra = 0;
	int finPalabra3;
	
	//Variables de la palabra 1 string 2
	int inicioCuartaPalabra;
	int contLetrasCuartaPalabra = 0;
	int finPalabra4;
	
	//Variables de la palabra 2 string 2
	int inicioQuintaPalabra;
	int contLetrasQuintaPalabra = 0;
	int finPalabra5;
	
	//Variables de la palabra 3 string 2
	int inicioSextaPalabra;
	int contLetrasSextaPalabra = 0;
	int finPalabra6;
	
	//Variables de la última palabra
	int inicioSeptimaPalabra;
	int contLetrasSeptimaPalabra = 0;
		
	int firstSentenceCompleted = 0;
	int secondSentenceCompleted = 0;
	
	for(int i = 1; i < argc; i++){
        
		char *elemento = argv[i];
        for(int j = 0; elemento[j] != '\0'; j++){
			buffer[pos++] = elemento[j];
		}
        buffer[pos++] = ' '; //Añadimos espacio al buffer por cada elemento para poder iterar y sacar el 3 valor del string (elemento)
    }
	
    buffer[pos] = '\0';

    for(int j = 0; buffer[j] != '\0'; j++){
		
        if(buffer[j] == ',' || (contadorDePalabras == 5 && buffer[j] == ' ')){
			contadorDePalabras++;

			if(contadorDePalabras == 1 && firstSentenceCompleted == 0){
				for(int inicioPrimeraPalabra = 0; buffer[inicioPrimeraPalabra] != ','; inicioPrimeraPalabra++){
					nombreUsuario1[contLetrasPrimeraPalabra++] = buffer[inicioPrimeraPalabra];
				}
				nombreUsuario1[contLetrasPrimeraPalabra] = '\0';
				finPalabra1 = contLetrasPrimeraPalabra + 1;
				
			}else if(contadorDePalabras == 2){
				for(inicioSegundaPalabra = finPalabra1; buffer[inicioSegundaPalabra] != ','; inicioSegundaPalabra++){
					ataqueUsuario1[contLetrasSegundaPalabra++] = buffer[inicioSegundaPalabra];
				}
				ataqueUsuario1[contLetrasSegundaPalabra] = '\0';
				finPalabra2 = inicioSegundaPalabra + 1;
				
			}else if(contadorDePalabras == 3){
				for(inicioTerceraPalabra = finPalabra2; buffer[inicioTerceraPalabra] != ' '; inicioTerceraPalabra++){
					elementoUsuario1[contLetrasTerceraPalabra++] = buffer[inicioTerceraPalabra];
				} 
				
				elementoUsuario1[contLetrasTerceraPalabra] = '\0';
				finPalabra3 = inicioTerceraPalabra + 1;
				contadorDePalabras++; //Sumamos 1 al contador de palabras (comas) para que pueda leer el resto de palabras de los strings porque si no no lo va a leer debido al espacio (no hay coma)
				firstSentenceCompleted = 1;
			}
            
			if(contadorDePalabras == 4 && firstSentenceCompleted == 1){
				for(inicioCuartaPalabra = finPalabra3; buffer[inicioCuartaPalabra] != ','; inicioCuartaPalabra++){
					nombreUsuario2[contLetrasCuartaPalabra++] = buffer[inicioCuartaPalabra];
				}
				
				nombreUsuario2[contLetrasCuartaPalabra] = '\0';
				finPalabra4 = inicioCuartaPalabra + 1;
			
			}else if(contadorDePalabras == 5 && firstSentenceCompleted == 1){
				for(inicioQuintaPalabra = finPalabra4; buffer[inicioQuintaPalabra] != ','; inicioQuintaPalabra++){
					ataqueUsuario2[contLetrasQuintaPalabra++] = buffer[inicioQuintaPalabra];
				}
				
				ataqueUsuario2[contLetrasQuintaPalabra] = '\0';
				finPalabra5 = inicioQuintaPalabra + 1;

			}
		}
		
		if(buffer[j] == ' '){
			if(contadorDePalabras == 6 && firstSentenceCompleted == 1){
				while(buffer[finPalabra5] != ' ' && buffer[finPalabra5] != '\0'){
					elementoUsuario2[contLetrasSextaPalabra++] = buffer[finPalabra5++];
				}
				elementoUsuario2[contLetrasSextaPalabra] = '\0';
				finPalabra6 = finPalabra5 + 1;
				secondSentenceCompleted = 1;
				contadorDePalabras++;
			}
		
			if(contadorDePalabras == 7 && firstSentenceCompleted && secondSentenceCompleted){

				for(inicioSeptimaPalabra = finPalabra6; buffer[inicioSeptimaPalabra] != ' ' && buffer[inicioSeptimaPalabra] != '\0'; inicioSeptimaPalabra++){
					energia[contLetrasSeptimaPalabra++] = buffer[inicioSeptimaPalabra];
				}

				energia[contLetrasSeptimaPalabra] = '\0';
				secondSentenceCompleted = 0;
				break;  
			}
		}
		
	}
	
	//printf("Nombre de usuario 1-> %s \n", nombreUsuario1);
	//printf("Ataque de usuario 1-> %s \n", ataqueUsuario1);
	//printf("Elemento de usuario 1-> %s \n", elementoUsuario1);
	//printf("Nombre de usuario 2-> %s \n", nombreUsuario2);
	//printf("Ataque de usuario 2-> %s \n", ataqueUsuario2);
	//printf("Elemento de usuario 2-> %s \n", elementoUsuario2);
	//printf("Energia -> %s\n", energia);

		
	//2. Inicializamos struct de magos
	
	Mago magoPersona;
	Mago magoMaquina;
	
	for(int letraNombre = 0; letraNombre < 10; letraNombre++){
		//Revisar cortar longitud de nombre cuando se sobrepasa 
		magoPersona.nombre[letraNombre] = nombreUsuario1[letraNombre];
		magoMaquina.nombre[letraNombre] = nombreUsuario2[letraNombre];
	}
	magoPersona.nombre[10] = '\0'; 
	magoMaquina.nombre[10] = '\0';
	
	printf("Mago persona nombre -> %s \n", magoPersona.nombre);
	printf("Mago maquina nombre -> %s \n", magoMaquina.nombre);
	
	//3. Creación del panel e introducción del mismo en un bucle
		//ensenaMenu();

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
