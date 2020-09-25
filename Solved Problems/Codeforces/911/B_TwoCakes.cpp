#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, a, b; cin >> n >> a >> b;
	// int ans = max(a/n, b/n);
	int ans = 0;

	for (int i = 1; i < n; ++i)
	{
		ans = max(ans, min(a/i, b/(n-i)));
	}

	cout << ans;
	return 0;
}