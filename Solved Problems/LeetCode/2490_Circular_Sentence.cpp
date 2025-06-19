class Solution {
public:
    vector<string> splitSentence(string s){
        vector<string> tokens;
        size_t initpos = 0;
        size_t endpos = 0;
        string token;
        endpos = s.find(" ", initpos);
        while(endpos != string::npos){
            token = s.substr(initpos, endpos-initpos);
            tokens.push_back(token);
            initpos = endpos+1;
            endpos = s.find(" ", initpos);
        }
        tokens.push_back(s.substr(initpos, s.size()-initpos+1));
        return tokens;
    }

    bool isCircularSentence(string sentence) {
        vector<string> tokens = splitSentence(sentence);
        for(int i = 1; i < tokens.size(); i++){
            if (tokens[i-1][tokens[i-1].size()-1] != tokens[i][0]){
                return false;
            }
        }
        if(tokens[tokens.size()-1][tokens[tokens.size()-1].size()-1] != tokens[0][0]){
            return false;
        }
        return true;
    }
};