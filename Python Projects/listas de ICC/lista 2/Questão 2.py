#Questão 2
def triangRetang():
    Lados = []
    for i in range (3):
        nums = int(input('numero: '))
        Lados.append(nums)

    k=0
    z=0
    for i in range (3):
        l = Lados[i]
        s =l*l
        if (k<s):
            k=s
        z+=s

    if(z-2*k==0):
        print('É um triângulo retângulo')
    else:
        print('não é um triângulo retângulo')