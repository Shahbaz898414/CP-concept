#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define MAXN 202020



vector<vector<int>> adj(MAXN);
vector<int> subtree_size(MAXN);

int calc (int node) {

  // cout<<"node "<<node<<endl;
   if (adj[node].size() == 0) {

    // cout<<1<<endl;
      return 1;
   } else {
      //  cout<<2<<" ";
       for (int i = 0; i < adj[node].size(); i++) {
          subtree_size[node] += calc(adj[node][i]);
       }
      //  cout<<endl;
   }
   return subtree_size[node] + 1;
}




int main () {

  int n;cin >> n;
  
 

  for (int i = 2; i <=n; i++) {

    int boss;cin>>boss;
    // cin>>arr[i];

    adj[boss].push_back(i);

  }

  // for(auto it:adj){
  //   for(auto i:it){
  //     cout<<i<<" ";
  //   }
  //   cout<<endl;
  // }

  // cout<<endl;

  calc(1);

  // cout<<endl<<endl;


  for (int i = 1; i <= n; i++) {
      cout << subtree_size[i] << " ";
  }
  

    
}


/*

2 3 
4 
5



*/