tamanho=5
Malha=[[0]*tamanho]*tamanho
def mostramalha(Matriz):
    k=len(Matriz)
    for i in range(k):
        for j in range(k):
            if (j==(k-1)&(i!=k-1)):
                print(" ")
            print(f'{Matriz[i][j]} ', end="")
    print(" ")
a = 1
a=int(input("Digite 1 para continuar ou 0 para parar:"))
while(a!=0):
    i, j, sinal=input().split()
    i = int(i)
    j = int(j)
    sinal = str(sinal)
    
    if(sinal=="+"):
        for k in range(-1,2):
            for l in range(-1,2):
                Malha[i][j]+=1
    else:
        for k in range(-1,2):
            for l in range(-1,2):
                Malha[i][j]-=1
    print(i)
    print(j)
    print(Malha[i][j])
    a=int(input("Digite 1 para continuar ou 0 para parar:"))

mostramalha(Malha)