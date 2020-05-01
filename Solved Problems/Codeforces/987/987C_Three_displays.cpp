#include <bits/stdc++.h>

using namespace std;

#define in(x) cin >> x;
#define out(x) cout << x << endl;

#define ll long long

ll s[30003], c[30003], m[30003];
ll n, i, j, k;

int main(int argc, char const *argv[])
{
	cin.sync_with_stdio(false);

	in(n);

	for (i = 0; i < n; ++i)
	{
		in(s[i]);
		m[i] = 0x3f3f3f3f;
	}

	for (i = 0; i < n; ++i)
	{
		in(c[i]);
	}

	ll ans = 0x3f3f3f3f;

	for (i = 1; i < n; ++i)
	{
		for (j = 0; j < i; ++j)
		{
			if (s[j] < s[i])
			{
				m[i] = min(m[i], c[j] + c[i]);
				ans = min(ans, m[j] + c[i]);
			}
		}
	}

	if (ans == 0x3f3f3f3f)
	{
		out(-1);
	}
	else{
		out(ans);
	}
	return 0;
}