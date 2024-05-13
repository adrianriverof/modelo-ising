

#include <stdio.h>
#include <stdlib.h>

int main() {
    int L;
    
    // Pedir al usuario que introduzca el tamaño de la matriz
    printf("Introduce el tamaño de la matriz: ");
    scanf("%d", &L);

    if (L <= 0) {
        printf("El tamaño debe ser un entero positivo.\n");
        return 1;
    }

    // Asignar memoria dinámicamente para la matriz
    int **matriz = (int **)malloc(L * sizeof(int *));
    if (matriz == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    for (int i = 0; i < L; i++) {
        matriz[i] = (int *)malloc(L * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Error al asignar memoria.\n");
            // Liberar la memoria asignada previamente
            for (int j = 0; j < i; j++) {
                free(matriz[j]);
            }
            free(matriz);
            return 1;
        }
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
