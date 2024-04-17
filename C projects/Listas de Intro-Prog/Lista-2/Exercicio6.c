#include <stdio.h>
#include <locale.h>

void main(){
    int valor, aux[4];

    scanf("%d",&valor);

    for(int i=0;i<4;i++){
        aux[i] = valor%10;
        valor = valor/10;
    }
    for(int i=0;i<4;i++){
        printf("%d",aux[i]);
    }
    printf("\n");
}