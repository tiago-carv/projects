import math
def divisores(k:int):
	div=[1,k]
	for i in range(2,(math.isqrt(k)+1)):
		if k%i==0:
			div.append(i)
			div.append(k//i)
	div=sorted(div)
	return div
def numdiv(k:int):
	return len(divisores(k))

def mdc(a:int,b:int):
	A=divisores(a)
	B=divisores(b)
	maxdiv=1
	for i in range(numdiv(a)):
		for j in range(numdiv(b)):
			if(A[i]==B[j]):
				maxdiv=A[i]
	return maxdiv

A=2
for i in range(3,21):
	if(A%i!=0):
		A=A*mdc(A,i)
print(divisores(21))
print(A)