#include <iostream>

using namespace std;

unsigned long long DP[30001];
int coins[] = {1, 5, 10, 25, 50};

int main()
{
    DP[0] = 1;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = coins[i]; j <= 30000; ++j)
        {
            DP[j] += DP[j - coins[i]];
        }
    }
    int n;
    while (cin >> n)
    {
        if (DP[n] == 1)
            cout << "There is only 1 way to produce " << n << " cents change.\n";
        else
            cout << "There are " << DP[n] << " ways to produce " << n << " cents change.\n";
    }
}