import palavras
import random

x=palavras.palavras[random.randint(0,1185)]

letrasus=[]
vidas=7
A=len(x)
while (A>0):
    letra=input('Escreva uma letra:')
    if (letra in letrasus):
        print('Escolha outra letra!')
    elif (letra in x):
        print('Acertou!')
        letrasus.append(letra)
    else:
        print('Errou!')
        vidas=vidas-1
        A=A-1
    sorted(letrasus)
    if (letrasus==x):
        A=0
    
if vidas==0:
    print('Voce foi enforcado!')
else:
    print('Voce venceu!')
print(x)