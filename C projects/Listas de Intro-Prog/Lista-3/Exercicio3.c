#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    float a, b ,c;
    char op;

    printf("Digite a:");
    scanf("%f",&a);
    printf("Digite b:");
    scanf("%f",&b);
    printf("Digite c:");
    scanf("%f",&c);
    getchar();

    printf("a)a área do triângulo que tem a por base e b por altura.\n");
    printf("b)a área do círculo de raio c.\n");
    printf("c)a área do trapézio que tem a e b por bases e c por altura.\n");
    printf("d)a área do quadrado de lado b.\n");
    printf("e)a área do retângulo de lados a e b.\n");
    scanf("%c",&op);

    switch (op)
    {
    case 'a':
        printf("%.2f",(a*b)/2);
        break;
    case 'b':
        printf("%.2f",(c*c*3.14));
        break;
    case 'c':
        printf("%.2f",((a+b)*c)/2);
        break;
    case 'd':
        printf("%.2f",(b*b));
        break;
    case 'e':
        printf("%.2f",(a*b));
        break;
    default:
        printf("opção inválida");
        break;
    }
    printf("\n");
    return 0;
}