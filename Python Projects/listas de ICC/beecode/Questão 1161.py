memo ={}

def fat(k:int):
    if k in memo:
        return memo[k]
    if k<=2:
        resultado=k
    else:
        resultado=(fat(k-1)*k)
    memo[k]=resultado
    return resultado  
    
    
while(True):
    try:
        a,b = map(int,input().split())
        c = fat(a)+fat(b)
        print(c)
        print(memo)
    except EOFError:
        break