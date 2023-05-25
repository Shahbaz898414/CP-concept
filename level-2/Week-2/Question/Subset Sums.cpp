//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends



class Solution {
public:
    vector<int> subsetSums(vector<int> arr, int N) {
        set<ll> se;

        

        for (int i = 0; i < N; i++)
        {
          /* code */
          se.insert(arr[i]);
          for (int j = 0; j < N; j++)
          {
            /* code */
            se.insert(arr[i]+arr[j]);
          }
          
        }

        vector<int> v;

        for(auto it:se){
          v.push_back(it);
        }

        return v;
        
        
    }
};




//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends