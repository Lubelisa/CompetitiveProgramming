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

string s;

int main(int argc, char const *argv[])
{
	cin.sync_with_stdio(false);

	int n, count = 0; in(n);
	in(s);
	int i = 0;
	while(i < n){
		if (i+1 >= n)
		{
			break;
		}
		if (s[i] == s[i+1])
		{
			if (i+2 >= n)
			{
				if (s[i] == 'B' or s[i] == 'R')
				{
					s[i+1] = 'G';
				}
				else{
					s[i+1] = 'R';
				}
				count++;
				break;
			}
			if (s[i] == 'B' && s[i+1] == 'B')
			{
				if (s[i+2] == 'R')
				{
					s[i+1] = 'G';
				}
				else{
					s[i+1] = 'R';
				}
			}
			else if (s[i] == 'R' && s[i+1] == 'R')
			{
				if (s[i+2] == 'B')
				{
					s[i+1] = 'G';
				}
				else{
					s[i+1] = 'B';
				}
			}
			else if (s[i] == 'G' && s[i+1] == 'G')
			{
				if (s[i+2] == 'B')
				{
					s[i+1] = 'R';
				}
				else{
					s[i+1] = 'B';
				}
			}
			count++;
			i+=2;
		}
		else{
			i++;
		}
	}

	out(count);
	out(s);
	return 0;
}