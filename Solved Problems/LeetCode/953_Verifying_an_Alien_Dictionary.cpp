#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> mp;
        for(int i = 0; i < order.size(); i++){
            mp[order[i]] = i;
        }
        
        bool flag_words = true;
            
        for(int i = 1; i < words.size(); i++){
            bool loop_stopper = true;
            bool flag_letters_equal = true;
            for(int j = 0; j < min(words[i-1].size(), words[i].size()) and loop_stopper; j++){
                if(mp[words[i-1][j]] < mp[words[i][j]]){
                    flag_words &= true;
                    flag_letters_equal = false;
                    loop_stopper = false;
                }
                else if(mp[words[i-1][j]] > mp[words[i][j]]){
                    loop_stopper = false;
                    flag_words &= false;
                }
            }
            
            if(flag_words == false) return false;
            
            if(flag_letters_equal == true){
                if(words[i-1].size() > words[i].size()) return false;
            }
        }
        
        return flag_words;
    }

int main() {
    vector<string> words;
    words.push_back("luan");
    words.push_back("luana");
    
    cout << isAlienSorted(words, "abcdefghijklmnopqrstuvwxyz") << endl;
    return 0;
}