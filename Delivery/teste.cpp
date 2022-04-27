#include <iostream>
#include <list>
#include <climits>

using namespace std;

struct no{
    int v;//vertice
    int distancia;//distancia aresta
};
struct info{
    int peso;
    int dist[100];
    int entregue;
};
struct entrega{
    int mochila;
    int tempo_total;
    int local_atual;
    list<int> entregou;
    list<int> caminho;
};

void caminho_entregador(int local, int entregador){
    entrega motoboy[100];
    motoboy[entregador].caminho.push_back(local);
}

void cria_aresta(list<no>adj[], int u, int v, int d){
    no aui;//auxiliar
    //criando arestas
    aui.v = v;
    aui.distancia = d;
    adj[u].push_back(aui);
    //rota inversa(nao orientado)
    aui.v = u;
    adj[v].push_back(aui);
}
void dijkstra(list<no>adj[], int nVertices, int start, int end, int &custo, int entregador, list<int> caminho[], int x[]){
    custo = 0;
    int v;//vertice
    int destino;//vertice de destino
    int weight;//distancia da aresta analisada
    int dist;//distancia auiiliar
    int u;//aui
    int parent[100];//pai do vertice
    int distancia[100];//vetor p distancias
    bool intree[100];//se esta na arvore
    list<int> stack;//pilha p resultado
    list<no>::iterator p;
    for(u = 0; u < nVertices; u ++){
        intree[u] = false;
        distancia[u] = INT_MAX;
        parent[u] = -1;
    }
    distancia[start] = 0;
    v = start;
    while(intree[v] == false){
        intree[v] = true;
        for(p = adj[v].begin(); p != adj[v].end(); p ++){
            destino = p->v;
            weight = p->distancia;
            if(distancia[destino] > distancia[v] + weight){//dijkstra
                distancia[destino] = distancia[v] + weight;
                parent[destino] = v;
            }
        }

        v = 0;
        dist = INT_MAX;
        for(u = 0; u < nVertices; u ++){
            if((intree[u] == false) && (dist > distancia[u])){
                dist = distancia[u];
                v = u;
            }
        }
    }
    //output
    cout << "Menor caminho: ";
    stack.push_front(end);
    u = end;
    while(parent[u] != -1){
        cout << "Entrou aqui" << endl;
        stack.push_front(parent[u]);
        u = parent[u];
    }
    x[entregador] = 0;
    while(!stack.empty()){
        x[entregador] ++;
        caminho[entregador].push_front(*stack.begin());
        cout << *stack.begin() << " - ";
        stack.pop_front();
    }
    cout << endl;
    custo = distancia[end];
    cout << "Custo: " << custo << endl;
}

int main(){
    int n_locais, n_entregadores;//numero de vertices e de entregadores
    int vo, vf;//vertices inicial e final
    int i, j, d, p;//local inicial, final, distancia dessa aresta e peso da entrega
    int x;//auxiliar
    int custo_atual;//var p comparacao de custos
    info local[100];//informacoes do local
    entrega motoboy[100];//dados base p entregador
    list<int> caminho[100];//caminho do entregador
    list<no> adj[100];//lista adjacencia

    //INPUT
    //criacao do grafo
    cout << "Entre com o numero de locais e de entregadores: ";
    cin >> n_locais >> n_entregadores;
    cout << endl;
    cout << "Obs.: Local 0 sera o supermercado." << endl;
    for(int i = 0; i < (n_locais - 1); i ++){
        for(int j = i + 1; j < n_locais; j ++){
            cout << "Entre com a distancia do local " << i << " ao local " << j << " em minutos: ";
            cin >> d;
            cout << endl;
            local[i].dist[j] = d;
            cria_aresta(adj, i, j, d);
        }
    }
    //peso das entregas
    for(int i = 1; i < n_locais; i ++){
        cout << "Entre com o peso da entrega do local " << i << ": ";
        cin >> p;
        cout << endl;
        local[i].peso = p;
    }
    //distancia ate o supermercado de cada entregador, atualizacao de local e resetar distancia da mochila
    for(int i = 0; i < n_entregadores; i ++){
        cout << "Entre com a distancia do entregador " << i << " ate o supermercado: ";
        cin >> x;
        motoboy[i].tempo_total += x;
        motoboy[i].local_atual = 0;
        motoboy[i].mochila = 0;
        caminho[i].push_front(motoboy[i].local_atual);
    }

    int menor = INT_MAX;
    int motoboy_escolhido;
    int n_locais_passou[100];//numero de locais q passou na funcao djikstra para testar menor caminho
    for(int i = 1; i < n_locais; i ++){
        for(int j = 0; j < n_entregadores; j ++){    
            dijkstra(adj, n_locais, motoboy[j].local_atual, i, custo_atual, j, caminho, n_locais_passou);
            if(custo_atual < menor && (motoboy[j].mochila + local[i].peso <= 18)){
                motoboy_escolhido = j;
            }
            for(int z = 0; z < n_locais_passou[j]; z ++){
                caminho[z].pop_front();//remover do caminho percorrido caso nao seja o entregador escolhido
            }
        }
        motoboy[motoboy_escolhido].local_atual = i;//atualizacao do local atual do entregador
        motoboy[motoboy_escolhido].mochila += local[i].peso;//peso gasto pela entrega do local i
        motoboy[motoboy_escolhido].tempo_total += local[motoboy[motoboy_escolhido].local_atual].dist[i];//distancia gasta ate o local i
        motoboy[motoboy_escolhido].entregou.push_front(i);//compra do local i entregue pelo motoboy
        menor = INT_MAX;
    }

    //OUTPUT
    for(int j = 0; j < n_entregadores; j ++){
        //for(int i = 0; i < n_locais_passou[j]; i ++){
        cout << "O caminho do entregador " << j << " foi: ";
        while(!caminho[j].empty()){
            cout << *caminho[j].begin() << " - ";
            caminho[j].pop_front();
        }
        cout << endl;
        cout << "O tempo total percorrido pelo entregador " << j << " foi de: " << motoboy[j].tempo_total << endl;
        cout << "As compras entregues pelo entregador " << j << " foram: ";
        while(!motoboy[j].entregou.empty()){
            cout << *motoboy[j].entregou.begin() << " - ";
            motoboy[j].entregou.pop_front();
        }
        cout << endl;
    }
    
    return 0;
}