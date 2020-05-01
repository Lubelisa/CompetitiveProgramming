#include <bits/stdc++.h>

using namespace std;

vector<int> v[150001];

int ant[150001], prox[150001];

int main(int argc, char const *argv[])
{

	cin.sync_with_stdio(false);
	int n, p; cin >> n;
	int prim = 1;

	memset(ant, -1, sizeof(ant));
	memset(prox, -1, sizeof(prox));
	
	for (int i = 1; i < n; ++i)
	{
		int x, y; cin >> x >> y;
		
		if(prox[x] != -1 || ant[y] != -1){
			while(ant[y] != -1){
				y = ant[y];
			}
			while(prox[x] != -1){
				x = prox[x];
			}
		}			

		prox[x] = y;

		ant[y] = x;		
	}

	
	while(ant[prim] != -1){
		prim = ant[prim];
	}

	while(prim != -1){
		cout << prim << " ";

		prim = prox[prim];
	}
	return 0;
		
}