#include <bits/stdc++.h>

using namespace std;

#define in(x) cin >> x;
#define out(x) cout << x << endl;

#define ll long long

int v[100001];

int find(int letter){
	if(v[letter] == letter)
		return letter;
	return v[letter] = find(v[letter]);
}

typedef struct st{
	char l1, l2;
}ST;

vector<pair<char, char> > ans;

int main(int argc, char const *argv[])
{
	cin.sync_with_stdio(false);

	int n;
	in(n);
	string s1, s2;
	in(s1);
	in(s2);

	for (int i = 0; i < 50; ++i)
	{
		v[i] = i;
	}

	for (int i = 0; i < n; ++i)
	{
		
		int x, y;
		x = find(s1[i] - 'a');
		y = find(s2[i] - 'a');

		// out(x);
		// out(y);
		if (x != y)
		{
			v[x] = y;
			ans.push_back(make_pair(s1[i], s2[i]));
		}
	}

	out(ans.size());

	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i].first << " " << ans[i].second << endl;
	}

	return 0;
}