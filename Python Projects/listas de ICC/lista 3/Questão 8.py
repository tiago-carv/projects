def Pa(lista):
    escada = 1
    a = lista[1]-lista[0]
    for i in range(1,len(lista)):
        if (lista[i]-lista[i-1] != a):
            escada+=1
            a = lista[i]-lista[i-1]
    return escada