//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>  meet(n);

        for (int i = 0; i <n; i++)
        {
          /* code */
          meet[i]={end[i],start[i]};
          // meet[i]={start[i],end[i]};
        }

        sort(meet.begin(),meet.end());


        for(auto it:meet){
          cout<<it.first<< " "<<it.second<<endl;
        }

        int avail=0;

        int cnt=0;

        for (int i = 0; i < n; i++)
        {
          if(avail<=meet[i].second){
            cnt++;
            avail=meet[i].first+1;
          }

        }

        
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends