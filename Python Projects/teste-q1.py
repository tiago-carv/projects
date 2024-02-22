from random import*

N = int(input('N: '))
Vet=[]

for i in range(N):
	Vet.append(i)

print(Vet)

def embaralhar(A: list):
	A_embaralhada=[]
	for i in range(N):
		aux=Vet[i]
		k=randint(0,N-1)
		A[i]=A[k]
		A[k]=aux
		
	return A

Vet=embaralhar(Vet)
print(f'Após o seu algoritmo de embaralhamento = {Vet}')