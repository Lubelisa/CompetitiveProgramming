#include <bits/stdc++.h>

using namespace std;

int neg[500005], pos[500005];
int n, max_ = 0, ans = 0;
string s;

bool correct(string s){

}

int main() {
    cin.sync_with_stdio(false);
    cin >> n;
    
    memset(neg, 0, sizeof(neg));
        memset(pos, 0, sizeof(pos));

    while(n--){
        cin >> s; int k = 0;
        stack<char> st;
        int open = 0, close = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')'){
                if (st.size() > 0)
                {
                    open--;
                    st.pop();
                }
                else close++;
                k++;
            }
            else{
                st.push('(');
                open++;
                k--;
            }
        }
        if(open != 0 && close != 0) continue;

        //cout << "k = " << k << endl;

        if(k >= 0){
            pos[k]++;
            //cout << "pos[" << k << "] = " << pos[k] << endl;
        }
        else neg[abs(k)]++;
        
        max_ = max(max_, abs(k));
    }
    // cout << "max = " << max_ << endl;
    ans += pos[0]/2;
    for(int i = 1; i <= max_; i++){
        //cout << "neg[" << i << "] = " << neg[i] << endl;
       //cout << "pos[" << i << "] = " << pos[i] << endl;
        while(neg[i] > 0 && pos[i] > 0){
            neg[i]--; pos[i]--;
            ans++;
        }
    }
    cout << ans;
    return 0;
}