#include <stdio.h>
#include <locale.h>

void main(){
    float Montante, valor1, valor2, valor3;
    setlocale(1, "Portuguese");

    printf("Digite o valor total do prêmio:");
    scanf("%f",&Montante);

    valor1 = 0.46*Montante;
    valor2 = 0.32*Montante;
    valor3 = Montante-(valor1+valor2);

    printf("O ganhador 1 vai receber %.2f\n",valor1);
    printf("O ganhador 2 vai receber %.2f\n",valor2);
    printf("O ganhador 3 vai receber %.2f\n",valor3);

}