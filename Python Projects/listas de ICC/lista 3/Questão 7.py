decimal = [1000,900,500,400,100,90,50,40,10,9,5,4,1]
romano = ['M','CM','D','CD','C','XC','L','XL','X','IX','V','IV','I']
roman = ''

n = int(input("Digite um numero:"))

for i in range(0,len(decimal)):
    m = n//decimal[i]
    for k in range(m):
        roman+=romano[i]
    n = n%decimal[i]

print(roman)