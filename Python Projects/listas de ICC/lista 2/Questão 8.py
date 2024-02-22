import random

V=[random.randint(0,10) for _ in range(100)]
print(V)

def selection(list):
    for i in range(len(list)):
        k=i
        for j in range(i+1,len(list)):
            if list[j]<list[k]:
                k=j
        if list[i]!=list[k]:
            aux = list[i]
            list[i] = list[k]
            list[k] = aux
    return list

V=selection(V)
print(V)