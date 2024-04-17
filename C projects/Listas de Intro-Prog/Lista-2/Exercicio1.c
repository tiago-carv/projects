#include <stdio.h>
#include <locale.h>

void main(){
    float raio, altura,pi=3.14192;
    setlocale(1, "Portuguese");

    printf("Digite o raio:");
    scanf("%f",&raio);
    printf("Digite a altura:");
    scanf("%f",&altura);

    float Volume=altura*pi*raio*raio;
    printf("O volume é igual à %f\n" ,Volume);
}