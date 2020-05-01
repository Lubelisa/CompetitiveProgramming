#include <bits/stdc++.h>

using namespace std;

#define N 1000

vector<int> edges[N];

int vis[N];

void dfs(int src){

	vis[src] = 1;

	for (unsigned int i = 0; i < edges[src].size(); ++i)
	{
		int u = edges[src][i];
		if(vis[u] == 0){dfs(u);}
	}
}


int main(int argc, char const *argv[])
{
	cin.sync_with_stdio(false);

	int nVertices, nEdges;
	cin >> nVertices >> nEdges;

	memset(vis, 0, N);

	for (int i = 0; i < nEdges; ++i)
	{
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	dfs(1);

	return 0;
}