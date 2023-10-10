k=0
z=0

for i in range (0,3):
    l = int(input('numero: '))
    s =l*l
    if (k<s):
        k=s
    z+=s

if(z-2*k==0):
    print('É um triângulo retângulo')
else:
    print('não é um triângulo retângulo')