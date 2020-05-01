#include <bits/stdc++.h>
using namespace std;


void lps_fill(string p, int psize, int * lps){
	int len = 0;
	lps[0] = 0;

	int i = 1;

	while(i < psize){
		if (p[i] == p[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else{
			if (len != 0)
				len = lps[len-1];
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMP(string s, string p, int ssize, int psize){
	int lps[psize+1];

	lps_fill(p, psize, lps);

	int i = 0;//index of s
	int j = 0;//index of p

	while(i < ssize){
		if (p[j] == s[i])
		{
			j++;
			i++;
		}

		if (j == psize)
		{
			cout << "Found at " << i-j << endl;
			j = lps[j-1];
		}
		else if (i < ssize and p[j] != s[i])
		{
			if (j != 0)
				j = lps[j-1];
			else i = i+1;
		}
	}
}

int main(int argc, char const *argv[])
{
	string s = "ABABDABACDABABCABAB";
	int ssize = (int)s.size();
	string p = "ABABCABAB";
	int psize = (int)p.size();
	KMP(s, p, ssize, psize);
	return 0;
}