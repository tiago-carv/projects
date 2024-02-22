#Questão 11

frase = input('Escreva uma frase: ').split()
for i in range(len(frase)):
    frase[i]=frase[i].capitalize()
for x in frase:
    print(x,end=" ")