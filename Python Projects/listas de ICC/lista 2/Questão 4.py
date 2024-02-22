#divisores
import math as math

a = int(input('Escreva um número inteiro:'))

def div(k):
    set = {1}
    for i in range(2,(math.isqrt(k)+1)):
        if (k%i==0):
            set.add(i)
            set.add(k//i)
    set.add(k)
    lista = list(set)
    lista.sort()
    return(lista)

def ehperfeito(k):
    soma=0
    for i in range(len(div(k))):
        soma=soma+div(k)[i]
    soma-=k
    if soma==k:
        return 'O número é perfeito'
    else:
        return 'O número não é perfeito'

n = int(input('Escreva um número para começar:'))

while (n!=0):
    ehperfeito(n)
    n = int(input('Escreva outro número ou zero para parar:'))