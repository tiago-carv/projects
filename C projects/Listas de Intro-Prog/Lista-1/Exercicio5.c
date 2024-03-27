#include <stdio.h>

int main(){
    float a,b,c,delta;
    
    printf("Digite os valores de a b e c respectivamente:");
    scanf("%f %f %f", &a, &b, &c);

    delta = b*b - 4*a*c;
    printf("%.2f", delta);

    return 0;
}