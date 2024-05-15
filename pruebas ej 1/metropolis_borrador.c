// metropolis borrador.c



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>





// Función para generar un número aleatorio entre 0 y L-1
int generarNumeroAleatorio(int L) {
    // Semilla para la función rand() basada en el tiempo actual
    
    
    // Generar un número aleatorio entre 0 y L-1
    int numAleatorio = rand() % L;
    
    
    return numAleatorio;
}









int main() {
    srand(time(NULL));
    
    int L = 10;
    int N = pow(10,4); // Número de repeticiones
    int iteracion;

    int i; // componentes del elemento a voltear
    int j;

    for (iteracion = 0; iteracion < N; iteracion++) {
        i = generarNumeroAleatorio(L);
        j = generarNumeroAleatorio(L);
        printf("\ni = %d\n", i);
        printf("\nj = %d\n", j);
        
        //printf("\n%d\n", generarNumeroAleatorio(L));
    }

    return 0;
}



