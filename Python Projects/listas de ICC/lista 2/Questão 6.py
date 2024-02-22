#Questão 6

n = int(input('Digite o tamanho da matriz:'))

valores = []
valores2= []
soma=0

for i in range(n):
    valor = int(input('Digite um número inteiro:'))
    valores.append(valor)
print(valores)

m = int(input('Digite um número inteiro:'))

valores1=[x for x in valores if x > m]

for x in valores1:
    if (x not in valores2):
        valores2.append(x)
for x in valores2:
    soma+=x
print(valores2)