#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}