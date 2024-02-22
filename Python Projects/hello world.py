a='hello world'
alph = ['a','b','c','d','e','f','g','h','i','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ']
Palavra=""
for i in range (11):
    for j in range(26):
        if(alph[j]!=a[i]):
            print(Palavra+alph[j])
        else:
            Palavra=Palavra+alph[j]