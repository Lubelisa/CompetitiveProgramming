#include <bits/stdc++.h>
using namespace std;

vector<int> v;


int main(int argc, char const *argv[])
{
    int x, case_ = 1;
    int bSequence = 1;
    while(true){
        while (cin >> x and x != -1)
        {
            v.push_back(x);
        }
        
        if(v.size() > 0){
            int n = v.size();
            int lds[n] = {1};
            bSequence = 1;
            for (int i = 0; i < n; i++)
            {
                lds[i] = 1;
                for (int j = 0; j < i; j++)
                {
                    if(v[i] <= v[j] and (lds[j] + 1) > lds[i]){
                        lds[i] = lds[j] + 1;
                        if(lds[i] > bSequence) bSequence = lds[i];
                    }
                }
            }
            cout << "Test #" << case_ << ":\n  maximum possible interceptions: " << bSequence << "\n";
            case_++;
        }

        v.clear();
        cin >> x;
        if(x == -1) break;
        else{
            cout << '\n';
            v.push_back(x);
        }
    }
    return 0;
}
