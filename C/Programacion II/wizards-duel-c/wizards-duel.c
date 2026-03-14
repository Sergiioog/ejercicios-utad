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

1. Atacar -> HECHO
	o Consume 100 J. -> HECHO
	o El daño se calculará mediante la función obligatoria calcular_danio(). -> HECHO
	o Si el mago no tiene suficiente energía para atacar, se mostrará un mensaje de error y se deberá elegir otra opción. -> HECHO

2. Recargar energía
	o Recupera 150 J (no puede superar los 500 J la energía del mago). -> HECHO

3. Mostrar estado
	o Muestra vida y energía (la energía se mostrará en la unidad indicada por el tercer argumento usando la función convertir_energia()). -> TODO: Mostrar en KJ

La máquina actuará con probabilidad:
	• 60% atacar (si tiene energía suficiente; en caso contrario recargará)
	• 40% recargar

Para la toma de decisiones de la máquina deberá utilizarse aleatoriedad (rand()), inicializada adecuadamente.

Deben utilizarse las estructuras, enumerados (y otros tipos si se consideran necesarios) para modelar los datos del problema.

Funciones obligatorias
1. Conversión de energía: -> HECHO
	double convertir_energia(ConversionInfo_t conversion); -> HECHO

La estructura de conversión deberá incluir: -> HECHO
	• el dato a convertir -> HECHO 
	• la unidad de entrada -> HECHO
	• la unidad de salida -> HECHO

Equivalencia:
• 1 kJ = 1000 J -> HECHO

2. Cálculo de daño: -> HECHO
	int calcular_danio(Mago_t atacante); -> HECHO

La función devolverá el daño causado según el elemento: -> HECHO
• FUEGO → potencia + 5 -> HECHO
• HIELO → potencia * 2 -> HECHO
*/


//Nombre del alumno: Sergio García
//Asignatura: Introducción a la Programación II
//Fecha: 03/03/2026

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <stdlib.h>


typedef struct {
	double datoAConvertir;
	char unidadEntrada[10];
	char unidadSalida[10];
} ConversionInfo_t;

typedef struct {
	char nombre[10];
	int potencia; 
	char elemento[6];
	int vida;
	double energia;
} Mago_t;

double convertir_energia(ConversionInfo_t conversion);
int calculaAtaqueMaquina();
void ensenaMenu();
int calcular_danio(Mago_t atacante);
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
	
	char unidadEnergia [10];
	
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
					unidadEnergia[contLetrasSeptimaPalabra++] = buffer[inicioSeptimaPalabra];
				}

				unidadEnergia[contLetrasSeptimaPalabra] = '\0';
				secondSentenceCompleted = 0;
				break;  
			}
		}
		
	}
		
	//-------------------- 2. Inicializamos struct de magos -------------------- 
	
	Mago_t magoPersona;
	Mago_t magoMaquina;	

	for(int letraNombre = 0; letraNombre < 10; letraNombre++){
		magoPersona.nombre[letraNombre] = nombreUsuario1[letraNombre];
		magoMaquina.nombre[letraNombre] = nombreUsuario2[letraNombre];
	}
	magoPersona.nombre[10] = '\0'; 
	magoMaquina.nombre[10] = '\0';
	
	magoPersona.potencia = atoi(ataqueUsuario1);
	magoMaquina.potencia = atoi(ataqueUsuario2);
	
	if(magoPersona.potencia <= 0 || magoMaquina.potencia <= 0){ 
		printf("Potencia igual o menor 0 \n");
		return 1;
	}
	
	for(int letraElemento = 0; letraElemento < 6; letraElemento++){
		magoPersona.elemento[letraElemento] = elementoUsuario1[letraElemento];
		magoMaquina.elemento[letraElemento] = elementoUsuario2[letraElemento];
	}
	
	magoPersona.elemento[6] = '\0';
	magoMaquina.elemento[6] = '\0';
	
	int esFuego1 = (magoPersona.elemento[0] == 'f' &&
					magoPersona.elemento[1] == 'u' &&
					magoPersona.elemento[2] == 'e' &&
					magoPersona.elemento[3] == 'g' &&
					magoPersona.elemento[4] == 'o' &&
					magoPersona.elemento[5] == '\0');

	int esHielo1 = (magoPersona.elemento[0] == 'h' &&
					magoPersona.elemento[1] == 'i' &&
					magoPersona.elemento[2] == 'e' &&
					magoPersona.elemento[3] == 'l' &&
					magoPersona.elemento[4] == 'o' &&
					magoPersona.elemento[5] == '\0');

	if(!esFuego1 && !esHielo1){
		printf("Elemento de mago 1 invalido. Usa 'fuego' o 'hielo'\n");
		return 1;
	}

	int esFuego2 = (magoMaquina.elemento[0] == 'f' &&
					magoMaquina.elemento[1] == 'u' &&
					magoMaquina.elemento[2] == 'e' &&
					magoMaquina.elemento[3] == 'g' &&
					magoMaquina.elemento[4] == 'o' &&
					magoMaquina.elemento[5] == '\0');

	int esHielo2 = (magoMaquina.elemento[0] == 'h' &&
					magoMaquina.elemento[1] == 'i' &&
					magoMaquina.elemento[2] == 'e' &&
					magoMaquina.elemento[3] == 'l' &&
					magoMaquina.elemento[4] == 'o' &&
					magoMaquina.elemento[5] == '\0');

	if(!esFuego2 && !esHielo2){
		printf("Elemento de mago 2 invalido. Usa 'fuego' o 'hielo'\n");
		return 1;
	}
		
	//------------ Inicialización de vida ------------
	magoPersona.vida = 100;
	magoMaquina.vida = 100;
	
	//------------ Inicialización y Conversión de energía ------------
	ConversionInfo_t energiaMagos;
	energiaMagos.datoAConvertir = 500;
	
	if (unidadEnergia[0] == 'J' && unidadEnergia[1] == '\0') { //Comprobamos en base a si es J o kJ

		energiaMagos.unidadEntrada[0] = 'J';
		energiaMagos.unidadEntrada[1] = '\0';

		energiaMagos.unidadSalida[0] = 'k';
		energiaMagos.unidadSalida[1] = 'J';
		energiaMagos.unidadSalida[2] = '\0';

	} else if (unidadEnergia[0] == 'k' && unidadEnergia[1] == 'J' && unidadEnergia[2] == '\0') {

		energiaMagos.unidadSalida[0] = 'J';
		energiaMagos.unidadSalida[1] = '\0';

		energiaMagos.unidadEntrada[0] = 'k';
		energiaMagos.unidadEntrada[1] = 'J';
		energiaMagos.unidadEntrada[2] = '\0';

	}else {

		printf("Unidad no permitida, usa J o kJ \n");
		return 1;

	}

	magoPersona.energia = convertir_energia(energiaMagos);
	magoMaquina.energia = convertir_energia(energiaMagos);
	
	/*double costeAtaque;
	double limiteEnergia;
	double recarga;

	if(unidadEnergia[0] == 'k'){
		costeAtaque = 0.1;
		limiteEnergia = 0.5;
		recarga = 0.15;
	} else {
		costeAtaque = 100;
		limiteEnergia = 500;
		recarga = 150;
	}

	ConversionInfo_t energiaMagos;
	energiaMagos.datoAConvertir = 500; // partimos de 500J
	energiaMagos.unidadEntrada[0] = 'J';
	energiaMagos.unidadEntrada[1] = '\0';
	energiaMagos.unidadSalida[0] = unidadEnergia[0];
	energiaMagos.unidadSalida[1] = unidadEnergia[1];
	energiaMagos.unidadSalida[2] = '\0';

	magoPersona.energia = convertir_energia(energiaMagos); 
	magoMaquina.energia = convertir_energia(energiaMagos);*/
			
	//3. Creación del panel e introducción del mismo en un bucle
	
	int respuesta;
	int userNameChecked = 0;
	int magoDano = 0;
	int turnoValido = 0;
	int diferencia;

	while(magoPersona.vida > 0 && magoMaquina.vida > 0){
		turnoValido = 0; //Se resetea al inicio de cada iteracion

		if(userNameChecked == 0){
			printf("Turno de %s \n", magoPersona.nombre);
		}else {
			printf("Turno de %s \n", magoMaquina.nombre);
		}
		
		ensenaMenu();
		scanf("%d", &respuesta);
		
		switch(respuesta){
			case 1:
			
				if(userNameChecked == 0){  
					magoDano = calcular_danio(magoPersona);
					
					if((int)magoPersona.energia < magoDano){
						printf("El mago %s no tiene suficiente energia para atacar \n", magoPersona.nombre);
					}else{
						printf("%s ataca y causa %d de danio\n", magoPersona.nombre, magoDano);
						magoPersona.energia = magoPersona.energia - magoDano;  // se resta en la unidad correcta
						magoMaquina.vida = magoMaquina.vida - magoDano; 
						turnoValido = 1;
					}
					
				}else{
					
					int probabilidadAtaque = calculaAtaqueMaquina();
					
					if(probabilidadAtaque == 1){
						magoDano = calcular_danio(magoMaquina);
					
						if((int)magoMaquina.energia < magoDano){
							printf("El mago %s no tiene suficiente energia para atacar \n", magoMaquina.nombre);
						}else{
							printf("%s ataca y causa %d de danio\n", magoMaquina.nombre, magoDano);
							magoMaquina.energia = magoMaquina.energia - magoDano;
							magoPersona.vida = magoPersona.vida - magoDano; 
							turnoValido = 1;
						}
					}else{
						printf("El mago %s ha decidido NO atacar \n", magoMaquina.nombre);
						
						magoMaquina.energia = magoMaquina.energia + 150;
						if((int)magoMaquina.energia > 500){
							diferencia = (int)magoMaquina.energia - 500;
							magoMaquina.energia = (int)magoMaquina.energia - diferencia;
						}
						turnoValido = 1;
					}
					
				}
				break;
				
			case 2:
				diferencia = 0;
				
				if(userNameChecked == 0){
					
					magoPersona.energia = magoPersona.energia + 150;
					
					if((int)magoPersona.energia > 500){
						diferencia = (int)magoPersona.energia - 500;
						magoPersona.energia = (int)magoPersona.energia - diferencia;
						printf("El mago %s ha alcanzado el limite maximo de energia: %.1f J\n", magoPersona.nombre, magoPersona.energia);
					
					}else{
						printf("El mago %s ha recargado energia. Energia actual: %.1f J\n", magoPersona.nombre, magoPersona.energia);					
					
					}
					
				
				}else{
					
					magoMaquina.energia = magoMaquina.energia + 150;
					
					if((int)magoMaquina.energia > 500){
						diferencia = (int)magoMaquina.energia - 500;
						magoMaquina.energia = (int)magoMaquina.energia - diferencia;
						printf("El mago %s ha alcanzado el limite maximo de energia: %.1f J\n", magoMaquina.nombre, magoMaquina.energia);
					
					}else{
						printf("El mago %s ha recargado energia. Energia actual: %.1f J\n", magoMaquina.nombre, magoMaquina.energia);					
					}
				}
				
				turnoValido = 1;
				break;
				
			case 3:				
				printf("--- estado ---\n");
				printf("nombre: %s | vida: %d | energia: %.0f | elemento: %s | potencia: %d \n", magoPersona.nombre, magoPersona.vida, magoPersona.energia, magoPersona.elemento, magoPersona.potencia);
				printf("nombre: %s | vida: %d | energia: %.0f | elemento: %s | potencia: %d \n", magoMaquina.nombre, magoMaquina.vida, magoMaquina.energia, magoMaquina.elemento, magoMaquina.potencia);
				printf("--------------\n");
				turnoValido = 1;
				break;
				
			default:
				printf("Opcion no valida\n");
				break;
		}

		if(turnoValido == 1){
			userNameChecked = (userNameChecked == 0) ? 1 : 0; //Ternario, por eficiencia usado en vez de if else anidado
		}
	}
	
	printf("=== fin del duelo ===\n");
	if(magoPersona.vida == 0){
		printf("ganador: %s\n", magoMaquina.nombre);
	}else{
		printf("ganador: %s\n", magoPersona.nombre);
	}
	
	//5. Inicialización de función random para el ataque de la maquina
	
	return 0;
}

//TODO: Revisar logica para cuando la unidad es kJ modificar la energia en el programa


//4. Inicialización de las funciones obligatorias por cada opción + energia

double convertir_energia(ConversionInfo_t conversion){
	
	double energiaInicial = conversion.datoAConvertir;
	
	if(conversion.unidadEntrada[0] == 'k' && conversion.unidadEntrada[1] == 'J' && conversion.unidadEntrada[2] == '\0'){
		energiaInicial = conversion.datoAConvertir / 1000.0;
	}

	return energiaInicial;
}

void ensenaMenu(){
	printf("-----------------------\n");
	printf("1) atacar \n");
	printf("2) recargar energia \n");
	printf("3) mostrar estado \n");
	printf("-----------------------\n");
}

int calculaAtaqueMaquina(){
	
	int prob = rand() % 100 + 1;
	int ataque = 0;
	
	if(prob >= 40){
		printf("La máquina decide atacar -> %d \n", prob);
		ataque = 1;
	}else{
		printf("La máquina decide NO atacar -> %d \n", prob);
	}
	
	return ataque;
}

int calcular_danio(Mago_t atacante){
		
	int energiaAtacante = 0; 
	
	if(atacante.elemento[0] == 'f' 
	&& atacante.elemento[1] == 'u' 
	&& atacante.elemento[2] == 'e' 
	&& atacante.elemento[3] == 'g' 
	&& atacante.elemento[4] == 'o' 
	&& atacante.elemento[5] == '\0'){
		energiaAtacante = atacante.potencia + 5;
	}else{
		energiaAtacante = atacante.potencia * 2;
	
	}
	
	return energiaAtacante;	
}

