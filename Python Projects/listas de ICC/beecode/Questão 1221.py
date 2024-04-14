import math
N = int(input())
X = int(input())

def Isprime(k:int):
    Div=[1]
    for i in range(2,(math.isqrt(k)+1)):
        if (k%i==0):
            Div.append(i)
            Div.append(k//i)
    Div.append(k)
    
    if (len(Div)==2):
        return "Prime"
    
    return "Not Prime"

    #return Div

print(Isprime(X))