#include  <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    int N,i=1;

    printf("Difite o número de estrelas desejado:");
    scanf("%d", &N);

    do
    {
        printf("*");
        i++;
    } while (i<=N);
    printf("\n");

    return 0;
}