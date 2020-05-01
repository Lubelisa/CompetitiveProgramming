#include <bits/stdc++.h>
using namespace std;

#define N 100001

vector<int> edges[N];

int dist[N];

void bfs(int s) {
    memset(dist, -1, sizeof dist);
    queue<int> q;

    dist[s] = 0;
    q.push(s);

    while(q.size()) {
        int u = q.front();
        q.pop();

        printf("%d\n", u);
        
        for(unsigned int i = 0; i < edges[u].size(); ++i) {
            int v = edges[u][i];
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
}}}}

int main() {
    cin.sync_with_stdio(false);
    int n, m, a, b; cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }    
    bfs(1);
    return 0;
}