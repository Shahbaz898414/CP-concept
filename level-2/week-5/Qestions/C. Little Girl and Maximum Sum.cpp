#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main()
{
  int n, q;
  cin >> n >> q;
  ll arr[n];

  for (ll i = 0; i < n; i++)
  {
    /* code */
    cin >> arr[i];
  }

  while (q--)
  {
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



*/
