#include <stdio.h>
#include <locale.h>

int main(){

    setlocale(1, "Portuguese");
    float fahrenheit, fahrenheit_p_celsius;

    printf("Digite  um temperatura Fahrenheit:");
    scanf("%f", &fahrenheit);
    fahrenheit_p_celsius = 5*(fahrenheit-32)/9;

    printf("%.4f\n",fahrenheit_p_celsius);

    return 0;
}