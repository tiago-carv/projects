#include <stdio.h>

void main  (){
    int a, b, diferenca;

    printf("Digite um número:");
    scanf("%d", &a);
    printf("Digite outro número:");
    scanf("%d", &b);

    diferenca = (a>b)? a-b:b-a;

    printf("%d\n", diferenca);
}