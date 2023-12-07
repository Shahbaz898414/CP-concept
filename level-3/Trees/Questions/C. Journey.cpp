#include <bits/stdc++.h>
using namespace std;

int main()
{

  int n;
  cin >> n;
  vector<int> adj[n + 1];
  for (int i = 1; i < n; i++)
  {
    /* code */
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  long double ans = 0;

  function<void(int, int, int, double)> dfs = [&](int node, int parent, int path, double pro)
  {
    for (auto &i : adj[node])
    {

      if(i!=parent)
         dfs(i, node, path + 1, pro / (adj[node].size() - (parent != -1)));
    }

    if (adj[node].size() == 1 and adj[node].front() == parent)
    {
      ans += pro * path;
    }
  };

  dfs(1, -1, 0, 1);

  cout << setprecision(25) << ans << endl;

  return 0;
}


/*



Today was my 64th day out of the 100 days  hard challenge.
So today, I solved 5 problems .


1. J. Send the Fool Further! (easy) (https://codeforces.com/contest/802/problem/J).



2. C. PolandBall and Forest  (https://codeforces.com/contest/755/problem/C).


3. A. Peculiar apple-tree (https://codeforces.com/contest/930/problem/A)


4. C. Cut 'em all! (https://codeforces.com/contest/982/problem/C).


5. C. Journey (https://codeforces.com/problemset/problem/839/C).



#100dayschallenge #challenge #consistency #Cp #lessons #learning
#competitiveprogramming

*/


/*

"12th Fail" is an amazing movie.
Highly recommended.

Just watched "12th Fail" and was truly inspired by the protagonist's journey. It beautifully captures the essence of perseverance and the belief that failure is not the end but a stepping stone to success.

Movie delivers a powerful message about the importance of self-belief and determination. It encourages everyone to pursue their dreams, no matter how many times they may stumble along the way.

I am someone who usually is very hesitant in recommending movies as liking a movie is very subjective.





"12th Fail" is an amazing movie.
Highly recommended.

Just watched "12th Fail" and was truly inspired by the protagonist's journey. It beautifully captures the essence of perseverance and the belief that failure is not the end but a stepping stone to success.

Movie delivers a powerful message about the importance of self-belief and determination. It encourages everyone to pursue their dreams, no matter how many times they may stumble along the way.

I am someone who usually is very hesitant in recommending movies as liking a movie is very subjective.



#12thfail  #selfbelief 

*/