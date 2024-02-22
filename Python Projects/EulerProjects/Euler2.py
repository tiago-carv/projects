memo ={}

def fib(k):
    if k in memo:
        return memo[k]
    if k<=2:
        resultado=k
    else:
        resultado=(fib(k-1)+fib(k-2))
    memo[k]=resultado
    return resultado


fib(34)
Par={}
def iseven(A: dict):
    for i in A:
        if A[i]%2==0:
            Par[i]=A[i]
    return Par

iseven(memo)
s=0
for i in Par:
    s+=Par[i]
print(s)