#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union 
int parent[N], sz[N];

int find(int a) {
	return parent[a] == a ? a : parent[a] = find(parent[a]); 
}

void swap(int *a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
}

void unite(int a, int b) {
	if ((a = find(a)) == (b = find(b))) return;

	if (sz[a] < sz[b]) swap(&a, &b);

	parent[b] = a;
	sz[a] += sz[b];
}