//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
  public:
  int CountStrings(string s)
  {
        int n=s.size(),res=0;
      for(int i=0;i<n;i++)
      {
          vector<int>cnt(10,0);
          int mx1=0,mx2=0;
          for(int j=i;j<min(n,i+72);j++)
          {
              cnt[s[j]-'0']++;
              mx1=max(mx1,cnt[s[j]-'0']);
              mx2=max(mx2,s[j]-'0');
              if(mx1<mx2) res++;
          }
      }
      return res;
  }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.CountStrings(s)<<endl;
    }
}
// } Driver Code Ends


