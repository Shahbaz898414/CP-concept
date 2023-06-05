#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  int n, q;
  cin >> n >> q;
  long long a[200010] = {}, cnt[200010] = {}, f = 0;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 1; i <= q; i++)
  {
    cin >> l >> r;
    cnt[l]++;
    cnt[r + 1]--;
  }
}

/*
#include<bits/stdc++.h>
using namespace std;
int n,q,l,r,i;

int main()
{
long long a[200010]={},t[200010]={},f=0;
cin>>n;
cin>>q;
for(i=0;i<n;i++)cin>>a[i];
sort(a,a+n);

for(i=0;i<q;i++)cin>>l>>r,t[l-1]++,t[r]--;
for(i=1;i<n;i++)t[i]+=t[i-1];
sort(t,t+n);
for(i=0;i<n;i++)f+=a[i]*t[i];
cout<<f<<endl;
}

/////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
long long a[200005],n,q, cnt[200005],l, r;
long long d;
int main(){
  cin>>n>>q;
  for (int i=1;i<=n;i++)cin>>a[i];
  for (int i=1;i<=q;i++){
  cin>>l>>r;
  cnt[l]++;
  cnt[r+1]--;
  }
  for(int i=1;i<=n;i++)cnt[i]=cnt[i-1]+cnt[i];
  sort(cnt+1,cnt+n+1);
  sort(a+1,a+n+1);
  for(int i=1;i<=n;i++)d+=(cnt[i]*a[i]);
  cout<<d;
  return 0;
}




*/
