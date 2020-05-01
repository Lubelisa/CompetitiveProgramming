#include <bits/stdc++.h>

using namespace std;


int parent[500005], weight[500005];

int find(int x){
	 return parent[x] == x ? x : parent[x] = find(parent[x]);
}

void uni(int x, int y){
	int u = find(x);
	int v = find(y);

	if (u != v)
	{
		parent[v] = u;
		weight[u] += weight[v];
	}
}

int v[500005];

int main(int argc, char const *argv[])
{
	int n, m; scanf("%d%d", &n, &m);

	for (int i = 0; i < n; ++i)
	{
		parent[i] = i; weight[i] = 1;
	}

	for (int i = 1; i <= m; ++i)
	{
		int k; scanf("%d", &k);

		for (int j = 0; j < k; ++j)
		{
			scanf("%d", &v[j]); uni(v[0], v[j]);			
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		printf("%d ", weight[find(i)]);
	}

	return 0;
}