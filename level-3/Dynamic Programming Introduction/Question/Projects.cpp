#include <bits/stdc++.h>
using namespace std;

#define ll long long


const int N=5002;
int n,arr[N];


int f(int i,int j,int k){
  // cin>>n;


  if(i==1 and j==n)  return n;


  if(i>1 || j>n)  return INT_MAX;


  int curCol = (k==0 ? arr[i]:arr[j]);


  int ans=INT_MAX;



  ans=min(ans,f(i-1,j,0))+(arr[i-1]!=curCol);
  ans=min(ans,f(i,j+1,0))+(arr[j-1]!=curCol);



  return ans;


}



int solve(){


  cin>>n;

  for (int i = 1; i <=n; i++) {
    cin>>arr[i];
  }

  

  int ans=INT_MAX;

  for (int i =1; i <=n; i++) {
    ans=min(ans,f(i,i,0));
  }
  

  cout<<ans<<endl;
  

}


int main()
{
  

  int t=1;

  // cin>>t;

  while(t--) {
    solve();
  }
  


  return 0;
}