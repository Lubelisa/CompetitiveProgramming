#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int ans = 0;
        for(int i = 1; i < A.size(); i++){
            if(A[i-1] < A[i]){
                if(ans == 0){
                    ans = 1;
                }
                else if(ans == 2){
                    return false;
                }
            }
            else if(A[i-1] > A[i]){
               if(ans == 0){
                    ans = 2;
                }
                else if(ans == 1){
                    return false;
                } 
            }
        }
        
        return true;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}