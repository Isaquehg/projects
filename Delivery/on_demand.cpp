#include <iostream>
#include <climits>

using namespace std;

struct dados1{
    int distancia[100]; //distancia ate o local x
    int peso; //peso da entrega do local
    bool entregue;//verificar se a compra desse local ja foi entregue
};

struct dados2{
    int dist_sup;//distancia do entregador ao supermercado em MINUTOS
    int dist_local[100];//distancia do entregador ao local y
    int tempo;//tempo total gasto pelo entregador
    int custo;//custo p comparar com outro entregadores
    int localidade;//local atual do entregador
    int mochila;//peso das entregas
    int caminho[100];//caminhos que o entregador passou
    int n_entregas;//numero de entregas que o entregador fez
};

void quem_leva(dados1 local[], dados2 entregador[], int n_locais, int n_entregadores){
    int menor_custo = 10000;
    int entregador_escolhido;
    int peso_atual;
    int local_atual;
    int tempo_atual;
    for(int i = 1; i < n_locais; i ++){
        for(int j = 0; j < n_entregadores; j ++){
            entregador[j].custo += local[entregador[j].localidade].distancia[i];
            if((entregador[j].custo < menor_custo) && (entregador[j].mochila + local[i].peso < 18)){
                entregador_escolhido = j;
                peso_atual = local[i].peso;
                local_atual = i;
                tempo_atual = local[entregador[j].localidade].distancia[i];
            }
        }
        entregador[entregador_escolhido].localidade = local_atual;
        entregador[entregador_escolhido].mochila += peso_atual;
        entregador[entregador_escolhido].tempo += tempo_atual;
        entregador[entregador_escolhido].caminho[entregador[entregador_escolhido].n_entregas] = local_atual;
        entregador[entregador_escolhido].n_entregas += 1;
        for(int z = 0; z < n_locais; z ++){
            entregador[entregador_escolhido].dist_local[z] = local[local_atual].distancia[z];
        }
        cout << "Entregador " << entregador_escolhido << " entregou para o local " << local_atual << endl;
        cout << "Tempo : " << entregador[entregador_escolhido].tempo << endl;
    }
    
}

int main(){
    //declaracao de variaveis
    dados1 local[100];//informacoes base de determinado local(grafo)
    dados2 entregador[100];//informacoes dos entregadores
    int n_locais;//numero de locais
    int n_entregadores;//numero de entregadores

    //input numero de locais e numero de entregadores
    cout << "Entre com o numero de locais e com o numero de entregadores: ";
    cin >> n_locais >> n_entregadores;
    cout << endl;
    //input dos locais e suas distancias(grafo)
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
    int m = 10000;//menor distancia
    int motoboy;//entregador c menor distancia
    for(int i = 0; i < n_entregadores; i ++){
        cout << "Entre com a distancia do entregador " << i << " ate o supermercado em minutos: ";
        cin >> entregador[i].dist_sup;
        if(entregador[i].dist_sup < m){
            m = entregador[i].dist_sup;
            motoboy = i;
        }
    }

    //input do local e peso de cada entrega
    //obs.: Contador comeca do 1, pois o local 0 é o supermercado!
    local[0].peso = 0;
    for(int i = 1; i < n_locais; i ++){
        cout << "Entre com o peso da entrega do local " << i << ": ";
        cin >> local[i].peso;
    }

    //reset
    int passou[100];//verificar se ja passou no local
    for(int i = 0; i < n_locais; i ++){//resetando visitas aos locais
        passou[i] = false;
        local[i].entregue = false;
    }
    for(int i = 0; i < n_entregadores; i ++){//somando tempo ao supermercado no custo total
        entregador[i].tempo = entregador[i].dist_sup;
        entregador[i].n_entregas = 0;
        entregador[i].mochila = 0;
    }
  
    //calculo do tempo de cada entregador ate cada casa passando pelo supermercado
    quem_leva(local, entregador, n_locais, n_entregadores);

    //output de quais compras ficaram com cada entregador
    //output do tempo percorrido por cada entregador
    //output da recuperacao de caminho de cada entregador

    return 0;
}