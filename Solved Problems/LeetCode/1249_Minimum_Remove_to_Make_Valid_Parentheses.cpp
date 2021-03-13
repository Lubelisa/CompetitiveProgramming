#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open_ones = 0, close_ones = 0;
        int n = s.size();
        int i = 0;
        while(i < n){
            // cout << s << "\n" << s[i] << '\n';
            // cout << "i = " << i << '\n';
            if(s[i] == '('){
                open_ones++; i++;
            }
            else if(s[i] == ')'){
                if(open_ones > 0){
                    open_ones--; i++;
                }
                else{
                    s.erase(s.begin()+i);
                    n = s.size();
                }
            }
            else i++;
        }
        // cout << s << '\n';
        i = n-1;
        while(i >= 0){
            // cout << "chegou aqui\n";
            if(s[i] == ')'){
                close_ones++; i--;
            }
            else if(s[i] == '('){
                if(close_ones > 0){
                    close_ones--; i--;
                }
                else{
                    s.erase(s.begin()+i);
                    n = s.size(); i--;
                }
            }
            else i--;
        }
        
        
        return s;
    }
};

int main(int argc, char const *argv[])
{
    string s = "(a(b(c)d)";
    Solution sol;
    cout << sol.minRemoveToMakeValid(s) << '\n';
    return 0;
}