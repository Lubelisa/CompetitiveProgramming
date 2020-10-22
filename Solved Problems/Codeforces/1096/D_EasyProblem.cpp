#include <bits/stdc++.h>
using namespace std;
string s;
long long n, h, a, r, d;
int main()
{
	cin >> n;
    cin >> s;

	for(int i = 0; i < n; i++){
		int x;
		cin >> x;

		if(s[i] == 'h'){
            h += x;
        }
		else if(s[i] == 'a'){
            a += x;
            a = min(h, a);
        }
		else if(s[i] == 'r'){
            r += x;
            r = min(a, r);
        }
		else if(s[i] == 'd'){
            d += x;
            d = min(r, d);
        }
	}


	cout << d << endl;

    return 0;
}