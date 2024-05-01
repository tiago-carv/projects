N = int(input('Escreva um o tamanho do quadrado:'))

def num_quadrados_int(num: int):
    quantidade=0
    for i in range(1,num+1):
        quantidade += (num-i+1)**2
    return quantidade

print(num_quadrados_int(N))
