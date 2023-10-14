#include <bits/stdc++.h>
using namespace std;

#define int long long


#define  all(x)  x.begin(), x.end()


const int N=4e5+5;

int a[N],b[N],c[N],dp[N];

vector<pair<int,int>>  start[N];


vector<int>  temp;


int idx(int val) {
  return  (lower_bound(all(temp),val)-temp.begin()+1);
}


int sol(int idx) {
  if(idx==0)  return 0;
  if(dp[idx]!=-1)  return dp[idx];
  int ans=sol(idx-1);
}



void sol() {
  memset(dp,-1,sizeof dp);
  int n;cin>>n;


  for (int i = 0; i < n; i++)
  {
    /* code */
    cin>>a[i]>>b[i]>>c[i];

    temp.push_back(a[i]);
    temp.push_back(b[i]);
  }


  sort(all(temp));

  temp.erase(unique(all(temp)),temp.end());


  for (int i = 0; i < n; i++)
  {
    /* code */
    a[i]=idx(a[i]);
    b[i]=idx(b[i]);

    start[b[i]].push_back({a[i],c[i]});
  }




  
  
}




int main() {
  int t=1;
  // cin>>t;
  while(t--) {
    sol();
  }
}