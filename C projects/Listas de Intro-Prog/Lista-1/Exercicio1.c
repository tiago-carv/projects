#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b, c;

    printf("Digite os valores de a e b:\n");
    scanf("%d %d", &a, &b);

    c=a-b;
    printf("O valor da diferença de a e b é: %d \n", c);
    return 0;
}
