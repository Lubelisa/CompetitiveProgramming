#include <bits/stdc++.h>

using namespace std;

int x_next[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int y_next[8] = {1, -1, 0, 0, 1, -1, 1, -1};

int N;
char letters[30][30];
set<string> st;


void clear_all(){
    st.clear();
}

bool violate_borders(int x, int y){
    if(x < 0 or y < 0 or x >= N or y >= N)return true;
    return false;
}

void solve(string s, int x, int y, map<pair<int,int>,short> vis){
    // cout << "x = " << x << " y = " << y << '\n';
    vis[make_pair(x,y)] = 1;
    if(s.size() >= 3){
        st.emplace(s);
    }

    for(short aux = 0; aux < 8; aux++){
        if(violate_borders(x+x_next[aux], y+y_next[aux]) == false and vis[make_pair(x+x_next[aux], y+y_next[aux])] == 0 and
            letters[x][y] < letters[x+x_next[aux]][y+y_next[aux]]){
            solve(s+letters[x+x_next[aux]][y+y_next[aux]], x+x_next[aux], y+y_next[aux], vis);
        }
    }
}

bool compare(string r, string s){
    int rs = r.size();
    int ss = s.size();
    if(rs > ss){
        return false;
    }
    else if(rs < ss){return true;}
    else{
        if(r < s) return true;
        return false;
    }
}


int main(int argc, char const *argv[])
{
    cin.sync_with_stdio(false);

    int t; cin >> t;
    while(t){
        cin >> N;

        for(int i = 0; i < N; i++){
            cin >> letters[i];
        }

        map<pair<int, int>, short> vis;
        string word = "";
        
        for(int i = 0; i < N; i++)
            for(int j = 0;  j < N; j++)
                solve(word+letters[i][j], i, j, vis);

        vector<string> v;
        for(string x : st){
            v.push_back(x);
        }

        sort(v.begin(), v.end(), compare);

        for(string s : v){
            cout << s << '\n';
        }

        if(t-- > 1)cout << '\n';
        clear_all();
    }
    return 0;
}
