#include <bits/stdc++.h>
using namespace std;


typedef long long ll;


#define INF 1e9;


int main() {

 
  ll t = 1;


  // cin >> t;


  while (t--) {


    int n; ll maxWeight; cin >> n >> maxWeight;


    vector<ll> people(n);


    for (int i = 0; i < n; i++) cin >> people[i];


    int limit = (1 << n);


    vector<pair<ll, ll>> dp(limit);


    dp[0] = {1, 0};



    for (int mask = 1; mask < limit; mask++) {


      pair<ll, ll> bestResult = {INT_MAX, INT_MAX};


      for (int i = 0; i < n; i++) {


        if (((1 << i) & mask) == 0) continue;


        auto res = dp[(1 << i) ^ mask];


        if (res.second + people[i] <= maxWeight) {


          res.second += people[i];
        
        
        } else {
        
        
          res.first += 1;
        
        
          res.second = people[i];
        
        
        }


        bestResult = min(bestResult,res);

        
      }


      dp[mask] = bestResult;


    }


    cout << dp[limit - 1].first;


  }


  return 0;


}


