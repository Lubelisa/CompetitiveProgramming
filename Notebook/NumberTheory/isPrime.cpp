#include <bits/stdc++.h>

#define ll long long

using namespace std;


ll _sieve_size;

bool bs[10000001];

vector<ll> primes;

void sieve(ll upperbound){
	_sieve_size = upperbound + 1;
	for(ll i = 2; i <= _sieve_size; i++) bs[i] = true;
	bs[0] = bs[1] = false;
	for(ll i = 2; i <= _sieve_size; i++){
		if(bs[i]){
			for(ll j = i*i; j <= _sieve_size; j += i) bs[j] = false;
			primes.push_back(i);
		}
	}
}

bool isPrime(ll N){
	if (N <= _sieve_size) return bs[N];
	
	for(int i = 0; i < (int)primes.size(); i++)
		if(N % primes[i] == 0) return false;

	return true;
}

int main(int argc, char const *argv[])
{
	sieve(10000000);
	return 0;
}