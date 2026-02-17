#include <stdio.h>  
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// El programa1 va a recibir las señales que le mande el programa2

int processStopped = 0;

void stopProcess(int signal){
    processStopped = 1;
    printf("Proceso pausado, esperando relanzamiento.\n");
    while(processStopped){
        sleep(1);
    }
}

void resumeProcess(int signal){
    processStopped = 0;
    printf("Proceso reanudado.\n");
}

void killProcess(int signal){
    printf("Señal recibida, finalizando proceso.\n");
    exit(0);
}

int main() {
    
    int contador = 0;

    printf("El PID del proceso1 es: %d\n", getpid());

    signal(SIGUSR1, stopProcess);  // Pausar proceso con SIGUSR1
    signal(SIGUSR2, resumeProcess); // Reanudar proceso con SIGUSR2
    signal(SIGTERM, killProcess);   // Terminar proceso con SIGTERM

    while(1){
        if(!processStopped){
            printf("Calculando nomina del empleado %d ... Este proceso podría llevar tiempo\n", contador);
            contador++;
        }
        sleep(1.5);
    }
    
    return 0;
}   