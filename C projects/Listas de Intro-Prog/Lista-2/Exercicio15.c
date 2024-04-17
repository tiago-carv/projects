#include <stdio.h>
#include <locale.h>

int isAnobissexto(int ano);
int isDataValida(int dia, int mes, int ano);

int main(){
    setlocale(LC_ALL,"Portuguese");
    int dia, mes, ano;

    printf("Digite o dia: ");
    scanf("%d",&dia);
    printf("Digite o mes: ");
    scanf("%d",&mes);
    printf("Digite o ano: ");
    scanf("%d",&ano);
    
    if(isDataValida(dia,mes,ano) == 1){
        printf("Data Válida");
    }else{
        printf("Data Inválida");
    }
    printf("\n");
    return 0;   
} 

int isDataValida(int dia, int mes, int ano){
    if(dia <= 0 || mes <= 0 || mes > 12 || ano <= 0){ 
        return 0;
    }
    if(mes == 2){
        if(dia <= (29+isAnobissexto(ano))){
            return 1;
        }
    }
    if(mes<8){
        if(dia < (30+mes%2)){
            return 1;
        }
    }
    else{
        if(dia < (31-mes%2)){
            return 1;
        }
    }
    return 0;
}

int isAnobissexto(int ano){
    if((ano%400==0)||((ano%4==0)&&(ano%100!=0))){
        return 1;
    }else{
        return 0;
    }
}