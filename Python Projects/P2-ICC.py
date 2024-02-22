Cidade=[];M=[0]*5;BAU=[0]*5;S=0;L=1;N=2;O=3;Sul=[];Leste=[];Norte=[];Oeste=[];n=1;Total=[]
s=0;
while (s<53):
    s=int(input())
    local=int(input())
    T=int(input())
    M[4]=M[4]+T+BAU[4]*(s-n-1)
    M[local]=M[local]+T+BAU[local]*(s-n-1)
    Cidade.append([s,local,T])
    BAU[local]=T
    BAU[4]=T
    n=s;
n=1;
for i in range(len(Cidade)):
    if Cidade[i][1]==S:
        for i in range(Cidade[i][0]-n-1):
            Sul.append(Cidade[i][1])
    if Cidade[i][1]==L:
        for i in range(Cidade[i][0]-n-1):
            Leste.append(Cidade[i][1])
    if Cidade[i][1]==N:
        for i in range(Cidade[i][0]-n-1):
            Norte.append(Cidade[i][1])
    if Cidade[i][1]==O:
        for i in range(Cidade[i][0]-n-1):
            Oeste.append(Cidade[i][1])
    for i in range(Cidade[i[0]-n-1]):
        Total.append(Cidade[i][1])
    n=Cidade[i][0];

def  moda(A:list):
    A=sorted(A)
    n=0
    s1=1
    s2=0
    a=A[0]
    b=0
    for i in range(1,len(A)):
        if(A[i]==a):
            s1+=1
        else:
            b=A[i]
            s2=1
        if(A[i]==b):
            s2+=1
        if(s1<s2):
            a=b
    return a

print(f"a média de toda a cidade é{M[4]/52}")
print(f"a média do {M[0]/52}")
print(f"a média de {M[1]/52}")
print(f"a média do {M[2]/52}")
print(f"a média do {M[3]/52}")
print(f"a moda de toda a cidade é{moda(Total)}")
print(f"a moda do sul é{moda(Sul)}")
print(f"a moda do leste é{moda(Leste)}")
print(f"a moda do norte é{moda(Norte)}")
print(f"a moda do oeste é{moda(Oeste)}")