#include <stdio.h>

int main(){
    int balas, alunos, resto_de_balas, balas_por_aluno;

    printf("Digite o numero de alunos\n");
    scanf("%d", &alunos);
    printf("Digite o numero de balas\n");
    scanf("%d", &balas);

    resto_de_balas = balas%alunos;

    balas_por_aluno = (balas-resto_de_balas)/alunos;

    printf("Cada aluno vai receber: %d balas\n", balas_por_aluno);
    printf("O professor vai dicar com %d balas\n", resto_de_balas);

    return 0;
}