#include <bits/stdc++.h>
 
using namespace std;
 
 
int main(int argc, char const *argv[])
{
	
    int t; cin >> t;
    
 
    while(t--){
        int n; cin >> n;
        set<int> v;
        for(int i = 2; i <= (int)sqrt(n); i++){
            if(n%i == 0){
                v.insert(i);
                n /= i;
            }
            if(v.size() == 2){
                if(n > 1){
                    v.insert(n);
                    break;
                }
            }
            
        }
 
        if(v.size() == 3){
            cout << "YES\n";
            set<int>::iterator it;
            for(it = v.begin(); it != v.end(); it++){
                cout << *it << " ";
            }
            cout << endl;
        }
        else cout << "NO" << endl;
    }
 
 
	return 0;
}