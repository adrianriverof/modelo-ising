#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main() {
    
    srand(time(NULL)); // Inicializa la semilla aleatoria
    int numeroAleatorio; // para la selección de spin

    int L; // dimension que deberá meter manualmente




    // Pedir al usuario que introduzca el tamaño de la matriz
    printf("Introduce el tamaño de la matriz: ");
    scanf("%d", &L);

    if (L <= 0) {
        printf("El tamaño debe ser un entero positivo.\n");
        return 1;
    }


    // Asignar memoria dinámicamente para la matriz
    int **matriz = (int **)malloc(L * sizeof(int *));
    for (int i = 0; i < L; i++) {
        matriz[i] = (int *)malloc(L * sizeof(int));
    }

    // Inicializar la matriz con ceros
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            
            numeroAleatorio = rand();
            // Determina si el número aleatorio es mayor o menor que la mitad de RAND_MAX
            if (numeroAleatorio < RAND_MAX / 2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = -1;
            }
        }
    }

    // Imprimir la matriz
    printf("Matriz de ceros de tamaño %dx%d:\n", L, L);
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberar la memoria asignada dinámicamente
    for (int i = 0; i < L; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
