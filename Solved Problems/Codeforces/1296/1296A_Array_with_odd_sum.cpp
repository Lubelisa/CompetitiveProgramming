#include <iostream>
 
using namespace std;
 
int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int odd = 0, even = 0;
        while(n--){
            int x; cin >> x;
            if(x%2 == 0)even++;
            else odd++;
        }
        if(odd == 0 or (odd%2 == 0 and even == 0)){
            cout << "NO" << endl;
        }
        else cout << "YES" << endl;
    }
    return 0;
}