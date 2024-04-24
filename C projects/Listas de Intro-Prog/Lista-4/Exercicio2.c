#include <stdio.h>
#include <locale.h>
int Verdadeiro(){
	return 1;
}
int main(){
	setlocale(LC_ALL,"Portuguese");
	int N, soma=0, soma_par=0, contador=0, contador_positivo=0, contador_par=0, maior=-32767, menor=32767;
	
	while(Verdadeiro()){
		scanf("%d",&N);
		if(N == -1){
			break;
		}
		contador++;
		soma+=N;
		if(N>0){
			contador_positivo++;
		}
		if(N%2==0){
			contador_par++;
			soma_par+=N;
		}
		if(maior<N){
            maior=N;
            }
		if(menor>N){
			menor=N;
		}
		
	}
	if(contador == 0){
		printf("Erro\n");
		return 1;
	}
	float media=soma/contador;
	printf("soma: %d\n", soma);
	printf("contador: %d\n", contador);
	printf("media: %.2f\n", media);
	if(contador_par != 0){
		int media_par=soma_par/contador_par;
		printf("media de pares:%d\n",media_par);
	}
	if(contador != 0){
		float percent_positivo=contador_positivo/contador;
		printf("porcentagem de positivos: %f\n", percent_positivo*100);
		printf("porcentagem dde negativos: %f\n", (1-percent_positivo)*100);
	}
}
