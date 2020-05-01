#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f; // inf = 1061109567 (um bom valor porque eh maior que 10^9, 2 * inf nao estoura um inteiro e eh rapido de fazer memset
vector<int> edges[N], costs[N]; // vetor de adjacencias, vetor de pesos >>>> v = edges[u][i]; w = costs[u][i];
int dist[N], pred[N], n; // vetor de distancias minimas, vetor de predecessor, numero de vertices

// Realiza o algoritmo partindo do vertice s (start)
void dijkstra(int s) {

    priority_queue<pair<int, int> > pq;
    // guarda os proximos vertices a serem visitados, junto com sua distancia minima com sinal trocado  {-dist[u], u}
    // o sinal eh trocado porque queremos uma priority_queue de minimo. Como queremos ordenar pela distancia, 
    // ela deve vir primeiro no pair

    for(int i = 1; i <= n; ++i) dist[i] = inf;
    
    // inicia com o vertice s (de partida)
    pq.push(make_pair(0, s))
    dist[s] = 0;

    while(pq.size()) {
        int u = pq.top().second; // pega o proximo vertice
        int d = -pq.top().first;
        pq.pop(); //retira

        // olha pros adjacentes
        for(int i = 0; i < edges[u].size(); ++i) {
            int v = edges[u][i];
            int w = costs[u][i];
            if(dist[v] > dist[u] + w) { // relaxa a aresta
                dist[v] = dist[u] + w; // atualiza a distancia
                pred[v] = u; // atualiza o predecessor
                pq.push(make_pair(-dist[v], v)); // coloca na priority queue
}}}}