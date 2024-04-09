#include <stdio.h>

void main(){
    int horas,minutos,seg,seg_final;
    int aux1,aux2,aux3,aux4,aux5;

    scanf("%d",&horas);
    scanf("%d",&minutos);
    scanf("%d",&seg);
    scanf("%d",&seg_final);

aux1 = horas*3600;
aux2 = minutos*60;
int segundos_total = aux1+aux2+seg+seg_final;


int seg_novo = segundos_total%60;
int minutos_novo = (segundos_total-seg_novo)/60;
int horas_novo = (minutos_novo-minutos_novo%60)/60;

if(minutos_novo<10&&seg_novo<10){
    printf("%d:0%d:0%d\n",horas_novo%60,minutos_novo%60,seg_novo);
}else{
    if(minutos_novo<10){
    printf("%d:0%d:%d\n",horas_novo%60,minutos_novo%60,seg_novo);
    }else{
        if (seg_novo<10){
            printf("%d:%d:0%d\n",horas_novo%60,minutos_novo%60,seg_novo);
        }else{
        printf("%d:%d:0%d\n",horas_novo%60,minutos_novo%60,seg_novo);
        }
    }
}



}