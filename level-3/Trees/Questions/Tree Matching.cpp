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



/*



Assignment: Log Ingestor and Query Interface

Objective:
Develop a log ingestor system that can efficiently handle vast volumes of log data, and offer a simple interface for querying this data using full-text search or specific field filters.

Sample Log Data Format:

{
"level": "error",
"message": "Failed to connect to DB",
"resourceID": "server-1234",
"timestamp": "2023-09-15T08:00:00Z",
"traceID": "abc-xyz-123",
"spanID": "span-456",
"commit": "5e5342f",
"metadata": {
"parentResourceId": "server-0987"
}
}

Requirements:
Log Ingestor: Develop a mechanism to ingest logs in the provided format.
Ensure scalability to handle high volumes of logs efficiently.
Mitigate potential bottlenecks such as I/O operations, database write speeds, etc.

Query Interface: Offer a user interface (Web UI or CLI) for full-text search across logs.

Include filters based on:
level
message
resourceID
timestamp
traceID
spanID
commit
metadata.parentResourceId
Aim for efficient and quick search results.

Advanced Features (Bonus):
Implement search within specific date ranges.
Utilize regular expressions for search.
Allow combining multiple filters.
Provide real-time log ingestion and searching capabilities.
Implement role-based access to the query interface.

Sample Queries:
Find all logs with the level set to "error".
Search for logs with the message containing the term "Failed to connect".
Filter logs between the timestamp "2023-09-10T00:00:00Z" and "2023-09-15T23:59:59Z".
Retrieve all logs related to resourceID "server-1234".

Evaluation Criteria:
Volume: The ability of your system to ingest massive volumes.
Speed: Efficiency in returning search results.
Scalability: Adaptability to increasing volumes of logs/queries.
Usability: Intuitive, user-friendly interface.
Advanced Features: Implementation of bonus functionalities.

Submission:
Source code.
README detailing setup instructions, design decisions, challenges faced, potential system improvements.
Optional video or presentation showcasing the solution.

Tips:
Consider hybrid database solutions (relational + NoSQL) for a balance of structured data handling and efficient search capabilities.
Database indexing and sharding might be beneficial for scalability and speed.
Distributed systems or cloud-based solutions can ensure robust scalability.
Tech Stack: You are free to use any tech stack you wish!
Deadline: 20 Nov 2023

Good luck! We look forward to your innovative solutions. If further clarifications are needed, please reach out.

Once you solve this, ping me here again.


*/