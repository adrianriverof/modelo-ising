#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"



// Definición de la función para guardar la matriz en un archivo de texto
void guardarMatrizEnArchivo(int **matriz, int n) {
    FILE *archivo;
    archivo = fopen("matriz.txt", "w"); // Abre el archivo para escritura

    if (archivo != NULL) {
        
        // Escribe los elementos de la matriz en el archivo
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                fprintf(archivo, "%d ", matriz[i][j]);
            }
            fprintf(archivo, "\n");
        }

        fclose(archivo); // Cierra el archivo
        printf("Matriz guardada en el archivo 'matriz.txt'.\n");
    } else {
        printf("Error al abrir el archivo.\n");
    }
}



// Función para inicializar la matriz con números aleatorios
void inicializarMatriz(int **matriz, int L) {
    srand(time(NULL)); // Inicializa la semilla aleatoria
    int numeroAleatorio;

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            numeroAleatorio = rand();
            matriz[i][j] = (numeroAleatorio < RAND_MAX / 2) ? 1 : -1;
        }
    }
}

// Función para imprimir la matriz
void imprimirMatriz(int **matriz, int L) {
    printf("Matriz de ceros de tamaño %dx%d:\n", L, L);
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}



// Función principal
int main() {
    int L; // Tamaño de la matriz

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

    // Inicializar la matriz con números aleatorios
    inicializarMatriz(matriz, L);

    // Imprimir la matriz
    imprimirMatriz(matriz, L);

    guardarMatrizEnArchivo(matriz, L);

    printf("%d ", matriz[0][0]);

    // Liberar la memoria asignada dinámicamente
    for (int i = 0; i < L; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
