#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


void imprimirProgreso(float progreso) {
    int barLength = 20;
    printf("[");
    int progressLength = (int)(progreso * barLength);
    for (int i = 0; i < barLength; i++) {
        printf(i < progressLength ? "=" : " ");
    }
    printf("] %.0f%%\r", progreso * 100);
    fflush(stdout); // Limpiar el buffer de salida para imprimir inmediatamente
}

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
    return rand() % L;
}



// Función principal
int main() {


    printf("=====================================\n");
    printf("             Ejercicio 3             \n");
    printf("=====================================\n\n");


    //tabla de salida
    float tabla_salida[11][2];

    //semilla
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

    // Asignar memoria dinámicamente para la matriz
    int **matriz = (int **)malloc(L * sizeof(int *));
    for (int i = 0; i < L; i++) {
        matriz[i] = (int *)malloc(L * sizeof(int));
    }


    // Inicializar la matriz con números aleatorios
    inicializarMatriz(matriz, L);

    

    // vamos cambiando la temperatura
    int iteracion_T = 0;
    for (T = 1.25; T <= 2.25; T += 0.1 ){
        
        printf("\n\nCalculando m para 5000 casos de T = %.2f\n\n", T);

        // grabamos el valor de la temperatura
        tabla_salida[iteracion_T][0] = T;
        tabla_salida[iteracion_T][1] = 0; 
        

        int iteracion_para_media;
        float m_media = 0;

        for (iteracion_para_media = 0; iteracion_para_media < 5000; iteracion_para_media++){
            
            //mostramos progreso del contaje
            imprimirProgreso((float)(iteracion_para_media+1) / 5000);
            
            
            
            //VOLTEAMOS
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
                }

            }
            

            // calculamos m 
            float m = 0;
            int sum = 0;

            for (int i = 0; i < L; i++) {
                for (int j = 0; j < L; j++) {
                    sum += matriz[i][j];
                }
            }

            m = (float)sum / 100;

            //esta m contribuye a la media global
            m_media += fabs(m)/5000;
        }
    }



    // guardamos la tabla en un archivo de salida
    FILE *archivo;
    archivo = fopen("tabla_salida_ej_3.txt", "w"); // Abre el archivo para escritura

    if (archivo != NULL) {
        
        // Escribe los elementos de la tabla en el archivo
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 2; j++) {
                fprintf(archivo, "%f ", tabla_salida[i][j]);
            }
            fprintf(archivo, "\n");
        }

        fclose(archivo); // Cierra el archivo
        printf("\n\n\nTabla guardada en el archivo 'tabla_salida_ej_3.txt'.\n");
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

 