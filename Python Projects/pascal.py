memo = {}
def factorial(n: int) -> int:
    if n in memo:
        return memo[n]
    if n<2:
        res=1
    else:
        res=factorial(n-1)*n
    memo[n]=res
    return res

def pascal(Rownum: int)-> list[int]:
        pascal_row = [0]*Rownum
        for i in range(Rownum):
            pascal_row[i]=factorial(Rownum)/(factorial(Rownum-i)*factorial(i))

def generate(numRows: int) -> list[list[int]]:
        saida=[]
        for i in range(numRows):
            saida.append(pascal(i))
        return saida
print(pascal(5))
print(memo)