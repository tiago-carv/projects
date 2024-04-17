#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    int lado[3];
    for (int i = 0; i < 3; i++){
        printf("Digite a medida do lado %d:",i+1);
        scanf("%d",&lado[i]);
    }
    

    if(((lado[0]+lado[1]) >= lado[2]) && ((lado[1]+lado[2]) >= lado[0]) && ((lado[0]+lado[2]) >= lado[1])){
        printf("Os lados formam um triângulo\n");
        if((lado[2] == lado[1])&&(lado[1] == lado[2])){
            printf("Os lados formam um triângulo equilátero\n");
        }
        else{
            printf("Os lados não formam um triângulo equilátero");
        }
    }
    else{
        printf("Os lados não formam um triângulo");
    }
    printf("\n");

    return 0;
}

