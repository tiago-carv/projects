#include <stdio.h>

void main(){
    int ordem[3];
    scanf("%d", &ordem[0]);
    scanf("%d", &ordem[1]);
    scanf("%d", &ordem[2]);
    
    // menor = (a<b)&&(a<b)? a:((b<c)? b:c);
    int aux,menor;
    for (int i=0; i<2 ;i++){
        menor = i;
        for (int j=(i+1); j<3 ;j++){
            menor = (ordem[j] <ordem[menor])? j:menor;
        }
        if (i!= menor){
            aux=ordem[i];
            ordem[i] = ordem[menor];
            ordem[menor]=aux;
        }
    }

    (ordem[0]>=0)? printf("%d , %d e %d são positivos!\n", ordem[0], ordem[1], ordem[2]):(ordem[1]>=0)? printf("%d e %d são positivos!\n", ordem[1], ordem[2]):(ordem[2]>=0)? printf("%d é positivo!", ordem[2]):printf("Nenhum numero é positivo!");

}