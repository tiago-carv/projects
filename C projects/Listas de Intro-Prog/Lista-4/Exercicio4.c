#include <stdio.h>
#include <locale.h>

int main(){

	int n;
	float soma=0;

	scanf("%d",&n);

	for(int i=1; i<=n;i++){
		soma+= 1 / (float)(i*i);
	}

	printf("%f\n",soma);
	return 0;
}
