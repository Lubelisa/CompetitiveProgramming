#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v;
    
    int n; cin >> n;
    int p[2] = {0, 0};
    
    while(n--){
        int s; cin >> s;
        int x; 
      
        for(int i = 0; i <= (s/2 - 1); i++){
            cin >> x;
            p[0] += x;
        }
        
        if(s%2 == 1){
            cin >> x;
            v.push_back(x);
        }
        
        for(int i = ((s%2 == 0) ? (s/2) : (s/2)+1); i < s; i++){
            cin >> x;
            p[1] += x;
        }
         
    }
    
    sort(v.begin(), v.end());
    
    int gamer = 0;
    
    for(int i = (v.size() - 1); i >= 0; i--){
        p[gamer] += v[i];
        gamer = (gamer+1)%2;
    }
    
    cout << p[0] << " " << p[1] << endl;
    return 0;
}