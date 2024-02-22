def euclid(a:int,b:int):
    r=[0]*3
    s=[0]*2
    t=[0]*2
    q=[0]*2
    r[0]=a
    r[1]=b
    s[0]=1
    s[1]=0
    t[0]=0
    t[1]=1
    r[2]=1
    j=1
    while r[j]!=0:
        j=j+1
        q.insert(j-1,r[j-2]//r[j-1])
        r.insert(j,r[j-2]%r[j-1])
        s.insert(j,s[j-2]-s[j-1]*q[j-1])
        t.insert(j,t[j-2]-t[j-1]*q[j-1])
    return r[-3]

print(euclid(21,37))
L=[0]
