#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;

ll dp[N][2];

bool check(vector<string> &arr,string a){
  for(auto &it:arr){
      int temp=0;
      for (int i = 0; i < a.size(); i++)
      {
       

        if(a[i]!=it[i]) temp++;
      }

      if(temp>1)  return false;
      
  }


  return true;
}

int main()
{
  ll t = 1;
  cin >> t;

  while (t--)
  {

    ll n,  z; ll m,k;
    cin >> n>>m;



    // string s;
    // cin >> s;
    string ans ="";

    vector<string> arr(n);


    for (ll i = 0; i < n; i++)
    {
     
      cin>>arr[i];
    }

    if(check(arr,arr[0])) {
        cout<<arr[0]<<endl;
        continue;
    }


    for (int i = 0; i <m; i++)
    {
      for (int k = 0; k < 26; k++)
      {
        string s=arr[0];
        s[i]=('a'+k);

        if(check(arr,s))  ans=s;
      }
      
    }

    cout<<((ans=="")?"-1":ans)<<endl;
    


    
       
    

    

  }
}



