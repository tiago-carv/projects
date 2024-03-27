#include <stdio.h>

void main(){
    float r, altura, area, volume;

    printf("Digite o valor do raio da base do cilindro:");
    scanf("%f", &r);
    printf("Digite o valor da altura do cilindro: ");
    scanf("%f", &altura);    

    area= 2*3.1415*r*altura;
    volume = 3.1415*r*r*altura;

    printf("O área lateral do volume é :%.3f\n", area);
    printf("O volume lateral do volume é :%.3f\n", volume);
}