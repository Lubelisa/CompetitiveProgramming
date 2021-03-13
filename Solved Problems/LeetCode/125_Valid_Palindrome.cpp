#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string s_low = "";
        for (int i = 0; i < n; i++){
            char c = tolower(s[i]);
            if(isalnum(c)){
                s_low += c;
            }
        }

        n = s_low.size();
        for(int i = 0, j = n-1; i < j; i++,j--){
            if(s_low[i] != s_low[j]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    string s = "race a car";
    Solution sol;
    cout << sol.isPalindrome(s) << '\n';
}