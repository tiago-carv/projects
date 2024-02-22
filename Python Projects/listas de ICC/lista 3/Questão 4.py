X = int(input())
Y = int(input())
soma = 0
prod = 1
a = X%2
b = Y%2
for i in range((X+a),(Y-b)+1,2):
	soma=soma+i

for i in range((X+(a-1)),(Y+(1-b))+1,2):
	prod=prod*z

print(soma)
print(prod)