#include <bits/stdc++.h>
using namespace std;

long long n, a, b, k;


bool compare (long long x, long long y){
	return ((x%(a+b)) < (y%(a+b)));
}

int main(int argc, char const *argv[])
{
	cin >> n >> a >> b >> k;
	printf("%s\n", );

	vector<long long> v;

	long long x;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end(), compare);

	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << v[i] << " \n"[i == (n-1)];
	// }

	long long ans  = 0;

	for (int i = 0; i < n; ++i)
	{
		long long rest = v[i]%(a+b);
		if (rest <= a and rest > 0)
		{
			ans++;
			cout << "hey1 k = " << k << endl;
		}
		else if (rest == 0)
		{
			if (k >= ceil(b/a))
			{
				k -= ceil(b/float(a));
				ans++;
			cout << "hey2 k = " << k << endl;

			}
		}
		else{
			if (k >= ceil(rest/a))
			{
				k -= ceil(rest/a);
				ans++;
			cout << "hey3 k = "<< k << endl;

			}
		}
	}

	cout << ans << endl;

	return 0;
}