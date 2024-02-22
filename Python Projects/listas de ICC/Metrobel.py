from random import*

PrimeiraEnt = []
SegundaEnt = []
n = int(input("n: "))

Perm1 = []
Perm2 = []
for i in range(n):
    Perm1.append(i+1);Perm2.append(i+1);

def embaralhar(A: list):
    tamlista=len(A)
    for i in range(tamlista):
        aux=A[i]
        k=randint(0,tamlista-1)
        A[i]=A[k]
        A[k]=aux
    return A
def mapa3(A: list):
    for i in range(len(A)):
        if (A[i][0]<20 and A[i][1]>55):
            return 1
        elif(A[i][0]>0 and A[i][1]==0):
            return 2
        else:
            return 0
def selection(A: list):
    for i in range(len(A)):
        k=i
        for j in range(i+1,len(A)):
            if A[j][1]<A[k][1]:
                k=j
        if A[i][1]!=A[k][1]:
            aux = A[i]
            A[i] = A[k]
            A[k] = aux
    return A
Perm1=embaralhar(Perm1)
Perm2=embaralhar(Perm2)

for i in range(n):
    a=Perm1[i]
    b=randint(0,100)
    c=randint(0,100)
    PrimeiraEnt.append([a,b,c])
    x=Perm2[i]
    y=randint(0,100)
    z=randint(0,100)
    SegundaEnt.append([x,y,z])
Ids=[0]*n
for i in range(n):
    for j in range(n):
        if SegundaEnt[i][0]==PrimeiraEnt[j][0]:
            Ids[i]=[i,j,SegundaEnt[i][1],SegundaEnt[i][2],PrimeiraEnt[j][1],PrimeiraEnt[j][2]]
Ids=selection(Ids)

MapaITU=[0]*n
for i in range(n):
    MapaITU[i]=PrimeiraEnt[Ids[i][1]][1]

MapaIDP=[0]*n
for i  in range(n):
    MapaIDP[i]=PrimeiraEnt[Ids[i][1]][2]
"""
for i in range(n):
    print(f'{MapaITU[i]} ',end='')
    if (i%8==7):
        print()
print()
for i in range(n):
    print(f'{MapaIDP[i]} ',end='')
    if (i%8==7):
        print()
print()
"""
Valores=[[0,0]]*n
for i in range(n):
    Valores[i,0]=Ids[i]
    Valores[i,1]=Ids[i]

for i in range(n):
    print(f'{mapa3(Valores)} ',end='')
    if (i%8==7):
        print()

print(Ids)