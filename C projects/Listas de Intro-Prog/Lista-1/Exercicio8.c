#include <stdio.h>

int main(){
    int nota, i=0, soma=0, notas[]={10,10,10},pesos[]={2,3,5};


    for(i=0;i<3;i++){
        scanf("%d", &nota);
        notas[i]=nota;
        soma=soma+notas[i]*pesos[i];
    }
    soma=soma/10;
    printf("%d", soma);

    return 0;
}