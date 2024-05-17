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
        printf("\n\nMatriz guardada en el archivo 'matriz.txt'.\n");
    } else {
        printf("\nError al abrir el archivo.\n");
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
            int numero = matriz[i][j];
            if (numero < 0){
                printf("--");
            }
            else{
                printf("++");
            }
            
        }
        printf("\n");
    }
}

int generarNumeroAleatorio(int L) {
    // devuelve un número aleatorio entre 0 y L-1
    return rand() % L;
}




// Función principal
int main() {

    // semilla aleatoria
    srand(time(NULL));

    printf("=====================================\n");
    printf("             Ejercicio 1             \n");
    printf("=====================================\n\n");

    printf("Parámetros\n\n");



    const int k_B = 1;
    const int J = 1;

    int L; // Tamaño de la matriz
    float T; // Temperatura
    int A; // exponente
    int N; // Numero de iteraciones
    int iteracion;
    
    int i_c; // componentes del elemento a voltear
    int j_c;


    printf("Introduzca tamaño L: ");
    scanf("%d", &L);

    printf("Introduzca exponente A: ");
    scanf("%d", &A);

    N = pow(10,A);

    printf("Introduzca temperatura T: ");
    scanf("%f", &T);

    printf("\n=====================================\n");


    // Asignar memoria dinámicamente para la matriz
    int **matriz = (int **)malloc(L * sizeof(int *));
    for (int i = 0; i < L; i++) {
        matriz[i] = (int *)malloc(L * sizeof(int));
    }

    // Inicializar la matriz con números aleatorios
    inicializarMatriz(matriz, L);


    // Imprimir la matriz
    printf("\nMatriz desordenada generada:\n\n-- : -1\n++ : +1\n\n");
    imprimirMatriz(matriz, L);

   
    for (iteracion = 0; iteracion < N; iteracion++) {
        // escogemos componentes del elemento a voltear
        i_c = generarNumeroAleatorio(L);
        j_c = generarNumeroAleatorio(L);
        

        float sum = 0;

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


        if (deltaH < 0){
            matriz[i_c][j_c] *= -1; // volteamos el elemento
        }
        else{
            float r = (float)rand() / ((float)RAND_MAX + 1);
            float P = exp(-deltaH / (k_B * T));

            if (r<P){
                matriz[i_c][j_c] *= -1; // volteamos el elemento
            }
            else{

            }
        }


        
    }   

    printf("\n\n=====================================\n\n");
    


   // Imprimir la matriz procesada
    printf("\nMatriz procesada\n\n");
    imprimirMatriz(matriz, L);
   
   // Guardar en archivo txt
    guardarMatrizEnArchivo(matriz, L);

    // Liberar la memoria asignada dinámicamente
    for (int i = 0; i < L; i++) {
        free(matriz[i]);
    }
    free(matriz);

    printf("\n=====================================\n");
    printf("           Fin del programa          \n");
    printf("=====================================\n");

    return 0;
}
