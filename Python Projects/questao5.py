
n = int(input('Digite o tamanho da matriz:'))

valores = []

for i in range(0,n+1):
    valor = int(input('Digite um número inteiro:'))
    valores.append(valor)
print(valores)

m = int(input('Digite um número inteiro:'))

valores1=[x for x in valores if x < m]
print(valores1)

"""
for i in range(0,n):
    if (valores[i]<m):
        valores.remove(valores[i])
"""