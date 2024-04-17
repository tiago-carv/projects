#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    float minutos, preço;

    printf("Quantos minutos foram:");
    scanf("%f",&minutos);
    if(minutos <= 3){
        preço = 0.75;
    }
    else{
        preço = 0.75 + minutos*0.26;
    }

    printf("O preço é %.2f\n", preço);
}