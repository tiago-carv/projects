tamanho=5
Malha = [[0 for _ in range(tamanho)] for _ in range(tamanho)]
def mostramalha(Matriz):
    k=len(Matriz)
    for i in range(k):
        for j in range(k):
            print(f'{Matriz[i][j]} ', end="")
        print(" ")

def foradabordas(x,y):
    if (0<x<tamanho)and(0<=y<tamanho):
        return 0
    
while(True):
    i, j, sinal=input().split()
    i, j= int(i) ,int(j)
    
    if(sinal=="+"):
        for k in range(-1,2):
            for l in range(-1,2):
                Malha[i+k][j+l]+=1
    else:
        for k in range(-1,2):
            for l in range(-1,2):
                Malha[i+k][j+l]-=1
    print(" ")
    mostramalha(Malha)
    a=int(input("Digite 1 para continuar ou 0 para parar:"))
    if (a==0):
        break
mostramalha(Malha)