#include <bits/stdc++.h>
using namespace std;
 


//  class Solution {
//   public:
//     bool lovelyCards(int N, vector<int> &Cards) {
//         // code here
//     }
// };


int Sum(int n,int sum){

     if(n==0)return sum;

     return n+Sum(n-1,0);


}

int32_t main()
{
 
int n=4;
 cout<<find(n);
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
 
  //   string a,b;
  //   cin >> a >> b;
  //   int n = a.length();
  //   int m = b.length();
 
  //   if(m>n){
  //       cout << 0 << endl;
  //       return 0;
  //   }
 
  //   vector<int> p_pow(n+1,1); 
  //   vector<int> inverse_p_pow(n+1,-1); 
  //   for(int i = 1;i <=n; i+=1) p_pow[i] = (p_pow[i-1]*31)%mod;
 
  //   inverse_p_pow[n] = mpow(p_pow[n],mod-2,mod);
 
  //   for(int i = n-1; i>=0; i--) inverse_p_pow[i] = ((31)*inverse_p_pow[i+1])%mod;
 
  //   vector<int> prefixHash(n); 
  //   for(int i =0;i<n; i+=1){
  //       prefixHash[i] = (a[i]-'a'+1)*p_pow[i];
  //       if(i) prefixHash[i] += prefixHash[i-1];
  //       prefixHash[i] %= mod;
  //   }
 
  //   int hashToCompare = 0; 
  //   for(int i =0;i <m; i+=1){
  //       hashToCompare += (b[i]-'a'+1)*p_pow[i];
  //       hashToCompare %= mod;
  //   }
  //   int answer =0;
   
  //   for(int i =0;i<n; i+=1){
  //       if((i+m-1)>=n) break;
  //       int substringHash = prefixHash[i+m-1];
  //       if(i){
  //           substringHash -= prefixHash[i-1];
  //       }
  //       substringHash = (substringHash%mod + mod)%mod;
  //       int denominator = inverse_p_pow[i];  
  //       substringHash = (substringHash*denominator)%mod;
  //       if(substringHash == hashToCompare) answer += 1;
  //   }


  //   cout << answer << endl;
  //   return 0;
 
}

/*
Func Sum(n,sum){
   if(n==0)return sum;
   return n+Sum(n-1,0);
}

Func Sum(n,sum){
   if(n==0)return sum;
   return Sum(n-1,sum+n-1);
}

Func Sum(n,sum){
   if(n==0)return sum;
   return n+Sum(n-1,sum);
}

Func Sum(n,sum){
   if(n==0)return sum;
   return Sum(n-1,sum+n);
}



    vector<vector<pair<int, int>>> adjList(N);
    for (int i = 0; i < M; i++) {
        int cityA = Roads[i][0];
        int cityB = Roads[i][1];
        int weight = Roads[i][2];
        adjList[cityA].push_back({cityB, weight});
        adjList[cityB].push_back({cityA, weight}); // Account for unidirectional roads
    }

   
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  
    vector<int> dist(N, INT_MAX);


    pq.push({0, 0});
    dist[0] = 0;

    
    while (!pq.empty()) {
        int currCity = pq.top().second;
        int currFuel = pq.top().first;
        pq.pop();

      
        if (currCity == N - 1) {
            return currFuel;
        }

       
        if (K > 0) {
            currFuel /= 2;
            K--;
        }

   
        for (pair<int, int>& neighbor : adjList[currCity]) {
            int nextCity = neighbor.first;
            int fuelNeeded = neighbor.second;

            
            if (currFuel + fuelNeeded < dist[nextCity]) {
                dist[nextCity] = currFuel + fuelNeeded;
                pq.push({dist[nextCity], nextCity});
            }
        }
    }

    return -1;

*/

