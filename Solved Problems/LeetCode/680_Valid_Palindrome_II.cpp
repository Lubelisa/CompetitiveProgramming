#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        return solve(s, 0, s.size()-1, false);   
    }
    
    bool solve(string s, int i, int j, bool found_error){
        for(; i < j; i++, j--){
            if(s[i] != s[j]){
                if(found_error == true)return false;
                else{
                    return solve(s, i+1, j, true) or solve(s, i, j-1, true);
                }
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
	Solution sol;

	cout << sol.validPalindrome("abca") << "\n";
	cout << sol.validPalindrome("aba") << "\n";
	cout << sol.validPalindrome("socorrrrrammesubinoonibusemmarrrocos") << "\n";

	return 0;
}