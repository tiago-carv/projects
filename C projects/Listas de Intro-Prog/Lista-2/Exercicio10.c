#include <stdio.h>
#include <locale.h>

void main(){
    int ano;
    setlocale(1,"Portuguese");
    printf("Digite o ano");
    scanf("%d",&ano);

    if((ano%400==0)||((ano%4==0)&&(ano%100!=0))){
        printf("O ano é bissexto!");
    }else{
        printf("O ano não é bissexto!");
    }
    
}