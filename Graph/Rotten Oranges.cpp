//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int orangesRotting(vector<vector<int>> &grid)
	{
		//  Die here
		int n = grid.size();
		int m = grid[0].size();

		queue << pair<int, int>, int >> q;
		vector<vector<int>> vis;

		for (int i = 0; i < n; i++) {
			/*    */
			for (int j = 0; j < m; j++) {
				/*    */

				if (grid[i][j] == 2) {
					q.push({{i,j},0});
					vis[i][j]=2;
				}
			}
		}

		int tm=0;

		while(!q.empty()){
			int r=q.front().first.first;
			int c=q.front().first.second;

			int t=q.front().second;

			q.pop();


		}




	}
};

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int>> grid(n, vector<int>(m, -1));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
