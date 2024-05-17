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
    // Semilla para la función rand() basada en el tiempo actual
    
    
    // Generar un número aleatorio entre 0 y L-1
    int numAleatorio = rand() % L;
    
    return numAleatorio;
}



// Función principal
int main() {

    printf("...");

    float tabla_salida[11][2];


    srand(time(NULL));

    const int k_B = 1;
    const int J = 1;

    int const L = 10; // Tamaño de la matriz
    float T; // Temperatura

    const int A = 5; // exponente
    int N = pow(10,A); // Numero de iteraciones
    int iteracion;
    
    int i_c; // componentes del elemento a voltear
    int j_c;

    printf("\n Empieza a alocatar");

    // Asignar memoria dinámicamente para la matriz
    int **matriz = (int **)malloc(L * sizeof(int *));
    for (int i = 0; i < L; i++) {
        matriz[i] = (int *)malloc(L * sizeof(int));
    }

    printf("\n Termina de alocatar");

    printf("\n Inicializa matriz");

    // Inicializar la matriz con números aleatorios
    inicializarMatriz(matriz, L);

    int iteracion_T = 0;

    printf("\n Empieza bucle");


    // vamos cambiando la temperatura
    for (T = 1.25; T <= 2.25; T += 0.1 ){

        printf("\n ahora mostramos la temperatura ");
        printf("\n Temperatura = %f", T);
        // grabamos el valor de la temperatura
        tabla_salida[iteracion_T][0] = T;
        tabla_salida[iteracion_T][1] = 0; 
        printf("\n debería haber terminado de mostrar la temperatura ");

        int iteracion_para_media;
        float m_media = 0;

        for (iteracion_para_media = 0; iteracion_para_media < 5000; iteracion_para_media++){
            
            //mostramos progreso del contaje
            if (iteracion_para_media % 100 == 0){
                printf(".");
                fflush(stdout);// vaciar el buffer de salida
            }
            
            
            //VOLTEAMOS
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

                }
            

            // calculamos m y la guardamos 
            float m = 0;
            int sum = 0;

            for (int i = 0; i < L; i++) {
                for (int j = 0; j < L; j++) {
                    sum += matriz[i][j];
                }
            }

            m = (float)sum / 100;

            m_media += m/5000;
            //printf("\nm = %f", m);
        }
        printf("\n m media: %f", m_media);
        tabla_salida[iteracion_T][1] = fabs(m_media);
        printf("iteración %d", iteracion_T);
        iteracion_T++ ;
    }



    




    // guardamos la tabla en un archivo de salida
    FILE *archivo;
    archivo = fopen("tabla_salida.txt", "w"); // Abre el archivo para escritura

    if (archivo != NULL) {
        
        // Escribe los elementos de la tabla en el archivo
        for (int i = 0; i < 11; i++) {
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




    // Liberar la memoria asignada dinámicamente
    for (int i = 0; i < L; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

 