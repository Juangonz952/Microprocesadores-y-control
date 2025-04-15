#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// Esta función se ejecutará cuando llegue la señal SIGINT
void manejarCtrlC(int signo) {
    printf("\nInterrupción recibida (SIGINT). ¡Adiós!\n");
    exit(0);
}

int main() {
    // Asociamos la señal SIGINT con la función manejarCtrlC
    signal(SIGINT, manejarCtrlC);

    // Loop infinito hasta que el usuario presione Ctrl+C
    while (1) {
        printf("Trabajando... (presioná Ctrl+C para salir)\n");
        sleep(1);
    }

    return 0;
}
