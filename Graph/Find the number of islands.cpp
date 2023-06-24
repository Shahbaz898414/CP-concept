
#include <bits/stdc++.h>
using namespace std;




class Solution {
  public:
    
    int numIslands(vector<vector<char>>& grid) {
       int n=grid.size();
       int m=grid[0].size();

       vector<vector<int>> vis(n,vector<int>(m,0));

       for (int row = 0; row <n; row++)
       {

          for (int col = 0; col < m; col++)
          {
            if(!vis[row][col]){
              cnt++;

              bfs(row,col,vis,grid);
            }
          }
          
       }

       return cnt;
       
    }
};





int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}



