#include <bits/stdc++.h>

using namespace std;

string coords(int x, int y){
	string s = to_string(x)+", "+to_string(y);
	return s;
}


int main(int argc, char const *argv[])
{	
	cin.sync_with_stdio(false);
	int t; cin >> t;

	while(t--){
		map<string, int> m;

		//Recebendo variáveis.
		int n; cin >> n;
		string s;
		cin >> s;

		//Percorrendo o caminho indicado pela string dada.
		int x = 0, y = 0;
		m[coords(0, 0)] = 1;
		int flag = false;
		int siz = 300003;
		int la = 0, ra = 0;
		for (int i = 0; i < n; ++i)
		{
			if(s[i] == 'L')x--;
			else if(s[i] == 'R')x++;
			else if(s[i] == 'U')y++;
			else if(s[i] == 'D')y--;

			if (m[coords(x, y)] > 0)
			{
				if((i+1 - m[coords(x, y)] + 1) < siz){
					siz = (i+1 - m[coords(x, y)] + 1);
					la = m[coords(x, y)];
					ra = i+1;
				}
				flag = true;
			}

			m[coords(x, y)] = i+2;

		}
		if (flag){
			cout << la << " " << ra << endl;
			continue;
		}

		cout << -1 << endl;

	}

	return 0;
}