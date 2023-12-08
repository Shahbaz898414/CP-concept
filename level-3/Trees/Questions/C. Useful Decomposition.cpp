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

  vector<pair<int,int>> ans;

  int cnt=0;

  int root=0;
  int deg=0;

  for (int i = 1; i <=n; i++)
  {
    /* code */
    if((int)adj[i].size()>deg){
      deg=adj[i].size();
      root=i;
    }

    if((int)  adj[i].size()>=3) ++cnt;
  }

  if(cnt>1)  cout<<"No"<<endl;

  else{
    cout<<"Yes"<<endl;
    for (int i =1; i <=n; i++)
    {
      /* code */
      if(i==root)continue;
      if((int)adj[i].size()==1){
        ans.push_back({root,i});
      }
    }

    cout<<(int)ans.size()<<endl;

    for(auto x:ans){
      cout<<x.first<<" "<<x.second<<endl;
    }
    
  }
  

  
    
  
  return 0;
}