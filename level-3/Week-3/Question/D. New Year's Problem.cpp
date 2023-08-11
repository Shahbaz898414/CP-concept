#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1000000009;


const int mx = 1e6;


ll a[mx];
ll b[mx];





int main()
{

  ll n,m;
  cin >> n>>m;

  vector<vector<ll>> v(n,vector<ll>(m));
  



  return 0;
}


/*

#include<bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
using namespace std;
int a[100005];
int c[100005];
int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--) {
		int m,n;
		cin>>m>>n;
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
		for(int pp=0; pp<m; pp++) {
			int s[100005];
			for(int i=0; i<n; i++) {
				cin>>s[i];
				if(s[i]>a[i]) a[i]=s[i];
			}
			sort(s,s+n);
			c[pp]=s[n-2];
		}
		sort(a,a+n);
		sort(c,c+m);
		cout<<min(a[0],c[m-1])<<endl;
	}
	return 0;
}



*/


/*

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t,m,n;

int main()
{
	cin >> t;
	while(t--){
		cin >> m >> n;
		vector<int> max(n,0),scmax;
		for (int i=0; i<m; i++)
		{
			int x[n];
			for (int i=0; i<n; i++)
			{
				cin >> x[i];
				if (x[i]>max[i]) max[i]=x[i];
			}
			sort(x,x+n);
			scmax.push_back(x[n-2]);
		}
		sort(scmax.begin(),scmax.end());
		sort(max.begin(),max.end());
		
		//Phan tu nho nhat cua max la max[0]
		//Phan tu lon nhat cua scmax la scmax[m-1]
		int res = (max[0] < scmax[m-1]) ? max[0] : scmax[m-1];
		cout << res << endl;
	}
	return 0;
}


*/


/*

#include <bits/stdc++.h>
#define N 100005
#define ll long long int
#define pii pair <int, int>
#define pb push_back
#define ff first
#define ss second
using namespace std;

int t, n, m, mx, ans; 
vector <int> v;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--){
		cin >> n >> m;
		vector <vector<int>> a(n + 10, vector<int>(m + 10));
		ans = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++) cin >> a[i][j];
		}
		for (int j = 1; j <= n; j++){
			v = a[j];
			sort(v.begin(), v.end(), greater<int>());
			ans = max(ans, v[1]);
    	}
    	for (int j = 1; j <= m; j++){
			mx = 0;
			for (int k = 1; k <= n; k++) mx = max(mx, a[k][j]);
			ans = min(ans, mx);
    	}
    	cout << ans << endl;
	}
}

*/









/*


#include<bits/stdc++.h>
#define lhr long long
using namespace std;
lhr t,n,m,a[200005],b,l=0,r=1000000000;
bool check(int x){
    for(int i=1;i<=n;++i){
        int f=1;
        for(int j=1;j<=m;++j)
            if(a[(j-1)*n+i]>=x) f=0;
        if(f) return 0;
    }
    for(int i=1;i<=m;++i){
        int cnt=0;
        for(int j=1;j<=n;++j)
            if(a[(i-1)*n+j]>=x) cnt++;
        if(cnt>=2) return 2;
    }
    return 0;
}
int main(){
    cin>>t;
    while(t--){
        cin>>m>>n;
        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j) cin>>a[(i-1)*n+j];
        l=0,r=1000000000;
        while(l<r){
            int mid=(l+r)/2;
            if(check(mid+1)) l=mid+1;
            else r=mid;
        }
        cout<<l<<endl;
    }
    return 0;
}


*/