#include <bits/stdc++.h>
using namespace std;


int n, k;
string s;

int check(char x){
	int ret = 0, l = 0, r = 0;
	int cnt = 0;//num de letras já mudadas
	for(l = 0; l < n; l++){
		while(r < n and (cnt < k or s[r] != x)){
			if (s[r] == x)
			{
				cnt++;//como eu informo que mudei uma letra
			}
			r++;
		}
		if (s[l] == x)
		{
			cnt--;
		}
		if (ret < r-l)
		{
			ret = r-l;
		}
	}

	return ret;
}

int main(int argc, char const *argv[])
{
	cin >> n >> k;
	cin >> s;
	cout << max(check('a'), check('b')) << endl;

	return 0;
}