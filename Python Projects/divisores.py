#divisores
import math as math

a = int(input('Escreva um número inteiro:'))
list = [1]

def divisores(k):
    for i in range(2,(math.isqrt(k))):
            if (k%i==0):
                list.append(i)
                list.append(k//i)
    list.append(k)
    list.sort()
    print(list)


divisores(a)
