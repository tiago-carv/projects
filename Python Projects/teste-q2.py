from math import*
A = int(input('A: '))
B = int(input('B: '))

def divisores(k):
	div=[1,k]
	for i in range(2,(isqrt(k)+1)):
		if k%i==0:
			div.append(i)
			div.append(i/k)
	return len(div)

PA=1
PB=1

for j in range(2,A+1):
	if divisores(j)==2:
		PA=j

for l in range(2,B+1):
	if divisores(l)==2:
		PB=l

print(PA*PB)