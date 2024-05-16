#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>






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


// Función para generar un número aleatorio entre 0 y L-1
int generarNumeroAleatorio(int L) {
    // Semilla para la función rand() basada en el tiempo actual
    
    
    // Generar un número aleatorio entre 0 y L-1
    int numAleatorio = rand() % L;
    
    return numAleatorio;
}




// Función principal
int main() {

    int contador_10_4 = 0;


    float tabla_salida[1000][2];


    srand(time(NULL));

    const int k_B = 1;
    const int J = 1;

    int const L = 50; // Tamaño de la matriz
    float T; // Temperatura
    const int A = 7; // exponente
    int N = pow(10,A);; // Numero de iteraciones
    int iteracion;
    
    int i_c; // componentes del elemento a voltear
    int j_c;

    // Pedir al usuario que introduzca la Temperatura
    printf("Introduzca T: ");
    scanf("%f", &T);

    printf("\n...recibido");


    // Asignar memoria dinámicamente para la matriz
    int **matriz = (int **)malloc(L * sizeof(int *));
    for (int i = 0; i < L; i++) {
        matriz[i] = (int *)malloc(L * sizeof(int));
    }


    // Inicializar la matriz con números aleatorios
    inicializarMatriz(matriz, L);


   
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

        if ( (iteracion % 10000 )== 0 ){
            //printf("  %d", iteracion);

            //calculamos m
            int m = 0;

            




            // grabamos el valor de la iteracion
            tabla_salida[contador_10_4][0] = (float)iteracion;
            // grabamos el valor de m
            tabla_salida[contador_10_4][1] = (float)m;

            contador_10_4++;


        }
        
    }





    // guardamos la tabla en un archivo de salida
    FILE *archivo;
    archivo = fopen("tabla_salida.txt", "w"); // Abre el archivo para escritura

    if (archivo != NULL) {
        
        // Escribe los elementos de la tabla en el archivo
        for (int i = 0; i < 1000; i++) {
            for (int j = 0; j < 2; j++) {
                fprintf(archivo, "%f ", tabla_salida[i][j]);
            }
            fprintf(archivo, "\n");
        }

        fclose(archivo); // Cierra el archivo
        printf("Tabla guardada en el archivo 'tabla_salida.txt'.\n");
    } else {
        printf("Error al abrir el archivo.\n");
    }

    printf("\nNúmero de salidas, tiene que ser 1000: %d\n\n\n", contador_10_4);



    // Liberar la memoria asignada dinámicamente
    for (int i = 0; i < L; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
