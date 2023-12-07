#include <bits/stdc++.h>
using namespace std;





int main() {

  int n;cin>>n;

  vector<int>  adj[n+1];


  vector<int>  degree(n+1);
  vector<int> subtree(n+1,1);

  for (int i = 1; i <n; i++)
  {
    /* code */
    int x,y;cin>>x>>y;

    adj[x].push_back(y);
    adj[y].push_back(x);
    degree[x]++;
    degree[y]++;
  }

  // int cnt =1;

  // for(auto it:adj){
  //   // cout<<cnt++<<endl;
  //   for(auto i:it) {
  //     cout<<i<< ' ';
  //   }

  //   cout<<endl;
  // }

  // cout<<endl;

  queue<int> q;

  for (int i = 2; i <=n; i++)
  {
    /* code */
    if(degree[i]==1) q.push(i);
  }

  int ans=0;

  bool fl=0; int cnt=0;

  while(!q.empty()) {
    int x=q.front();
    q.pop();

    if(x==1){
      break;
    }

    if(subtree[x]%2==0){
      ans++;
      subtree[x]=0;
    }
    // if(fl==0)
    // cout<<x<<"x  ";
    

    for(auto &it:adj[x]) {
      // if(fl==0)
      //   cout<<it<<" ";
      subtree[it]+=subtree[x];
      degree[it]--;

      if(degree[it]==1) q.push(it);
    }
  //  cnt++;
  //  if(cnt==3){
  //   fl=1;
  //  }
    // cout<<endl;
  }

    // cout<<endl;

    if(n%2)  cout<<-1<<endl;
    else cout<<ans<<endl;
    
  
  return 0;
}