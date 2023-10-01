#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll nax = 505;
const ll mod = (10e8) + 7;

ll modInverse(ll base, ll exp)
{
  if (exp == 0)
  {
    return 1;
  }

  ll res = modInverse(base, exp / 2);
  if (exp % 2 == 1)
  {
    return (((res * res) % mod) * base) % mod;
  }
  else
  {
    return (res * res) % mod;
  }
}

#define INF 1e9;

int dp[nax][nax];



// 


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll t = 1;
  // cin >> t;

  while (t--) {
    ll n, k, x;
    cin >> n ;
    vector<int> arr(n);

    for (ll i = 0; i < n; i++) {
      cin >> arr[i];
    }

   

  }
  return 0;
}




/*


#include<bits/stdc++.h>
using namespace std;
const int N = 5008;
int n;
int a[N],dp[N][N][2];

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=2;i<=n;++i)
	{
		for(int j=1;j+i-1<=n;++j)
		{
			int l=j,r=j+i-1;
			dp[l][r][0]=min(dp[l+1][r][0]+(a[l]!=a[l+1]),dp[l+1][r][1]+(a[l]!=a[r]));
			dp[l][r][1]=min(dp[l][r-1][0]+(a[r]!=a[l]),dp[l][r-1][1]+(a[r-1]!=a[r]));
		}
	}
	cout<<min(dp[1][n][0],dp[1][n][1])<<endl;
}








*/