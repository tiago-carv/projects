#divisores
import math as math

a = int(input('Escreva um número inteiro:'))
A = [1]

def divisores(k):
    for i in range(2,(math.isqrt(k))):
            if (k%i==0):
                A.append(i)
                A.append(k//i)
    A.append(k)
    A.sort()
    print(A)


divisores(a)
