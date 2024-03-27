#include <stdio.h>

void main(){
    float salario_bruto, salario_liquido,desconto=0.15;

    printf("Digite o salário bruto:");
    scanf("%f", &salario_bruto);
    salario_liquido = salario_bruto - (salario_bruto*desconto);
    printf("O salário liquido é %.2f\n", salario_liquido);
}