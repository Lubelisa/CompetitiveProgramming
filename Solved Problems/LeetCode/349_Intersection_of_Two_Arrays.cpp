#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ans;
        unordered_set<int> s_nums1(nums1.begin(), nums1.end());
        
        for(int i : nums2){
            if(s_nums1.find(i) != s_nums1.end()){
                ans.insert(i);
            }
        }
        
        vector<int> v(ans.begin(), ans.end());  
        
        return v;
    }
};

int main(int argc, char const *argv[])
{
	Solution sol;
	vector<int> nums1{4,9,5};
	vector<int> nums2{2,2};

	vector<int> ans = sol.intersection(nums1, nums2);

	for(int i : ans){
		cout << i << ' ';
	}
	cout << '\n';

	return 0;
}