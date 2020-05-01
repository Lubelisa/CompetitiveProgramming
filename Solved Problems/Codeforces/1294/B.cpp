#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char const *argv[])
{
	int t; cin >> t;
 
	while(t--){
		int n; cin >> n;
		vector<pair<int, int> >v;
		pair<int, int> p;
		string s;
 
		while(n--){
			cin >> p.first >> p.second;
			v.push_back(p);
		}
 
		sort(v.begin(), v.end());
 
		pair<int, int> aux(0, 0);
		bool flag = true;
		for(int i = 0; i < v.size(); i++){
			if(v[i].first >= aux.first && v[i].second >= aux.second){
				for(int j = 0; j < (v[i].first - aux.first); j++) s+="R";
				for(int j = 0; j < (v[i].second - aux.second); j++) s+="U";
				aux = v[i];
			}
			else{
				cout << "NO\n";
				flag = false;
				break;
			}
		}
 
		if(flag){
			cout << "YES\n" << s << endl;
		}
	}
 
	return 0;
}