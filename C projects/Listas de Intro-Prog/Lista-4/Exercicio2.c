#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"Portuguese");
	int N, soma=0, soma_par=0, contador=0, contador_positivo=0, contador_par=0, maior=-32767, menor=32767;
	
	while(1){
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
	float media = (float)soma / contador;
	printf("soma: %d\n", soma);
	printf("contador: %d\n", contador);
	printf("media: %.2f\n", media);
	if(contador_par != 0){
		float media_par = (float)soma_par / contador_par;
		printf("media de pares:%.2f\n",media_par);
	}
	
	float percent_positivo = (float)contador_positivo / contador * 100.0f;
	printf("porcentagem de positivos: %.2f%%\n", percent_positivo);
	printf("porcentagem de negativos: %.2f%%\n", (100.0f - percent_positivo));
	

	return 0;
}
