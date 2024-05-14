#include <stdio.h>
#include <stdlib.h>
#include <time.h>



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

