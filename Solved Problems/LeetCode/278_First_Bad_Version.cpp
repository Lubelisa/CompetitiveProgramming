#include <bits/stdc++.h>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n, mid, min_ = n;
        bool res;
        
        while(l <= r){
            mid = (l+r)/2;
            res = isBadVersion(mid);
            if(res == true){
                min_ = mid;
                r = min_-1;
            }
            else{
                l = mid+1;
            }
        }
        
        return min_;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}