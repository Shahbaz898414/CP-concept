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