#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

#define ll long long
#define all(x) x.begin(), x.end()
#define vi vector<long long int>

using namespace std;






signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        ll n,k;cin>>n;

       if(n==2 || n==1){
        cout<<0<<endl;
       }else if(n==3){
        cout<<2<<endl;
       }else {

          ll sum=(n*(n+1))/2;

          if(sum&1) {
            cout<<0<<endl;
            continue;
          }

       }
    }

    return 0;
}





/*


Today was my 45th day out of the 100 days  hard challenge.
So today, I solved 5 problems .


1. Company Queries I (https://cses.fi/problemset/task/1687).


2. Company Queries II (https://cses.fi/problemset/task/1688).


3. Penalty Shoot-Out II (https://www.codechef.com/problems/PSHOT)


4. Bon Appetit (https://www.codechef.com/problems/FGFS).


5. Chefina and Swap (https://www.codechef.com/problems/CHFNSWAP).

#100dayschallenge #challenge #consistency #SegmentTree #lessons  #learning



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