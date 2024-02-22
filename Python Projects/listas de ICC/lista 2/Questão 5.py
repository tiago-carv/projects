#Questão 5

n = input('Digite o tamanho máximo da frase: ')

num = int(n[0])
cad = n[2:num+2]
cad_inv= ""
for i in range(len(cad)-1,-1,-1):
    cad_inv+=cad[i]
cad_inv = str(cad_inv)
print(cad_inv)