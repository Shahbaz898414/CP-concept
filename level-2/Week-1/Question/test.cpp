#include<bits/stdc++.h>
#define ll long long
using namespace std;



int main() {
  
  int n;cin>>n;

  vector<int>  v;

  for(int i=0;i<n;i++){
    int x;cin>>x;

    v.push_back(x);
  }

  for(auto it:v){
    it++;

    // cout<<it<<" ";
  }

  // for(auto it:v){
  //   cout<<it<<" ";
  // }

  cout<<endl;

  


  




  return 0;
}