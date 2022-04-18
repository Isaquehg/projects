#include <iostream>
#include <climits>

using namespace std;

struct dados1{
    int distancia[100]; //distancia ate o local x
    int peso; //peso da entrega do local
};

struct dados2{
    int dist_sup;//distancia do entregador ao supermercado em MINUTOS
    int dist_local[100];//distancia do entregador ao local y
};

int main(){
    //declaracao de variaveis
    dados1 local[100];//informacoes base de determinado local
    dados2 entregador[100];//informacoes dos entregadores
    int n_locais;//numero de locais
    int n_entregadores;//numero de entregadores
    int carga = 18;//peso suportado pelos entregadores = 18kg

    //input numero de locais e numero de entregadores
    cout << "Entre com o numero de locais e com o numero de entregadores: ";
    cin >> n_locais >> n_entregadores;
    cout << endl;
    //input dos locais e suas distancias(grafo)
    bool reverso = false;
    cout << "Entrada do Grafo(O primeiro local sera o supermercado)" << endl;
    for(int i = 0; i < (n_locais - 1); i ++){
        for(int j = (i + 1); j < n_locais; j ++){
            cout << "Entre com a distancia do local " << i << " ate o local " << j << ": ";
            cin >> local[i].distancia[j];
            local[j].distancia[i] = local[i].distancia[j];//caminho reverso
            cout << endl;
        }
    }

    //distancias dos entregadores ate o supermercado
    for(int i = 0; i < n_entregadores; i ++){
        cout << "Entre com a distancia do entregador " << i << " ate o supermercado em minutos: ";
        cin >> entregador[i].dist_sup;
    }

    //input do local e peso de cada entrega
    //obs.: Contador comeca do i, pois o local 0 é o supermercado!
    for(int i = 1; i < n_locais; i ++){
        cout << "Entre com o peso da entrega do local " << i << ": ";
        cin >> local[i].peso;
    }

    //calculo do tempo de cada entregador ate cada casa passando pelo supermercado
    /*
    int vis[i];//verificar se ja passou no local
    for(int i = 0;i < n;i++)
		vis[i] = false;
	
	// guloso
	menor_custo = 0;
	cidade_atual = cidade_inicial;
	for(int i = 0;i < n-1;i++) // n-1 vezes = qnt de caminhos (exceto a volta para a cidade inicial)
	{
		vis[cidade_atual] = true; // marco que ja visitei a cidade atual
		// encontrar qual a proxima cidade mais proxima
		custo_at = INT_MAX;
		for(int j = 0;j < n;j++)
		{
			if(!vis[j] && custo_at > custo[cidade_atual][j])
			{
				proxima_cidade = j;
				custo_at = custo[cidade_atual][j];
			}	
		}
		menor_custo += custo_at;
		cidade_atual = proxima_cidade;
	}
	menor_custo += custo[cidade_atual][cidade_inicial];
	cout << "Menor custo = " << menor_custo << endl;
    */












    //depois de decidir qual entregador esta mais perto de certo local, verificar se cabe em sua mochila, caso contrario, escolher o outro mais perto


    //output de quais compras ficaram com cada entregador
    //output do tempo percorrido por cada entregador
    //output da recuperacao de caminho de cada entregador

    return 0;
}