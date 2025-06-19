class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int size = s.size();
        if(size < 3){
            return s;
        }
        ans+=s[0];
        ans+=s[1];
        int ans_count = 1;

        for(int i = 2; i < size; i++){
            if(s[i] == ans[ans_count] && ans[ans_count] == ans[ans_count-1]){
                continue;
            }
            else{
                ans+=s[i];
                ans_count+=1;
            }
        }

        return ans;
    }
};