class Cliente:
    def __init__(self, nome, email, plano):
        self.nome = nome
        self.email = email
        self.lista_planos = ["basic", "premium"]#se fosse uma variavel somente pra essa funcao, nao precisaria do self.
        if plano in self.lista_planos:
            self.plano = plano
        else:
            raise Exception("Plano inválido!")
    def mudar_plano(self, novo_plano):
        if novo_plano in self.lista_planos:
            self.plano = novo_plano
        else:
            print("Plano inválido!")

    def ver_filme(self, filme, plano_filme):
        if self.plano == plano_filme:
            print(f'ver {filme}')
        elif self.plano == "premium":
            print(f'ver {filme}')
        else:
            print(f'filme não disponível no plano {self.plano}')

cliente1 = Cliente("Isaque", "isaque@gmal.com", "basic")
print(cliente1.plano)
cliente1.ver_filme("Homem-Aranha", "premium")

cliente1.mudar_plano("premium")
print(cliente1.plano)
cliente1.ver_filme("Homem-Aranha", "premium")