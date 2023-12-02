#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

 int minimumCoins(vector<int>& A) {


        int N = A.size();
        
       
        vector<int> dp(N + 5, 1e9); 
        

        dp[0] = 0; 
        
       
        for(int i = 1; i <= N; i++) {


            int sdp = dp[i - 1] + A[i - 1]; 
            

            for(int j = 0; j <= i; j++) {
                

                dp[min(N, i + j)] = min(dp[min(N, i + j)], sdp);


                cout<<dp[min(N, i + j)]<<" ";


            }

            cout<<endl;


        }
        

        return dp[N]; 


    }





int main() {
   

    int n;
    // cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> originalArray(n);

    // cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> originalArray[i];
    }


    cout<< minimumCoins(originalArray)<<endl;
    

    return 0;
}



/*


    int dp[1001] = {};
    int solve(vector<int>& prices, int i){
        if(i >= prices.size()) return 0;
        if(dp[i]) return dp[i];
        int res = INT_MAX;
        for(int j = i+1; j <= 2*i + 2; ++j){
            res = min(res, solve(prices, j));
        }
        return dp[i] = res + prices[i];
    }

    int minimumCoins(vector<int>& prices) {
        return solve(prices, 0);
    }



      int minimumCoins(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(n,1000000000);
        dp[0]=prices[0];
        for(int i=1;i<n;i++){
            if(i==1){
                dp[1]=dp[0];
                continue;
            }
            int minn=100000000;
            for(int j=i;j>=0;j--){
                if(2*j+1>=i && j-1>=0 && prices[j]+dp[j-1]<=minn){
                    minn=prices[j]+dp[j-1];
                    dp[i]=min(dp[i],minn);
                }
            }
        }
        return dp[n-1];
    }




    

class Solution {
public:


   


    int minimumCoins(vector<int>& A) {


        int N = A.size();
        
       
        vector<int> dp(N + 5, 1e9); 
        

        dp[0] = 0; 
        
       
        for(int i = 1; i <= N; i++) {


            int sdp = dp[i - 1] + A[i - 1]; 
            

            for(int j = 0; j <= i; j++) {
                

                dp[min(N, i + j)] = min(dp[min(N, i + j)], sdp);


            }


        }
        

        return dp[N]; 


    }
};



*/