#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main() {
    int pid;
    int option;

    printf("Introduzca el PID del proceso receptor: \n");
    scanf("%d", &pid);

    // Menú de opciones
    printf("¿Qué desea hacer?\n");
    printf("1. Pausar el proceso\n");
    printf("2. Reanudar el proceso\n");
    printf("3. Salir (matar proceso)\n");
    scanf("%d", &option);

    // Procesar la opción seleccionada
    switch(option) {
        case 1:
            // Enviar señal SIGUSR1 para pausar el proceso
            if (kill(pid, SIGUSR1) == 0) {
                printf("El proceso con PID %d ha sido pausado.\n", pid);
            } else {
                perror("Ha habido un error al pausar el proceso");
            }
            break;

        case 2:
            // Enviar señal SIGUSR2 (id=12) para reanudar el proceso
            if (kill(pid, 12) == 0) {
                printf("El proceso con PID %d ha sido reanudado.\n", pid);
            } else {
                perror("Ha habido un error al reanudar el proceso");
            }
            break;

        case 3:
            if(kill(pid, SIGTERM) == 0){
                printf("Proceso %d killed, saliendo...\n", pid);
            }
            exit(0);
            break;

        default:
            printf("Opción no válida. Saliendo...\n");
            exit(1);
    }

    return 0;
}
