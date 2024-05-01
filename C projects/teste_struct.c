#include <stdio.h>
#include <locale.h>

int Fat(int Numero);

int main(){
	int N;
	
	printf("Digite um valor inteiro:\n");
	scanf("%d",&N);
	
	int k = Fat(N);
	printf("%d\n",k);

	return 0;
}

int Fat(int Numero){
	int Fatorial=1;
	switch(Numero){
		case 1:
			Fatorial=1;
		break;
		case 2:
			Fatorial=2;
		break;
		default:
			Fatorial=Numero*Fat((Numero-1));
		break;
	}
	return Fatorial;
}
