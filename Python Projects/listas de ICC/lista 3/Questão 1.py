Notas=[]

n= int(input('Digite nota do primeiro aluno:'))

while(n!=-1):
    Notas.append(n)
    n = int(input('Digite a nota de um aluno ou digite -1 para terminar a inserção de notas:'))

Notas = sorted(Notas)
menor=0
maior=0
k=1
while(k<len(Notas)):
    if (Notas[menor]>Notas[k]):
        menor=k
    if (Notas[maior]<Notas[k]):
        maior=k
    k=k+1

print(Notas[menor])
print(Notas[maior])