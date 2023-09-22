#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;

ll dp[N][2];

int main()
{
  ll t = 1;
  cin >> t;

  while (t--)
  {

    ll n,  z;
    cin >> n;

    string s;
    cin >> s;
    ll ans = 0;

    vector<ll> vis(n);

    for (ll i = 0; i < n;)
    {

      if (vis[i])
        break;

      int j, k, cnt = 0;

      j = i;
      while (s[j] == s[i] and j < n)
      {
        vis[j++] = 1, cnt += 1;
      }

      if (i == 0)
      {

        cout<<1<<endl;
        k = n - 1;

        while (k > i and !vis[k] and s[k] == s[i]) {
          vis[k--] = 1;
          cnt++;
        }
      }

      cout<<cnt<<" cnt"<<endl;

      ans += (cnt + 2 * (cnt == n)) / 3;

      i = j;


    }





    cout << ans << endl;





  }
}



/*


Hi,

I hope this message finds you well! I came across the Servicenow Intern (https://airtable.com/appWUzBuE7uhXshqJ/shrDZGwztjlex8Jdb?prefill_Tacnique%20Form=1&hide_Tacnique%20Form=true&prefill_Referred%20By=LinkedIn%20Recruiter&prefill_Applying%20for=recvjFCQrIA6TiEDP) at Servicenow. As an aspiring Software Engineer, I admire the company's innovative work. If possible, could you kindly refer me? I'd greatly appreciate it!

Best regards,
Shahbaz Khan



*/