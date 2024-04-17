#include <stdio.h>
#include <locale.h>

void main(){
    int maior, menor, meio, valor1, valor2, valor3;

    scanf("%d",&valor1);    
    scanf("%d",&valor2);    
    scanf("%d",&valor3);

    maior=valor1;

    if(maior<valor2){
        maior=valor2;
    }
    if(maior<valor3){
        maior=valor3;
    }

    menor=valor1;
    if(menor>valor2){
        menor=valor2;
    }
    if(menor>valor3){
        menor=valor3;
    }
    meio=valor1;

    if((meio=menor)||(meio=maior)){
        menor=valor2;
    }

    if((meio=menor)||(meio=maior)){
        menor=valor3;
    }
    
    printf("%d ",menor);
    printf("%d ",meio);
    printf("%d\n",maior);
    printf("%d ",maior);
    printf("%d ",meio);
    printf("%d\n",menor);

}