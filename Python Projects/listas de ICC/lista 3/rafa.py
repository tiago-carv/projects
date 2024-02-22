dec = [1000,900,500,400,100,90,50,40,10,9,5,4,1]
roman = ['M','CM','D','CD','C','XC','L','XL','X','IX','V','IV','I']
n = int(input("Digite um numero:"))
rom = ''
for i in range(0,len(dec)):
    m = n // dec[i]
    for j in range(m):
        rom+=roman[i]
    n = n % dec[i]
print(rom)