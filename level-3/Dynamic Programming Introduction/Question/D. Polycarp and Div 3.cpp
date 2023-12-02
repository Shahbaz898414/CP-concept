#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = (10e8) + 7;

// ll   f[2][100001],a[2][100001];

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;cin>>s;

  ll len=s.size();

  // cout<<len;

  vector<ll>  arr(len,0);

  for (ll i = 0; i < len; i++)
  {
    /* code */
    arr[i]=(s[i]-'0')%3;
  }

  ll ans=0;
  int i=0;

  while (i<len)
  {
    /* code */
    if(arr[i]==0){
      i++;
      ans++;
    }else if(i<len-1 and arr[i]==2 and arr[i+1]==1){
      ans++;
      i+=2;
    }else if(i<len-1 and arr[i]==1 and arr[i+1]==2){
      ans++;
      i+=2;
    }else if(i<len-2 and arr[i]==1 and arr[i+1]==1 and arr[i+2]==1){
      ans++;
      i+=3;
    }else if(i<len-2 and arr[i]==2 and arr[i+1]==2 and arr[i+2]==2){
      ans++;
      i+=3;
    }else i++;
  }
  
  cout<<ans<<endl;


}
