#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fast_exp_logn(ll base, ll e){

	if (e == 0){return 1;}

	ll ans = fast_exp_logn(base, e/2);

	ans = ans*ans;

	if (e%2){ans = ans * base;}
	
	return ans;
}



ll fast_exp_O1(ll base, ll e){
	ll ans = 1;
	while(e > 0){
		if(e%2){
			ans *= base;
		}
		base *= base;
		e = e/2;
	}
	return ans;
}

/* Iterative Function to calculate (x^y)%p in O(log y) */
ll power(ll x, unsigned ll y, ll p)  
{  
    ll res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y%2)  
            res = (res*x) % p;  
  
        // y must be even now  
        y /= 2; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
}

int main(int argc, char const *argv[])
{
	cout << fast_exp_O1(10, 10) << endl;
	return 0;
}