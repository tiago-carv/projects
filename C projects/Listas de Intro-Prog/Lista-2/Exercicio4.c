#include <stdio.h>
#include <locale.h>

void main(){
    setlocale(1, "Portuguese");

    float largura, comprimento, preço_por_metro, valor;
    
    printf("Digite o valor da largura:");
    scanf("%f",&largura);
    printf("Digite o valor da comprimento:");
    scanf("%f",&comprimento);
    printf("Digite o valor da preço por metro:");
    scanf("%f",&preço_por_metro);

    valor = largura*comprimento*preço_por_metro;

    printf("O valor do %.2f\n",valor);
}