

#include <bits/stdc++.h>
using namespace std;


class Solution {

  void dfs(int row,int col,vector<vector<int>> &mat,int delrow[],int delcol[]){
      mat[row][col]=0;

      int n=mat.size();
      int m=mat[0].size();

      for (int i = 0; i < 4; i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow>=0 and nrow<n and ncol>=0 and ncol<m  and mat[nrow][ncol]==1)
          dfs(nrow,ncol,mat,delrow,delcol);
      }
    
  }


  public:
    int numberOfEnclaves(vector<vector<int>> &mat) {

      int delrow[]={-1,0,+1,0};
      int delcol[]={0,1,0,-1};

      int n=mat.size();
      int m=mat[0].size();

      for (int i = 0; i < n; i++)
      {
        
        for (int j = 0; j < m; j++)
        {
          if(i==0 || j==0 || j==m-1 || i==n-1){
            if(mat[i][j]==1) dfs(i,j,mat,delrow,delcol);
          }
        }
        
      }


      
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] == 1)
                cnt++;
            }
        }

        return cnt;
      

    }
};




int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}


