#Questão3
def ehsubconj():
    conj = []
    for i in range (5):
        nums = int(input('numero: '))
        conj.append(nums)

    if ((conj[0]==conj[3] or conj[1]==conj[3] or conj[1]==conj[3]) and (conj[0]==conj[4] or conj[1]==conj[4] or conj[2]==conj[4])):
        return "É um subconjunto"
    else:
        return "Não é um subconjunto"

a = ehsubconj()
print(a)