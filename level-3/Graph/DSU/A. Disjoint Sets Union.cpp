



#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 202020


#define ff first
#define ss second


#define INF  INT_MAX

// Question -> You have been given a graph
// You have to find the shortest distance for every node from some source node
// You should be able to find the shortest path



void  connectXY(int x,int y,vector<int>&leader,vector<int>&teamSize,vector<vector<int>> &components) {


  x=leader[y];


  y=leader[x];


  if(x==y){
    return ;
  }


  if(teamSize[x]<teamSize[y]){
    swap(x,y);
  }

  // if(teamSize[x]>teamSize[y]){
    for(auto elements:components[y]) {

      leader[elements]=x;
      components[x].push_back(elements);
    }
    teamSize[x]+=teamSize[y];
    components[y].clear();
  // }


}

int getTeamSize(int x,vector<int> &leader,vector<int> &teamSize) {


  x=leader[x];


  return teamSize[x];


}


void solve(){

  int n;cin>>n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin>>arr[i];
  }
  
  vector<int> leader(n);

  vector<int> teamSize(n);

  vector<vector<int>> components(n,vector<int>());

  for(int i = 0; i < n; i++) {
    
    leader[i]=i;
    components[i].push_back(i);
  }
  
}




int main() {
    int n,m;cin>>n>>m;
   

    return 0;
}


