import math

def div(k: int) -> int:
    set = {1}
    for i in range(2,(math.isqrt(k)+1)):
        if (k%i==0):
            set.add(i)
            set.add(k//i)
    set.add(k)
    lista = list(set)
    lista.sort()
    return(lista)

def ehprimo(k: int):
    if len(div(k))==2:
        return True
    else:
        return False

print(ehprimo(int(input('Digite um número: '))))