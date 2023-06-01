#include <bits/stdc++.h>
#define ll long long
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        // int n=nums.size();

        // int ans=0;

        // if(n==1) return 0;

        // for (int i = 0; i < n; i++)
        // {
        //   ans++;
        //   if(nums[i]+i>=nums.size()-1) break;

        //   int mx=0,go=-1;

        //   for (int j = i+1; j <=nums[i]+i; j++)
        //   {
        //     /* code */
        //     if(nums[j]+j>mx) {
        //       mx=nums[j]+j,go=j;
        //     }
        //   }
        //   i=go-1;
          
        // }

        // return ans;
        

        for(int i = 1; i <n; i++) {
           nums[i]=max(nums[i]+i,nums[i-1]);
        }
        int cnt=0;
        int ans=0;
        while(cnt<nums.size()-1) {
            ans++;
            cnt=nums[cnt];
        }


        return ans;
    }
};


int main()
{
  ll t;
  cin >> t;

  while (t--)
  {
    ll n;
    cin >> n;

    
    ll arr[n],l[n]={0},r[n]={0},f=0;

    for (int i = 0; i < n; i++) {
      cin>>arr[i];
    }

    for (int i = 0; i < n; i++)
    {
      
      if(arr[i]>=i) l[i]=1;
      else break;
    }

    for (int i = n-1; i >=0; i--)
    {
      
      if(arr[i]>=n-i-1) r[i]=1;
      else break;
    }

    for (int i = 0; i < n; i++)
    {
      
      if(l[i] and r[i]) f=1;
    }

    if(f)  cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    
  }
}