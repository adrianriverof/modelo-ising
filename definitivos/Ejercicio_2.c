#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


// Función para inicializar la matriz con números aleatorios
void inicializarMatriz(int **matriz, int L) {
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
    return rand() % L;;
}




// Función principal
int main() {

    // semilla aleatoria
    srand(time(NULL)); 
    
    printf("=====================================\n");
    printf("             Ejercicio 2             \n");
    printf("=====================================\n\n");

    printf("Parámetros\n\n");



    int contador_10_4 = 0;
    float tabla_salida[1000][2];

    //constantes
    const int k_B = 1;
    const int J = 1;

    //parámetros
    int const L = 50; // Tamaño de la matriz
    float T; // Temperatura
    const int A = 7; // exponente
    int N = pow(10,A); // Numero de iteraciones

    int iteracion; // contador de iteraciones
    
    int i_c; // componentes del elemento a voltear
    int j_c;


    // Pedir al usuario que introduzca la Temperatura
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

   
    for (iteracion = 0; iteracion < N; iteracion++) {

        // escogemos componentes del elemento a voltear
        i_c = generarNumeroAleatorio(L);
        j_c = generarNumeroAleatorio(L);        


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

        // cuando sea múltiplo de 10^4
        if ( (iteracion % 10000 )== 0 ){

            //calculamos m
            float m = 0;

            int sum = 0;
            for (int i = 0; i < L; i++) {
                for (int j = 0; j < L; j++) {
                    sum += matriz[i][j];
                }
            }


            m = (float)sum / pow(50,2);



            // grabamos el valor de la iteracion
            tabla_salida[contador_10_4][0] = (float)iteracion;
            // grabamos el valor de m
            tabla_salida[contador_10_4][1] = fabs((float)m);

            //aumentamos el valor de contador de múltiplos de 10^4
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
        printf("\n\nTabla guardada en el archivo 'tabla_salida.txt'.\n\n");
    } else {
        printf("Error al abrir el archivo.\n");
    }




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
