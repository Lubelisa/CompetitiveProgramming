class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
         int m = grid[0].size();
         int counter = 0;
         for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                 if(grid[i][j] == '1'){
                    // cout << "i = " << i << " j = " << j << '\n';
                    DFS(grid, n, m, i, j);
                    counter++;
                 }
             }
         
           }
        return counter;
    }
    
    
    void DFS(vector<vector<char>>& grid, int n, int m, int i, int j){
        grid[i][j] = '2';// Visited
        // cout << "grid[" << i << "][" << j << "] = " << grid[i][j] << '\n';
        if(i+1 < n and grid[i+1][j] == '1'){
          DFS(grid, n, m, i+1, j);
        }
        if(j+1 < m and grid[i][j+1] == '1'){
          DFS(grid, n, m, i, j+1);
        }
        if(i-1 >= 0 and grid[i-1][j] == '1'){
          DFS(grid, n, m, i-1, j);
        }
        if(j-1 >= 0 and grid[i][j-1] == '1'){
          DFS(grid, n, m, i, j-1);
        }
    }
};