tamanho = 5
Malha = [[0 for _ in range(tamanho)] for _ in range(tamanho)]

def mostramalha(Matriz):
    k = len(Matriz)
    for i in range(k):
        for j in range(k):
            print(f'{Matriz[i][j]} ', end="")
        print()  # Simplesmente quebra a linha após cada linha da matriz

a = int(input("Digite 1 para continuar ou 0 para parar:"))
while(a != 0):
    i, j, sinal = input().split()
    i, j = int(i), int(j)
    
    if sinal == "+":
        Malha[i][j] += 1
    else:
        Malha[i][j] -= 1
    
    print(Malha[i][j])
    a = int(input("Digite 1 para continuar ou 0 para parar:"))

mostramalha(Malha)
