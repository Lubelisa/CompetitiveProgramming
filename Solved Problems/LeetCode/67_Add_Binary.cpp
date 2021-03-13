#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        // a =  "11"
        // b =   "1"
        // c = "100"
        
        bool carry = false;
        int an = a.size();
        int bn = b.size();
        int i = an-1, j = bn-1;
        string c = "";
        
        while(i >= 0 and j >= 0){
            if(a[i] == '1' and b[j] == '1'){
                if(carry == true){
                    c += '1';
                }
                else{
                    c += '0';
                    carry = true;
                }
            }
            else if(a[i] == '1' or b[j] == '1'){
                if(carry == true){
                    c += '0';
                }
                else{
                    c += '1';
                    carry = false;
                }
            }
            else{
                if(carry == true){
                    c += '1';
                    carry = false;
                }
                else{
                    c += '0';
                }
            }
            i--; j--;
        }
        if(an > bn){
            while(i >= 0){
                if(carry == true){
                    if(a[i] == '1'){
                       c += '0'; 
                    }
                    else{
                        c += '1';
                        carry = false;
                    }
                }
                else{
                    c += a[i];
                }
                i--;
            }
        }
        else if(an < bn){
            while(j >= 0){
                if(carry == true){
                    if(b[j] == '1'){
                       c += '0'; 
                    }
                    else{
                        c += '1';
                        carry = false;
                    }
                }
                else{
                    c += b[j];
                }
                j--;
            }
        }

        if(carry == true){
            c += '1';
        }
        reverse(c.begin(), c.end());
        return c;
    }
};

int main(int argc, char const *argv[])
{
    string a = "111111111111111110", b = "1";
    Solution sol;
    cout <<  sol.addBinary(a, b) << '\n';
    return 0;
}