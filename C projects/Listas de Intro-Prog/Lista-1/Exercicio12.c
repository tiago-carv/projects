#include <stdio.h>

void main(){
    int X ,Y;

    printf("Digite o valor de x:");
    scanf("%d", &X);
    printf("Digite o valor de x:");
    scanf("%d", &Y);

    (X%Y==0)? printf("%d é multiplo de %d\n", X ,Y):printf("%d não é multiplo de %d\n", X ,Y);

}