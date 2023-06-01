#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ll t;
  cin >> t;

  while (t--)
  {
    ll n;
    cin >> n;

    
    ll arr[n],l[n]={0},r[n]={0},f=0;

    for (int i = 0; i < n; i++) {
      cin>>arr[i];
    }

    for (int i = 0; i < n; i++)
    {
      
      if(arr[i]>=i) l[i]=1;
      else break;
    }

    for (int i = n-1; i >=0; i--)
    {
      
      if(arr[i]>=n-i-1) r[i]=1;
      else break;
    }

    for (int i = 0; i < n; i++)
    {
      
      if(l[i] and r[i]) f=1;
    }

    if(f)  cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    
  }
}