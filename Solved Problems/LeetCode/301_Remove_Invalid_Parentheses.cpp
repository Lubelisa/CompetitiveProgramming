// DOES NOT WORK YET

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool verifyExpression(string s, int &open, int &close){
        // int open = 0, close = 0;
        open = close = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i]  == '('){
                open++;
            }
            else if(s[i] == ')'){
                if(open > 0){
                    open--;
                }
                else{close++;}
            }   }
        
        if(open > 0 or close > 0){
            return false;
        }
        else
            return true;
    }
    
    vector<string> removeInvalidParentheses(string s) {
        // Creating a set, queue and auxiliary variables
        set<string> st;
        queue<string> q;
        queue<pair<int, int>> qp;
        int sopen = 0, sclose = 0;
        
        // Checking if s is already a valid string
        if(verifyExpression(s, sopen, sclose)){
            vector<string> ans;
            ans.push_back(s);
            return ans;
        }
        
        
        // Computing all possible expressions
        q.push(s);
        qp.push(make_pair(sopen, sclose));
        
        while(!q.empty()){
            s = q.front(); q.pop();
            pair<int,int> pr = qp.front(); qp.pop();

            if(verifyExpression(s, sopen, sclose)){
                st.insert(s);
                continue;
            }
            else{
                for(int i = 0; i < s.size(); i++){
                    
                    if((s[i] == '(' and pr.first > 0) or (s[i] == ')' and pr.second > 0)){
                        string temp = s.substr(0,i) + s.substr(i+1,s.size()-i-1);
                        q.push(temp);
                        qp.push(make_pair(pr.first - (s[i] == '('), pr.second - (s[i] == ')')));
                    }
                }
            }
        }

        // At this point I will have a set with the valid combinations
        vector<string> ans(st.begin(), st.end());

        if(ans.empty()) ans.push_back("");

        return ans;  
    }
};

int main(int argc, char const *argv[])
{
    Solution sl;
    string s = "((()())((()())()()(()(";
    vector<string> ans = sl.removeInvalidParentheses(s);

    // cout << ans.size() << "\n";

    for(auto i : ans){
        cout << i << "\n";
    }

    return 0;
}