#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    float distancia, litros, km_p_litro;

    printf("Digite a distancia percorrida:");
    scanf("%f",&distancia);
    getchar();
    printf("Digite os litros consumidos:"); 
    scanf("%f",&litros);
    getchar();

    km_p_litro = distancia/litros;

    if(km_p_litro < 8){
        printf("Venda o carro!\n");
    }
    else if((8 <= km_p_litro)&&(km_p_litro <= 14)){
        printf("Econômico\n");
    }
    else{
        printf("Super Econômico!\n");
    }
    
    return 0;
}