
#include <stdio.h>


void impimirMatriz3x3(){
    // Declarar una matriz de 3x3
    int matriz[3][3];

    // Inicializar la matriz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = 0; // Puedes asignar cualquier valor aquí
        }
    }

    // Acceder a elementos de la matriz e imprimirlos
    printf("Matriz:\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}






void main() {
    impimirMatriz3x3();
}

