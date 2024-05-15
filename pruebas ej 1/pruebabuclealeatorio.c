#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void elegir_i(int i) {
    printf("Iteración %d: %d\n", i + 1, rand() % 100); // Supongamos que queremos números aleatorios entre 0 y 99
}

int main() {
    int N = 10; // Número de repeticiones
    int i;

    // Inicializar la semilla del generador de números aleatorios
    srand(time(NULL));

    for (i = 0; i < N; i++) {
        elegir_i(i);
    }

    return 0;
}