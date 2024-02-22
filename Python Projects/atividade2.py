#atividade2
5
TIAGO=[1,2,3,4,5]
n=int(input('Escreva um numero inteiro: '))

def fib(k):
    Fibo = []
    if (k==1):
        Fibo=[1]
    elif(k==2):
        Fibo=[1,2]
    else:
        a1=1
        a2=2
        Fibo=[1,2]
        k=k-2
        for i in range(k):
            aux=a1+a2
            a1=a2
            a2=aux
            Fibo.append(a2)
    return Fibo

def sub_l(list,k):
    while(len(list)>k):
        list.pop()
    return list

def imprimir(a):
    for i in range(len(a)-1):
        for j in range(i):
            print(f'{a[j]}',end=" ")
        print()

def imprimirinv(a):
    for i in range(len(a)-1, -1, -1):
        for j in range(i):
            print(f'{a[j]}',end=" ")
        print()
i=1
soma=0
while fib(i)[i]<4000000:
    soma=soma+fib(i)
    i+=1
    
imprimir(fib(n))
imprimirinv(fib(n))