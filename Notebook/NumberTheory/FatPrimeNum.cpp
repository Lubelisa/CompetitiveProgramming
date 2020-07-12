#include <bits/stdc++.h>
using namespace std;

map<int, int> FatPrimes(int N){
    map<int, int> ans;
    int aux = N;
    for(int i = 2; i <= N; i++){
        while (aux % i == 0)
        {
            ans[i]++;
            aux /= i;
        }
        
    }

    if(aux > 1){
        ans[aux] = 1;
    }

    return ans;
}


int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
