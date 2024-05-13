#include <stdio.h>

char palabro[100];

int main(){
    printf("\nBuenos días, escribe algo y yo lo repetire\n");
    scanf("%s", palabro);

    printf("\n ¡Ahí va!\n...\n");
    printf("%s", palabro);
    printf("\n FIN \n\n\n\n");

    return 0;
}