#include <stdio.h>
int potencia(int base, int pot);

int main(){
    int N, count=0, aux;

    printf("Digite um maior que zero");
    scanf("%d",&N);
    
    while(N != 0){
        aux=N;

        while(aux > 9){
            aux /= 10;
            count++;
        }

        printf("%d\n", aux);

        N = N - aux*potencia(10,count);

        count = 0;
    }

    return 0;
}

int potencia(int base, int pot){
    int resultado = 1;
    
    for (int i = 0; i < pot;i++){
        resultado *= base;
    }
    return resultado;
}