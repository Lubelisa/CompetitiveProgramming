#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000;

int dist[MAX][MAX], parent[MAX];

void floydWarshall(int n) {
	for (int i = 1; i <= n; i++) dist[i][i] = 0;
	memset(par, -1, sizeof par);

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					parent[k] = i;
					parent[j] = k;
				}
			}
		}
	}
}

int main() {
	memset(dist, 0x3f3f, sizeof(dist));

	int n, m; cin >> n >> m;
	while(m--) {
		int u, v, w; cin >> u >> v >> w;
		dist[u][v] = w;
	}

	floydWarshall(n);

	return 0;
}