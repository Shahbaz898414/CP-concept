#include <bits/stdc++.h>
#define int long long
using namespace std;

string s[3], ans = "ZZZ";
bool vis[3][3];

void solve(int x, int y, string str) {
    if (x < 0 || y < 0 || x >= 3 || y >= 3 || vis[x][y]) return;
    vis[x][y] = 1;
    str += s[x][y];
    if (str.size() == 3) {
        ans = min(ans, str);
    } 
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i || j) {
                solve(x + i, y + j, str);
            } 
        }
    }
    vis[x][y] = 0;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    for (int i = 0; i < 3; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            solve(i, j, "");
        }
    }
    cout << ans << endl;
    return 0;
}



/*

Today was my 69th day out of the 100 days  hard challenge.
So today.

Sher ne aaj 5 question solve kiya,
sher ka mid sem exam hone wala hai,
sher fir bhi coding karega .


1. B. YetnotherrokenKeoard (https://codeforces.com/contest/1907/problem/B).


2. A. Easy As ABC  (https://codeforces.com/contest/1906/problem/A).


3. B. Permutation Swap (https://codeforces.com/contest/1828/problem/B)


4. D. Buying Shovels (https://codeforces.com/contest/1360/problem/D).


5. A. k-Factorization (https://codeforces.com/contest/797/problem/A).




#100dayschallenge #challenge #consistency #Cp #lessons #learning
#competitiveprogramming
*/





/*


  int n,k,d=2; 
    cin>>n>>k;
	vector<int> a;
	while (d<=n && k)
	{
		if (k==1) d=n;
		if (n%d==0) 
			n/=d, a.push_back(d), k--;
		else
			d++;
	}
	if (k==0)
		for (int v: a) cout<<v<<' ';
	else
		cout<<-1;


*/