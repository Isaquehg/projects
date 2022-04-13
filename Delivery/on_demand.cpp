#include <iostream>

using namespace std;

struct dados{
    int distancias[10][10];//distancia do local x para o y (grafo)
    int entregas[10];//peso da entrega do local x
    int dist_sup[100];//distancia do supermercado do entregador x
    int dist_local[10][10];//distancia do entregador x ao local y
};

int main(){
    //declaracao de variaveis
    dados info;//struct para informacoes
    int n_locais;//numero de locais
    int n_entregadores;//numero de entregadores


    //input dos locais e suas distancias(grafo)
    //input do numero de entregadores e suas distancias do supermercado
    //input do local e peso de cada entrega

    //calculo de distancia e tempo de cada entregador ate o supermercado e ate cada casa
    
    //calculo de quais pacotes irao com cada entregador

    //output de quais compras ficaram com cada entregadro
    //output do tempo percorrido por cada entregador
    //output da recuperacao de caminho de cada entregador

    return 0;
}