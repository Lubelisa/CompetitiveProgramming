#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
#define yes() cout << "YES" << endl;
#define no() cout << "NO" << endl;
 
#define in(x) cin >> x;
#define out(x) cout << x << endl;
#define pb push_back
#define infinity 0x3f3f3f3f
#define MAX(x,y) (x > y) ? x : y
#define MIN(x,y) (x < y) ? x : y
#define MAXIMO 100000
#define MOD 1000000007

char m[51][51];

int main(int argc, char const *argv[])
{
	int n, count = 0; in(n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			in(m[i][j]);
			if (m[i][j] == '.')
			{
				count++;
			}

		}
	}

	if(count % 5 != 0){
		no();
		return 0;
	}

	for (int i = 1; i < n-1; ++i)
	{
		for (int j = 1; j < n-1; ++j)
		{
			if(m[i][j] == '.' and m[i-1][j] == '.' and m[i+1][j] == '.' and m[i][j+1] == '.' and m[i][j-1] == '.'){
				m[i][j] = m[i-1][j] = m[i+1][j] = m[i][j+1] = m[i][j-1] = '#';
				count -= 5;
			}

		}
	}

	if(count == 0){yes();}
	else{no();}

	return 0;
}