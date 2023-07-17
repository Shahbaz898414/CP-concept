#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool ok(int m,vector<int> a,int k){
  int cnt=1;
  int sum=0;

  for(auto i:a){
    if(sum+i>m){
      cnt++;
      sum=i;
    }else{
      sum+=i;
    }
  }

  return cnt<=k;
}


int main()
{

    int k=3;
    vector<int>  a={10,5,20,50,25,45,15};

      int ans=-1;

      int l=*max_element(begin(a),end(a));

      int r=accumulate(begin(a),end(a),0);

      while(l<=r){
        int m=(l+r)/2;

        if(ok(m,a,k)){
          ans=m;

          r=m-1;
        }else{
          l=m+1;
        }
      }

      cout<<ans<<endl;

    return 0;
}

