#include <iostream>
 
using namespace std;
 
int main() {
    int t; cin >> t;
    while(t--){
        long long n; cin >> n;
        long long ans = 0;
        while((int)(n/10) > 0){
            long long spend = (long long)(n - n%10);
            ans += spend;
            n -= spend;
            n += (long long)(spend/10);
        }
        ans += n;
        cout << ans << endl;
    }
    return 0;
}