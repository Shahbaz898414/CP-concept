#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define MAXN 202020



vector<vector<int>> adj(MAXN);
vector<int> subtree_size(MAXN);

int calc (int node) {

  // cout<<"node "<<node<<endl;
   if (adj[node].size() == 0) {

    // cout<<1<<endl;
      return 1;
   } else {
      //  cout<<2<<" ";
       for (int i = 0; i < adj[node].size(); i++) {
          subtree_size[node] += calc(adj[node][i]);
       }
      //  cout<<endl;
   }
   return subtree_size[node] + 1;
}




int main () {

  int n;cin >> n;
  
 

  for (int i = 2; i <=n; i++) {

    int boss;cin>>boss;
    // cin>>arr[i];

    adj[boss].push_back(i);

  }

  // for(auto it:adj){
  //   for(auto i:it){
  //     cout<<i<<" ";
  //   }
  //   cout<<endl;
  // }

  // cout<<endl;

  calc(1);

  // cout<<endl<<endl;


  for (int i = 1; i <= n; i++) {
      cout << subtree_size[i] << " ";
  }
  

    
}


/*

testcasse
10
8 9
10 9
1 4
7 1
8 3
10 5
4 2
3 7
6 4


10
10 9
3 6
5 10
10 3
1 3
3 2
4 2
7 10
8 3



*/



/*


You are given a tree consisting of n nodes. A matching is a set of edges where each node is an endpoint of at most one edge. What is the maximum number of edges in a matching?  

Input The first input line contains an integer n: the number of nodes. The nodes are numbered  1,2,…,n.  Then there are n−1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b. 

Output
Print one integer: the maximum number of pairs.  
Constraints
1≤n≤2⋅10 ^5 .
1≤a,b≤n







Today was my 41th day out of the 100 days  hard challenge.
So today, I solved 5 problems .


1. Tree Matching (https://cses.fi/problemset/task/1130).


2. Subordinates (https://cses.fi/problemset/task/1674).


3. Range Xor Queries (https://cses.fi/problemset/task/1650)


4. Josephus Queries (https://cses.fi/problemset/task/2164).


5. Counting Rooms (https://cses.fi/problemset/task/1192).


#100dayschallenge #challenge #consistency #SegmentTree #lessons
#learning



*/