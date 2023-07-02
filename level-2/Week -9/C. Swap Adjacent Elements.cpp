#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // ll t;cin>>t;

  // while(t--) {

  // }

  ll n, m;
  cin >> n;

  ll total = 0, ans;

  bool fl=false;

  vector<ll> a(n),pos(n+1),pre(n);

  for (int i = 0; i < n; i++)
    cin >> a[i];

  string s;
  cin >> s;

  // ll sum = 0;
  ll len = s.size();
  
  for (int i = 0; i < n; i++) {
    pos[a[i]]=i;
  }
  
  pre[0]=s[0]-'0';

  for (ll i = 1; i <n-1; i++)
  {
    /* code */
    pre[i]+=pre[i-1]+(s[i]-'0');
  }

  pre[n-1]=pre[n-2];

  for (int i = 1; i < n; i++)
  {
    /* code */
    if(pos[i]>pos[i+1]){
      ll l=pos[i+1],r=pos[i];
      ll sum=pre[r-1]-(l-1>=0?pre[l-1]:0);
      if(sum<(r-l)){
        fl=true;
        break;
      }
    }
  }

  if(fl) cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
  
  

  

  return 0;
}













/*


#include <bits/stdc++.h>
using namespace std;
int main()
{
  int i,mxnum=0,n,sum;
  cin>>n;

  int a[n];

  for(i=0;i<n;i++)cin>>a[i];

  string s;cin>>s;


  for (i=0;i<n;i++){

    mxnum=max(mxnum,a[i]);

    if(s[i]=='0'&&mxnum>i+1) {
      cout<<"NO";
      return 0;
    }
  }


  cout<<"YES";

    return 0;
}



*/

