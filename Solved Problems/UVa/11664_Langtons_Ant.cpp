#include <bits/stdc++.h>
using namespace std;


void moveRight(int *x) {*x = (*x+1+4)%4;}
void moveLeft(int *x) {*x = (*x-1+4)%4;}
bool validPosition(int x, int y, int n){
    if(x >= 0 and x < n and y >= 0 and y < n) return true;
    return false;
}

int main(int argc, char const *argv[])
{
    /*
    0 -> N
    1 -> E
    2 -> S
    3 -> O
    */
    int n, x, y, face = 0;
    long long c;
    cin >> n >> c >> x >> y;
    while(n != 0 and (c != 0 and (x != 0 and y != 0))){
        char tab[n][n];
        x-=1; y-=1;
        face = 0;
        string s = "";

        for (int i = 1 << n*n-1; i > 0; i = i / 2) 
            s += (c & i)? '1' : '0';
        
        // cout << s << "\n";

        int it = 0;
        for (int i = n-1; i >= 0; i--)
            for (int j = 0; j < n; j++)
            {
                tab[i][j] = s[it++];
            }
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
            {
                cout << tab[i][j] << " ";
            }
            cout << "\n";
        }
        
        bool flag = true;
        
        while(flag){
            if(x == (0) and y == (n-1)){
                flag = false;
                cout << "Yes\n";
                continue;
            }
            // cout << "x = " << x << " y = " << y << "\n";
            if(tab[x][y] == '0') moveLeft(&face);
            else moveRight(&face);

            if(face == 0 and validPosition(x-1, y, n)) x -= 1;
            else if(face == 1 and validPosition(x, y+1, n)) y += 1;
            else if(face == 2 and validPosition(x+1, y, n)) x+=1;
            else if(face == 3 and validPosition(x, y-1, n)) y-=1;
            else{
                flag = false;
                cout << "Kaputt!\n";
            }
        }
        cin >> n >> c >> x >> y;
    }
        
    return 0;
}
