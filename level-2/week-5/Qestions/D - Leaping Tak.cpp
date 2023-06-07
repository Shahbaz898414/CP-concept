

#include <bits/stdc++.h>
using namespace std;


typedef  long long ll;
const ll mod=998244353;



int main()
{
  int n, m;
  cin >> n >> m;
  vector<pair<int,int>>  v(m);

  for (int i = 0; i < m; i++) {
    cin>>v[i].first>>v[i].second;
  }

  vector<long long>  sum(n+1);
  sum[1]=1;

  for (int i =2; i <=n; i++)
  {
    /* code */
    long long cur=0;

    for(int  j=0;j<m;i++) {
      if(v[j].first>=i)  continue;

      int l=max(1,i-v[i].second);
      int r=i-v[j].first;

      cur+=sum[r]-sum[l];

      
    }

    cur%=mod;

    if(cur>0) cur+=mod;

    sum[i]=(sum[i-1]+cur)%mod;
  }

  ll ans=sum[n]-sum[n-1];

  if(ans<0)  ans+=mod;

  cout<<ans<<endl;
  
  
  return 0;
}