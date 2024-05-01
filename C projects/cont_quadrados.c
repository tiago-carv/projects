#include <stdio.h>
#include <locale.h>
int num_quadrados_internos(int num);
int main(){
    setlocale(LC_ALL,"Portuguese");
    int N, a;
    
    printf("Digite o tamanho do quadrado:");
    scanf("%d",&N);
    a = num_quadrados_internos(N);
    printf("O número de quadrados dentro de desse quadrado de lado %d é %d\n", N, a);

    return 0;
}

int num_quadrados_internos(int num){
    int quantidade=0;
    for(int i = 1 ; i <= num; i++){
        quantidade += (num-i+1)*(num-i+1);
    }
    return quantidade;
}
