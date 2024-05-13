#include <stdio.h>
#include <stdlib.h>


//INTERESANTE: fíjate como usa aquí la entrada en una sola línea con lo del uso


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <tamaño>\n", argv[0]);
        return 1;
    }

    int L = atoi(argv[1]); // Convertir el argumento a entero
    // atoi = "ascii to integer"

    if (L <= 0) {
        printf("El tamaño debe ser un entero positivo.\n");
        return 1;
    }

    // Crear la matriz de tamaño LxL e inicializarla con ceros
    int matriz[L][L];
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

    return 0;
}
