#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    int N;

    scanf("%d",&N);

    for (int i=0;i<N;i++){
        if(i%7 == 0){
        printf("%d\n",2*i+1);
        }
    }
    return 0;
}