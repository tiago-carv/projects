n = int(input('Digite o tamanho máximo da palavra: '))
frase = input('Digite a palavra')

cad = frase[0:n]
cad_inv= ""
for i in range(len(cad)-1,-1,-1):
    cad_inv+=cad[i]
    print(i)
cad_inv = str(cad_inv)
print(cad_inv)

if (cad_inv==cad):
    print('é palindrome')
else:
    print('não é palindrome')