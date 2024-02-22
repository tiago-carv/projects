#Questão 1
s = int(input("Digite um número: "))

min = s//60
h = min//60

if s%60<10:
    segundos=f'0{s%60}'
else:
    segundos=f'{s%60}'

if min%60<10:
    minutos=f'0{min%60}'
else:
    minutos=f'{min%60}'

if h<10:
    horas=f'0{h%60}'
else:
    horas=f'{h%60}'

print(f'{horas}:{minutos}:{segundos}')