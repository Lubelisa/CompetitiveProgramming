#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int carry = 0;
        int n = num1.size(), m = num2.size(), i, j;
        for(i = n-1, j = m-1; i >= 0 and j >= 0; i--, j--){
            int val = (num1[i] - '0') + (num2[j] - '0') + carry;
            // cout << "val = " << val << '\n';
            carry = val/10;
            val = val%10;
            
            char c = '0' + val;
             // cout << "c = " << c << '\n';
            ans = c + ans;
        }
        // cout << "ans = " << ans << '\n';
        if(n != m){
            if(n > m){
                while(i >= 0){
                    int val = (num1[i] - '0') + carry;
                    carry = val/10;
                    val = val%10;
                    
                    char c = '0' + val;
                    ans = c + ans;
                    i--;
                }
            }
            else{
                while(j >= 0){
                    int val = (num2[j] - '0') + carry;
                    carry = val/10;
                    val = val%10;
                    
                    char c = '0' + val;
                    ans = c + ans;
                    j--;
                }
            }
        }
        if(carry > 0){
            char c = '0' + carry;
            ans = c + ans;
        }
        return ans;
    }
// 29 + 57 =     
// 9 + 7 = 16 -> ans = "...6"
// 2 + 5 = 7 + 1 -> ans = "86"
};

int main(int argc, char const *argv[])
{
    string num1 = "1", num2 = "9";
    Solution sol;
    cout << sol.addStrings(num1, num2) << '\n';
    return 0;
}