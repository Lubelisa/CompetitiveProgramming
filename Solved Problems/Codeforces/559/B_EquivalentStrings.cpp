#include <bits/stdc++.h>
using namespace std;
 
bool solve(string a, string b){
	if(a == b)return true;
	if(a.size()%2 == 1)return false;
 
	string a1 = a.substr(0, a.size()/2);
	string a2 = a.substr(a.size()/2, a.size());	
	string b1 = b.substr(0, b.size()/2);
	string b2 = b.substr(b.size()/2, b.size());
 
	if(a1 == b2 and b1 == a2) return true;
	if(a1.size() == 1)return false;
 
	return (solve(a1, b2) and solve(a2, b1)) or (solve(a1, b1) and solve(a2, b2));
}
 
int main(int argc, char const *argv[])
{
	string a, b;
	cin >> a >> b;
 
	if(solve(a, b)){
		cout << "YES";
	}
	else cout << "NO";
 
	return 0;
}