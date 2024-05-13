#include <stdio.h>

char palabro[100];

int main(){
    printf("Buenos días, escribe algo y yo lo repetire");
    scanf("%s", palabro);

    printf("%s", palabro);

    return 0;
}