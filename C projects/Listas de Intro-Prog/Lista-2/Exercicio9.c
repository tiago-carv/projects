#include <stdio.h>
#include <locale.h>

void main(){
    float Graus, Rad_p_Graus, pi=3.14;

    printf("Digite a medida do ângulo em graus");
    scanf("%f", &Graus);

    Rad_p_Graus = (Graus*pi)/180;

    printf("A medida do ângulo em radianos é %.4f\n",Rad_p_Graus);
    
}