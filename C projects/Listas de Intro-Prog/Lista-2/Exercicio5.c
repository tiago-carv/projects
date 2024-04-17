#include <stdio.h>
#include <locale.h>

void main(){

    setlocale(1, "Portuguese");
    float fahrenheit, kelvin, fahrenheit_p_celsius, kelvin_p_celsius;

    printf("Digite  um temperatura Fahrenheit:");
    scanf("%f", &fahrenheit);
    printf("Digite  um temperatura Kelvin:");
    scanf("%f", &kelvin);
    fahrenheit_p_celsius = 5*(fahrenheit-32)/9;
    kelvin_p_celsius = kelvin -273.15;

    printf("%.2f\n",fahrenheit_p_celsius);
    printf("%.2f\n",kelvin_p_celsius);
}