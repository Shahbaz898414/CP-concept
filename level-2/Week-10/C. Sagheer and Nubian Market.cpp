#include <bits/stdc++.h>
using namespace std;
#define ll long long


const int N=1e6+10;

int a[N],b[N];
ll n,s;


ll check(ll x) {
  for (int i =1; i <=n; i++)
  {
    /* code */
    b[i]=a[i]+x*i;

  }

  sort(b+1,b+1+n);
  ll sum=0;

  for (int i=1; i <=x; i++)
  {
    /* code */
    sum+=b[i];
  }
  
  if(sum<=s)  return sum;

  else return -1;
}

int32_t main() {
 
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  

  cin>>n>>s;

  for (int i =1; i <=n; i++)
  {
    /* code */
    scanf("%d",a+i);
  }

  int l=0,r=n;

  while(l<r) {
    int mid=(l+r+1)/2;
    if(check(mid)>=0){
      l=mid;
    }else{
      r=mid-1;
    }
  }
  

  cout<<l<<" "<<check(l)<<endl;


  return 0;
}


