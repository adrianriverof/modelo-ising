#include <stdio.h>
#include <stdlib.h>




int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <tamaño>\n", argv[0]);
        return 1;
    }

    int L = atoi(argv[1]); // Convertir el argumento a entero

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
            matriz[i][j] = 0;
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
