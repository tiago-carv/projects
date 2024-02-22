def swap(lista1, lista2, inteiro1, inteiro2):
    aux=lista1[inteiro1]
    lista1[inteiro1]=lista2[inteiro2]
    lista2[inteiro2]=aux


def troca(lista1,lista2,inteiro1,inteiro2):
    for k in range(inteiro1,inteiro2):
        swap(lista1, lista2, k, k);

def Opera(lista1, lista2, lista3):
    if(len(lista3)%2!=0):
        print('tamanho da lista de pares é impar')
    else:
        for k in range(0,len(lista3)-1,2):
            troca(lista1, lista2, lista3[k], lista3[k+1])
    print(lista1)

Opera([1,0,-2],[3,4,5],[0,2])
