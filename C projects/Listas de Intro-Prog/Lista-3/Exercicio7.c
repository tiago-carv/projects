#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    int valor,Valor_decomposto[5];
    int MS[5]={100,50,10,5,1};

    printf("Digite o valor:");
    scanf("%d",&valor);
    for(int i=0;i<5;i++){
        Valor_decomposto[i] = (valor - valor%(MS[i]));
        valor = valor%MS[i];
    }
    
    for(int i=0;i<5;i++){
        printf("%d moedas de %d\n",Valor_decomposto[i],MS[i]);
    }

    return 0;

}