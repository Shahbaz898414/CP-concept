



#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 202020


#define ff first
#define ss second


#define INF  INT_MAX



struct DSU {
  int n;
  vector<int>  parent;
  vector<int>  rank;
  vector<int>  teamSize;
  DSU(int n1){
    n=n1;
    parent.resize(n);
    rank.resize(n);

    for (int i = 0; i < n; i++) {
    
      parent[i]=i;

      rank[i]=0;

      teamSize[i]=1;

    }
    
  }

  void connect(int x,int y){
      x=getLeader(x);
      y=getLeader(y);

      if(x==y)  return ;
      if(rank[x]==rank[y]){
        rank[x]++;

      }

      if(rank[x]>rank[y]){
        parent[y]=x;
        teamSize[x]+=teamSize[y];
      }else{
        parent[x]=y;
        teamSize[y]+=teamSize[x];
      }

  }

  int getLeader(int x){
    if(x==parent[x]){
      return x;
    }

    int leader=getLeader(parent[x]);

    parent[x]= leader;

    return leader;
  }


};


void solve(){

  int n,x; // for inilizing

  DSU d=DSU(n);

  cout<<d.teamSize[d.getLeader(x)];
  
}




int main() {
    
   

    return 0;
}


