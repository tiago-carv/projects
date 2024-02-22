def indice(lista:list,a:int):
    posições=[]
    for i in range(len(lista)):
        if (lista[i]==a):
            posições.append(i)
    return posições