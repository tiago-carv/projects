class cachorro:
    def __init__(self,nome,comida,sono,fome):
        self.nome = nome
        self.comida = comida
        self.sono = sono
        self.fome = fome
    def comer(self):
        self.comida -= 1
        self.fome -= 1
    
    def dormir(self):
        self.sono = False

dudy = cachorro("dudy",17,True,10)
print(dudy.comida)
print(dudy.fome)

while(dudy.fome>0):
    dudy.comer()

print(dudy.comida,"\n",dudy.fome)