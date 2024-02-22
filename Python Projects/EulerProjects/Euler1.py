def ThreeFive(k):
    A = []
    for i in range(2,k):
        if(i%3==0)or(i%5==0):
            A.append(i)
    L=len(A)
    s=0
    for i in range(L):
        s=s+A[i]
    return s

print(ThreeFive(1000))