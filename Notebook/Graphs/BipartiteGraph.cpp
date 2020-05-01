int cor[N];

int main(int argc, char const *argv[])
{
    memset(cor, -1, sizeof(cor));

    for (int i = 1; i <= N; ++i)
    {
        if(vis[i] == -1)dfs(i, 0);
    }
    return 0;
}


bool dfs(int u, int c){
    cor[u] = c;

    bool possible = 1;

    for(int v : edges[u]){
        if (cor[v] == -1)
        {
            possible &= dfs(v, !c); //possible = possible & dfs(v, !c);
        }
        else if (cor[v] == c)
        {
            return 0;
        }
    }

    return possible;
}