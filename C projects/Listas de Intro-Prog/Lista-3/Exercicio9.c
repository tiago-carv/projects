#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");

    scanf("%d",&N);
    int sequencia[N];

    for (int i=0 ;i < N; i++){
        printf("Digite %d valor:",i+1);
        scanf("%d",&sequencia[i]);
    }

    int soma = 0;

    for (int i=0 ;i < N; i++){
        if(sequencia[i]%2 == 0){
            soma = soma + sequencia[i];
        }
    }

    printf("A soma é %d\n",soma);

    return 0;
}