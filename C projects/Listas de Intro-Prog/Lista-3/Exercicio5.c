#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    float km_final, km_inicial, litros, consumo_p_litro;

    printf("Escreva o kilometro final");
    scanf("%f",&km_final);
    printf("Escreva o kilometro inicial");
    scanf("%f",&km_inicial);
    printf("Escreva o consumo");
    scanf("%f",&litros);

    consumo_p_litro = (km_final-km_inicial)/litros;
    printf("%f",consumo_p_litro);
    return 0;
}