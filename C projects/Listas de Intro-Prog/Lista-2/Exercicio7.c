#include <stdio.h>

void main(){
    int valor, aux[3];

    scanf("%d",&valor);

    for(int i=0;i<3;i++){
        aux[i] = valor%10;
        valor = valor/10;
    }
    for(int i=0;i<3;i++){
        printf("%d",aux[i]);
    }
    printf("\n");
}