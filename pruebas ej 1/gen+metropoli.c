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

    int contador_volteos1 = 0;
    int contador_volteos2 = 0;
    int contador_no_volteados =0 ;


    srand(time(NULL));

    const int k_B = 1;
    const int J = 1;

    int L; // Tamaño de la matriz
    float T; // Temperatura
    int A; // exponente
    int N; // Numero de iteraciones
    int iteracion;
    
    int i_c; // componentes del elemento a voltear
    int j_c;

    // Pedir al usuario que introduzca el tamaño de la matriz
    printf("Introduzca L: ");
    scanf("%d", &L);

    // Pedir al usuario que introduzca el exponente
    printf("Introduzca A: ");
    scanf("%d", &A);

    N = pow(10,A);

    // Pedir al usuario que introduzca la Temperatura
    printf("Introduzca T: ");
    scanf("%f", &T);


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
        
        //printf("\ni = %d\n", i_c);
        //printf("\nj = %d\n", j_c);

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

        //printf("\nDeltaH = %f\n ¿es menor que cero? %d", deltaH, (deltaH<0));

        if (deltaH < 0){
            matriz[i_c][j_c] *= -1; // volteamos el elemento
            contador_volteos1 += 1;
        }
        else{
            float r = (float)rand() / ((float)RAND_MAX + 1);
            float P = exp(-deltaH / (k_B * T));

            if (r<P){
                matriz[i_c][j_c] *= -1; // volteamos el elemento
                contador_volteos2 += 1;
            }
            else{
                contador_no_volteados += 1;

            }
        }


        
    }


   printf("\n\n__Contaje de volteos_\ncontador1= %d \n", contador_volteos1);
   printf("contador2= %d \n", contador_volteos2);
   printf("no volteados= %d \n", contador_no_volteados);

   printf("TOTAL= %d \n", (contador_no_volteados+contador_volteos1+contador_volteos2));
   
   // Imprimir la matriz procesada
    printf("\nmatriz procesada\n");
    imprimirMatriz(matriz, L);
   
    guardarMatrizEnArchivo(matriz, L);

    // Liberar la memoria asignada dinámicamente
    for (int i = 0; i < L; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
