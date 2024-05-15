#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



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
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para generar un número aleatorio entre 0 y L-1
int generarNumeroAleatorio(int L) {
    // Semilla para la función rand() basada en el tiempo actual
    
    
    // Generar un número aleatorio entre 0 y L-1
    int numAleatorio = rand() % L;
    
    return numAleatorio;
}




// Función principal
int main() {

    srand(time(NULL));

    const int k_B = 1;
    const int J = 1;

    int L; // Tamaño de la matriz
    int T; // Temperatura
    int A; // exponente
    int N; // Numero de iteraciones
    int iteracion;
    
    int i_c; // componentes del elemento a voltear
    int j_c;

    // Pedir al usuario que introduzca el tamaño de la matriz
    printf("Introduce el tamaño de la matriz: ");
    scanf("%d", &L);

    if (L <= 0) {
        printf("El tamaño debe ser un entero positivo.\n");
        return 1;
    }
    // Pedir al usuario que introduzca la Temperatura
    printf("Introduce la Temperatura: ");
    scanf("%d", &T);

    if (L <= 0) {
        printf("La temperatura debe ser un entero positivo.\n");
        return 1;
    }

    // Pedir al usuario que introduzca el exponente
    printf("Introduce el exponente del número de pasos: ");
    scanf("%d", &A);

    if (L <= 0) {
        printf("El exponente debe ser un entero positivo.\n");
        return 1;
    }
    
    N = pow(10,A);

    // Asignar memoria dinámicamente para la matriz
    int **matriz = (int **)malloc(L * sizeof(int *));
    for (int i = 0; i < L; i++) {
        matriz[i] = (int *)malloc(L * sizeof(int));
    }


    // Inicializar la matriz con números aleatorios
    inicializarMatriz(matriz, L);

    // Imprimir la matriz
    printf("\nmatriz original\n");
    imprimirMatriz(matriz, L);

   
    for (iteracion = 0; iteracion < N; iteracion++) {
        // escogemos componentes del elemento a voltear
        i_c = generarNumeroAleatorio(L);
        j_c = generarNumeroAleatorio(L);
        // elemento: matriz[i_c][j_c]
        printf("\ni = %d\n", i_c);
        printf("\nj = %d\n", j_c);

        //printf("\nelemento = %d", matriz[i_c][j_c]);

        float sum = 0;

        // sumar teniendo en cuenta los bordes
        if (i_c == 0){
            sum += matriz[L-1][j_c];
        } 
        else{
            sum += matriz[i_c-1][j_c];
        }
        if (i_c == L-1){
            sum += matriz[0][j_c];
        }
        else{
            sum += matriz[i_c+1][j_c];
        }

        if (j_c == 0){
            sum += matriz[i_c][L-1];
        }
        else{
            sum += matriz[i_c][j_c-1];
        }
        if (j_c == L-1){
            sum += matriz[i_c][0];
        }
        else{
            sum += matriz[i_c][j_c+1];
        }

        float deltaH = 2 * J* matriz[i_c][j_c] * sum ;

        printf("\nDeltaH = %f\n ¿es menor que cero? %d", deltaH, (deltaH<0));

        if (deltaH < 0){
            matriz[i_c][j_c] *= -1; // volteamos el elemento
        }
        else{
            float r = (float)rand() / ((float)RAND_MAX + 1);
            float P = exp(-deltaH / (k_B * T));

            if (r<P){
                matriz[i_c][j_c] *= -1; // volteamos el elemento
            }
        }


        
    }

   
   
   
   
    guardarMatrizEnArchivo(matriz, L);

    // Liberar la memoria asignada dinámicamente
    for (int i = 0; i < L; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
