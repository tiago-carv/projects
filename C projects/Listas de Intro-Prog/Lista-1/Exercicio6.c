#include <stdio.h>

int main(){
    int a, quadrado, cubo, quarta;
    scanf("%d", &a);
    quadrado=(a*a);
    cubo = (a*quadrado);
    quarta = (a*cubo);
    
    printf("Quadrado: %d\n cubo: %d\n quarta: %d\n", quadrado, cubo, quarta);

    return 0;
}