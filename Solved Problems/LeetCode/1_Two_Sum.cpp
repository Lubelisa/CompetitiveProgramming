#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int n = nums.size();
      int x, y;
    
      unordered_set<int> st;
    
      for(int i = 0; i < n; i++){
        if(st.find(target-nums[i]) != st.end()){
            x = i;
            break;
        }
        st.insert(nums[i]);
      }
      
      for(int j = 0; j < n; j++){
        if(nums[j] == target-nums[x] and j!=x){
            y = j;
            break;
        }
      }
    
      vector<int> ans;
      ans.push_back(x);
      ans.push_back(y);
        
      return ans;
    
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v;
    v.push_back(3);
    v.push_back(3);
    Solution s;
    v = s.twoSum(v, 6);
    for(auto i : v){
        cout << i << "\n";
    }
    return 0;
}