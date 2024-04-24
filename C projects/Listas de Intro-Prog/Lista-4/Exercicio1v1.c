#include  <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    int N;

    printf("Difite o número de estrelas desejado:");
    scanf("%d", &N);

    for (int i=1;i<=N;i++){
        printf("*");
    }
    printf("\n");

    return 0;
}