/*
n: array size
m: num of different keys in the array

Complexity:
To build the map: O(n*logn)
To build the set: O(n)
To checking the keys: O(m*k)

O(n*logn + n + m*k)

*/

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if((float)(nums.size()/k) != 0.0) return false;
        map<int,int> mp;
        unordered_set<int> st;
        /*
        To build the map: O(n*logn)
        To build the set: O(n)
        */
        for (int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
            st.insert(nums[i]);
        }
        
        int i;
        
        // Complexity of checking the keys: O(m*k)    
        for(map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){//O(m)
            int x = it->first;
            if(mp[x] == 0) continue;
            for(i = 1; i < k; i++)//O(k)
                    //O(1)
                if(st.find(x+i) != st.end() and mp[x+i] > 0 and mp[x] <= mp[x+i]){
                    mp[x+i] -= mp[x];
                }
                else{
                    return false;
                }
                mp[x] = 0;
        }

        
        return true;
    }
};