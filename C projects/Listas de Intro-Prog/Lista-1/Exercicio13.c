#include <stdio.h>

void main(){
    float n1, n2, n3, media;

    printf("Digite a nota 1:");
    scanf("%f",&n1);
    printf("Digite a nota 2:");
    scanf("%f",&n2);
    printf("Digite a nota 3:");
    scanf("%f",&n3);

    media = (n1+n2+n3)/3;

    (media>=7)? printf("Aprovado\n"):printf("Reprovado\n");
}