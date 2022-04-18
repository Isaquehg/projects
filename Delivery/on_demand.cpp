#include <iostream>
#include <climits>

using namespace std;

struct dados{
    int distancias[100][100];//distancia do local x para o y (grafo)
    int entregas[100];//peso da entrega do local x
    int dist_sup[100];//distancia do supermercado do entregador x em MINUTOS
    int dist_local[100][100];//distancia do entregador x ao local y (Usar Prog. Dinâmica!)
};

int main(){
    //declaracao de variaveis
    dados info;//struct para informacoes
    int n_locais;//numero de locais
    int n_entregadores;//numero de entregadores
    int carga = 18;//peso suportado pelos entregadores

    //input numero de locais e numero de entregadores
    cout << "Entre com o numero de locais e com o numero de entregadores: ";
    cin >> n_locais >> n_entregadores;
    cout << endl;
    //input dos locais e suas distancias(grafo)
    cout << "Entrada do Grafo(O primeiro local sera o supermercado)" << endl;
    for(int i = 0; i < n_locais; i ++){
        for(int j = 0; j < (n_locais - 1); j ++){
            cout << "Entre com a distancia do local " << i << " ate o local " << j << ": ";
            cin >> info.distancias[i][j];
            cout << endl;
        }
    }

    //distancias dos entregadores ate o supermercado
    for(int i = 0; i < n_entregadores; i ++){
        cout << "Entre com a distancia do entregador " << i << " ate o supermercado em minutos: ";
        cin >> info.dist_sup[i];
    }

    //input do local e peso de cada entrega
    //obs.: Contador comeca do i, pois o local 0 é o supermercado!
    for(int i = 1; i < n_locais; i ++){
        cout << "Entre com o peso da entrega do local " << i << ": ";
        cin >> info.entregas[i];
    }

    //calculo do tempo de cada entregador ate cada casa passando pelo supermercado


    //depois de decidir qual entregador esta mais perto de certo local, verificar se cabe em sua mochila, caso contrario, verificar o outro mais perto


    //output de quais compras ficaram com cada entregador
    //output do tempo percorrido por cada entregador
    //output da recuperacao de caminho de cada entregador

    return 0;
}