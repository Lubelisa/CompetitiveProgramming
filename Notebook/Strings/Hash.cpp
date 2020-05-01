#include <bits/stdc++.h>

using namespace std;

#define FIRST 96
#define MAX 100000
#define ll long long
ll MOD[2] = {1000000007, 1000000009};
int primes[2] = {31, 37};
ll potences[2][MAX+10];
ll hashes[2][MAX+10];


void intialize_hash(string s){
	ll siz = (ll)s.size();
	for (ll i = 0; i < 2; ++i)
	{
		potences[i][0] = 1;
		for (ll j = 1; j <= siz; ++j)
			potences[i][j] = (potences[i][j-1] * primes[i]) % MOD[i];
	}

	for (ll i = 0; i < siz; ++i) s[i] = s[i] - FIRST;
	
	for (ll i = 0; i < 2; ++i)
	{
		hashes[i][0] =	s[i];
		for (ll j = 1; j < siz; ++j)
			hashes[i][j] = (hashes[i][j-1] + j + (s[j] * potences[i][j])) % MOD[i];
	}	
}

int main(int argc, char const *argv[])
{
	string s = "choremos";

	intialize_hash(s);

	cout << hashes[0][s.size()-1] << endl;
	cout << hashes[1][s.size()-1] << endl;
	return 0;
}