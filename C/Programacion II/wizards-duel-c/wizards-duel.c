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

