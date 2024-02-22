import math
A = int(input('A: '))

def divisores(k):
	div=[k]
	for i in range(2,(math.isqrt(k)+1)):
		if k%i==0:
			div.append(i)
			div.append(k//i)
	div=sorted(div)
	return div

def numdiv(k):
	return len(divisores(k))+1
PA=1
DA=divisores(A)

for i in range(len(DA)):
	if(numdiv(DA[i])==2):
		PA=DA[i]

print(PA)