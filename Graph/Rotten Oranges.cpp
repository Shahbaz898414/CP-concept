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

		queue <pair< pair<int, int>, int >> q;
		int vis[n][m];

		for (int i = 0; i < n; i++)
		{
			/* Die here   */
			for (int j = 0; j < m; j++)
			{
				/* Die here   */

				if (grid[i][j] == 2)
				{
					q.push({{i, j}, 0});
					vis[i][j] = 2;
				}
				else
				{
					vis[i][j] = 0;
				}
			}
		}

		int tm = 0;

		int drow[] = {-1, 0, +1, 0};
		int dcol[] = {0, 1, 0, -1};

		while (!q.empty())
		{
			int r = q.front().first.first;
			int c = q.front().first.second;

			int t = q.front().second;
			tm = max(tm, t);
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nrow = r + drow[i];
				int ncol = c + dcol[i];
				if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and vis[nrow][ncol] != 2 and grid[nrow][ncol] == 1)
				{
					q.push({{nrow, ncol}, t + 1});
					vis[nrow][ncol] = 2;
				}
			}
		}


		for (int i = 0; i < n; i++)
		{
			/* code */
			for (int j = 0; j < m; j++)
			{
				/* code */
				if(vis[i][j]!=2 and grid[i][j]==1){
					return -1;
				}
			}
			
		}

		return tm;
		
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
			for (int j = 0; j < m; j++)

				cin >> grid[i][j];

		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
