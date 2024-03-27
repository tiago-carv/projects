#include <stdio.h>

void main(){
    int a, b, c, maior;
    printf("Digite um valor inteiro:");
    scanf("%d",&a);
    printf("Digite um valor inteiro:");
    scanf("%d",&b);
    printf("Digite um valor inteiro:");
    scanf("%d",&c);
    maior = (a>b)&&(a>c)? a:((b>c)&&(b>a)? b:c);

    printf("O maior é %d\n", maior); 
    
}