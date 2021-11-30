class ControleRemoto:
    def __init__(self, cor, altura, largura, profundidade):#na funcao init ficam os atributos!!!
        self.cor = cor
        self.altura = altura
        self.largura = largura
        self.profundidade = profundidade
    def passar_canal(self, botao):
        if botao == "+":
            print("Aumentar canal")
        elif botao == "-":
            print("Voltar canal")

controle_remoto1 = ControleRemoto("Preto", "10cm", "5cm", "5cm")#uma instancia do controle remoto
print(controle_remoto1.cor)

controle_remoto2 = ControleRemoto("Azul", "15cm", "4,5cm", "3cm")
print(controle_remoto2.cor)