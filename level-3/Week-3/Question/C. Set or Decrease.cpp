/*



#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{

  ll t;
  cin >> t;

  while (t--)
  {
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    ll sum = 0;
    ll ans=0;

    for (ll i = 0; i < n; i++)
    {
      cin >> arr[i];
      sum += arr[i];
    }

    ll l=0,h=1e8;

  }

  return 0;
}



*/





#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;

const int N = 2e5 + 10;

int a[N];
ll n, k;
ll s[N];

bool check(ll x)
{
  ll t = 0; ll sum = 0;
  for (int i = 0; i < n; i++) {
    t = i;
    sum = s[n - i] + i * s[1];
    if (sum > k) 
      t += (sum - k + i) / (i + 1);
    
    if (t <= x)
      return true;
  }


}

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    sort(a, a + n + 1);

    // for (int i = 1; i <= n; i++)
    //   cout<<a[i]<<" ";

    // cout<<endl;

    for (int i = 1; i <= n; i++){
      s[i] = s[i - 1] + a[i];
      //  cout<<s[i]<<" "<<a[i]<<endl;
    }
      


    // for (int i = 1; i <= n; i++)
     

    // cout<<endl;

    ll l = 0, r = 1e16;
    while (l < r)
    {
      ll mid = l + r >> 1;
      if (check(mid))
        r = mid;
      else
        l = mid + 1;
    }

    cout << l << endl;
  }

  return 0;
}
