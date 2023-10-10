//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        queue<pair<int,pair<int,int>>> pq;

        int n=grid.size();

        int m=grid[0].size();

        vector<vector<int>>  dist(n,vector<int>(m,1e9));

        dist[source.first][source.second]=0;
        pq.push({0,{source.first,source.second}});

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!pq.empty()){
          auto it=pq.front();

          pq.pop();

          int dis=it.first;

          int r=it.second.first;
          int c=it.second.second;

          for (int i = 0; i <4; i++)
          {
            /* code */
            int newr=r+dr[i];
            int newc=c+dr[i];
            if(newr>=0 and newr<n and newc>=0 and newc<m and grid[newr][newc]==1 and dis+1<dist[newr][newc]){
              dist[newr][newc]=1+dis;

              if(newr==destination.first  and newc==destination.second){
                return dis+1;
              }

              pq.push({1+dis,{newr,newc}});
            }
          }

        }

        return -1;

    }
};


//{ Driver Code Starts.
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends