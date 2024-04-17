#include <stdio.h>
#include <locale.h>

void main(){
    int a;
    setlocale(LC_ALL,"Portuguese");

    printf("Digite um número:");
    scanf("%d",&a);

    if((a%5==0)||(a%3==0)){
        if(a%15==0){
            printf("O número é divisível por 5 e 3\n");
        }else{
            printf("O número é divisível por 5 ou 3 mas não pelos dois\n");
        }
    }else if(a%5==0){
        printf("O número não é divisível nem por 5 ou 3\n");
    }
}