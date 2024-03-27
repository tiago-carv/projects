#include <stdio.h>

int main(){
    float num1, num2, media;
    printf("Escreva as entradas para média:\n");
    scanf("%f %f", &num1, &num2);
    media = (num1+num2)/2;
    printf("A média é igual a: %.2f \n", media);


    return 0;
}