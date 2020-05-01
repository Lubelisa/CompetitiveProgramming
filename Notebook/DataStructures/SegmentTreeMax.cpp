#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define N 131072

int st[2*N + 1];
int n;
/*Insert a element on the tree*/
void update(int pos, int value){
    pos += n+1;
    st[pos] = value;

    while(pos > 0){
        pos /= 2;
        st[pos] = max(st[2*pos], st[2*pos + 1]);
    }
}

/*Allows you to find the largest element of a range*/
int query(int l, int r){
    int s = 0;

    l += n+1; r += n+1;

    while(l <= r){
       s = max(s, max(st[l], st[r]));
       if(l % 2 == 1) l++;
       if(r % 2 == 0) r--;
       l /= 2; r /= 2; 
    }

    return s;
}

int main(int argc, char const *argv[])
{
  cin.sync_with_stdio(false);
  cin >> n;

  for (int i = 1; i <= n; ++i)
    {
        int x; cin >> x;
        update(i, x);
    }

  for (int i = 2; i <= n; ++i)
    cout << "max(" << 1 << ", " << i << ") = " << query(1, i) << endl;
  return 0;
}