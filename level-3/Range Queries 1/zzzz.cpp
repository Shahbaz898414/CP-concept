#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

#define int long long
#define all(x) x.begin(), x.end()

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    cin >> testCases;

    while (testCases--) {
       int n;cin>>n;

       vector<int> arr(n);
        int x=0;
       for (int i = 0; i < n; i++)
       {
        /* code */
        cin>>arr[i];

        x^=arr[i];
       }
       
        
    }

    return 0;
}



/*

Sonu and Titu are playing a tennis match. They are playing a "best of  N sets" match ( N is always odd). That means that they will play at most  N sets, and the person who has won most sets wins the match. But they are smart, and if they notice at any point that one of them has no chance of winning the match, they will stop the match right then, without playing out all the  N sets needlessly.  For example, suppose  = 11 N=11. And at some point, Sonu has won 5 sets, and Titu has won 4 sets. Sonu is leading now, but it is possible that Titu wins the two remaining sets and wins the whole match. So they will not stop right now.  But suppose Sonu wins the next set as well, and so now the score is (6,4). Now, even though there is one set remaining, there is no chance of Titu winning the whole match, since at best, even if he wins the next set, the score will become  (6,5), and Sonu still wins. So, they will stop at a score of  (6,4) and declare Sonu as the winner.  As another example, if  = 15 N=15, and the score is currently (8,2), then they'll stop right now, since there is no way for Titu to win the match. Even if Titu wins all the  5 5 remaining sets, Titu cannot win the match.  You are watching the match, and you see that the match has ended with a score of (X,Y). That is, Sonu has won  X sets, and Titu has won  Y sets. But you don't know what  N is. Can you find out  N from just knowing the final score?  Input Format The first line of input will contain a single integer  T, denoting the number of test cases. Each test case consists of a single line of input containing two space-separated integers  X and  Y where  X is the number of sets won by Sonu and  Y is the number of sets won by Titu. Output Format For each test case, output on a new line the value of  N. Note that you should only output an odd integer. Constraints 1 ≤ ≤ 10000 1≤T≤10000 1 ≤ ≤ 100 1≤X≤100 1 ≤ ≤ 100 1≤Y≤100 ≠ X=Y, since they would never stop when they have won the same number of sets.



*/