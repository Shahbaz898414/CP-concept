#include <bits/stdc++.h>

#define ll long long
using namespace std;


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();

        map<int,int> mp;

        int ans=0;

        for (int i = 0; i < n; i++) {
          mp[nums[i]]++;
        }

        if(k==0) {
          for(auto it:mp){
            if(it.second>=2){
              ans++;
            }
          }
        }else {
          for(auto it:mp)
          {
            int nx=it.first+k;

            if(mp.count(nx)>0){
              ans++;
            }
           }

         }


         return ans;


        

        
    }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    ll n;
    cin >> n;
    ll arr[n];

    for (ll i = 0; i < n; i++)
    {
      
      cin >> arr[i];
    }

    ll m,p=0;cin>>m;

    

    for (int i = 0; i < m; i++) {
      ll x;cin>>x;

      p=(p+x)%n;
    }

    cout<<arr[p]<<endl;
    
  }
}
