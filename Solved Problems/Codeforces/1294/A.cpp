#include <bits/stdc++.h>

using namespace std;
]
int main(){

	int q; cin >> q;//queries

	int a, b, c, n;

	while(q--){
		cin >> a >> b >> c >> n;

		if((a+b+c+n)%3 != 0){//if the sum of the coins are not divisible by 3,
							//it is impossible to divide the coins
			cout << "NO" << endl;
			continue;
		}

		int average = (a+b+c+n)/3;

		if(a > average || b > average || c > average){
			cout << "NO" << endl;/*if one of the children has more coins
									that the average of the division, it is
									also impossible to divide the coins between
									them.*/
			continue; 
		}

		cout << "YES" << endl;/*Unless all of this, it is possible to divide the coins*/
	}

	return 0;
}