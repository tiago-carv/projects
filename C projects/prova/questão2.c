#include <stdio.h>

int main(){
    int tam=1000,N[tam],k,count=0,soma=0;
    
    for(int i=0; i<=tam ;i++){
        N[i]=-1;
    }

    for(int i=0; i <=tam ;i++){
        scanf("%d", &k);
        if(k%2 == 0){
        N[i]=k;
        count+=1;
        }
    }

    k=0;
    int Pares[count];

    for(int i=0 ; i < count; i++){
        for(int j=k ; j < tam; j++){
            if(N[j]%2 == 0){
                Pares[i]=N[j];
                k=j+1;
                break;
            }
        }
    }

    float media = (float)soma/media;

    printf("%f",media);

    return 0;
}