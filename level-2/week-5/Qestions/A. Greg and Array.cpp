#include <bits/stdc++.h>
#define ll long long
using namespace std;



int main() {
  ll n, m, q, a[100004], b[100004], c[100004], d[100004], l[100004], r[100004], i, x, y;

  cin >> n >> m >> q;


  for (i = 1; i <= n; i++)
    cin >> a[i];

  
  for (i = 1; i <= m; i++)
  {
    cin >> l[i] >> r[i] >> d[i];
  }


  while (q--)
  {
    cin >> x >> y;
    b[x]++;
    b[y + 1]--;
  }
  for (i = 1; i <= m; i++)
    cout<<b[i]<<" ";

  cout<<"before b"<<endl;
  for (i = 2; i <= m; i++)
    b[i] += b[i - 1];

  for (i = 1; i <= m; i++)
   cout<< b[i] << " ";

  cout<<"after b"<<endl;

  for (i = 1; i <= m; i++)
  {
    c[l[i]] += (b[i] * d[i]);
    c[r[i] + 1] -= (b[i] * d[i]);
  }

  for (i = 1; i <= m; i++)
  {
    cout<<c[i]<< " ";
  }

  cout<<"before c"<<endl;


  for (i = 2; i <= n; i++)
    c[i] += c[i - 1];

  for (i = 1; i <= m; i++)
  {
    cout<<c[i]<< " ";
  }


  cout<<"after c"<<endl;

  for (i = 1; i <= n; i++)
    cout << a[i] + c[i] << " ";



}

/*


#include<iostream>
#include<vector>
#define pb push_back
#define ll long long
using namespace std;
ll n,m,q,a[100004],b[100004],c[100004],d[100004],l[100004],r[100004],i,x,y;
int main()
{

  cin>>n>>m>>q;
  for(i=1;i<=n;i++) cin>>a[i];
  for(i=1;i<=m;i++)
  {
    cin>>l[i]>>r[i]>>d[i];
  }
  while(q--)
  {
    cin>>x>>y;
    b[x]++;
    b[y+1]--;
  }
  for(i=2;i<=m;i++)
      b[i]+=b[i-1];
  for(i=1;i<=m;i++)
  {
    c[l[i]]+=(b[i]*d[i]);
    c[r[i]+1]-=(b[i]*d[i]);
  }
  for(i=2;i<=n;i++)
    c[i]+=c[i-1];
  for(i=1;i<=n;i++)
    cout<<a[i]+c[i]<<" ";


}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



*/