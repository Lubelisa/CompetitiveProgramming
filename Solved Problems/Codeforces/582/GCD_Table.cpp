#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<ll, int> mp;
set<ll> s;
ll val[501];

ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a%b);}

int main(){
    
    int N, x; cin >> N;
    
    for(int i = 0; i < N*N; i++){
        cin >> x;
        mp[-x]++;
        s.insert(-x);
    }
    int last = N-1;
    for(ll aux : s){
        x = -aux;
        while(mp[aux] > 0){
            cout << x << ' ';
            val[last] = x;
            for(int i = last+1; i < N; i++){
                int y = gcd(val[i], x);
                mp[-y]-=2;
            }
            last--;
            mp[aux]--;
        }
    }
    
    
    
    
    
    return 0;
}