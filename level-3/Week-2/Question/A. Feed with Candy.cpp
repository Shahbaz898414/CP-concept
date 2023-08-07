#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

int main()
{
  // ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);

  ll n, x;
  cin >> n >> x;
  ll t[n], h[n], m[n];

  for (ll i = 0; i < n; i++)
    cin >> t[i] >> h[i] >> m[i];

  ll atb = 0;

  for (ll e = 0; e <= 1; e++)
  {
    ll x2 = x;
    vector<bool> ty(n);
    for (ll i = 0; i < n; i++)
    {
      ll c = -1;
      for (ll j = 0; j < n; j++)
      {
        if (!ty[j] && h[j] <= x2 && t[j] == (e + i) % 2)
        {
          if (c == -1 || m[j] > m[c])
          {
            c = j;
          }
        }
      }
      if (c == -1)
        break;

      x2 += m[c];
      ty[c] = true;
      atb = max(atb, i + 1);
    }
  }

  cout << atb;

  return 0;
}

/**


    int n, x; cin >> n >> x;
    int t[n], h[n], m[n];

    for (int i = 0; i < n; i++)  cin >> t[i] >> h[i] >> m[i];

    int atb=0;

    for (int e = 0; e <= 1; e++) {
        int x2 = x;
        vector <bool> ty(n);
        for (int i = 0; i < n; i++) {
            int c = -1;
            for (int j = 0; j < n; j++) {
                if(!ty[j] && h[j]<=x2 && t[j]==(e+i)%2) {
                    if(c==-1 || m[j] > m[c]) {
                        c=j;
                    }
                }
            }
            if(c==-1)
                break;

            x2+=m[c];
            ty[c] = true;
            atb = max(atb, i+1);
        }
    }

    cout << atb;



*/

/*

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second > p2.second)
    {
        return true;
    }
    else if (p1.second < p2.second)
        return false;
    else
    {

        if (p1.first <= p2.first)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
int calculate(vector<pair<int, int>> &zero, vector<pair<int, int>> &one, int h)
{
    int i = 0, j = 0, n = zero.size(), m = one.size(), cnt = 0, candies = 0;
    priority_queue<int> zero1, one1;
    while (true)
    {
        while (i < n && zero[i].first <= h)
        {
            zero1.push(zero[i].second);
            i++;
        }
        while (j < m && one[j].first <= h)
        {
            one1.push(one[j].second);
            j++;
        }
        if (candies == 0)
        {
            if (zero1.empty())
                break;
            else
            {
                cnt++;
                h += zero1.top();
                zero1.pop();
                candies = 1;
            }
        }
        else
        {
            if (one1.empty())
                break;
            else
            {
                cnt++;
                h += one1.top();
                one1.pop();
                candies = 0;
            }
        }
    }
    return cnt;
}
int main()
{
    int n, h;
    cin >> n >> h;
    vector<pair<int, int>> zero, one;
    for (int i = 0, t, a, b; i < n; i++)
    {
        cin >> t >> a >> b;
        if (t == 0)
            zero.push_back({a, b});
        else
            one.push_back({a, b});
    }
    sort(zero.begin(), zero.end());
    sort(one.begin(), one.end());
    int mx1 = calculate(zero, one, h);
    int mx2 = calculate(one, zero, h);
    cout << max(mx1, mx2) << endl;
}

*/

/*

# include <bits/stdc++.h>
# define flash ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
# define ff first
# define ss second
# define pb push_back
# define all(x) x.begin(), x.end()
# define allr(x) x.rbegin(), x.rend()
# define in insert
# define file(s) freopen(s".in", "r", stdin); freopen(s".out", "w", stdout)

typedef long long ll;
typedef double db;
typedef long double ld;
using namespace std;

const int N = 2e5 + 5;
const ll inf = 1e9 + 7;
const ll INF = 1e18;
const db pi = acos(-1.0);

int n, tt = 1, x, k, ans, cnt;
vector <pair <int, int> > v1, v2;
bool used1[2005], used2[2005];

void solve(){
  cin >> n >> x;
  k = x;
  for (int i = 1; i <= n; i++){
    int t, h, m;
    cin >> t >> h >> m;
    if (t){
      v1.pb({h, m});
    }
    else{
      v2.pb({h, m});
    }
  }
  while (1){
    int id = -1, mx = 0;
    for (int i = 0; i < v2.size(); i++){
      if (!used2[i] && v2[i].ff <= x){
        if (v2[i].ss > mx){
          mx = v2[i].ss;
          id = i;
        }
      }
    }
    if (id == -1) break;
    ans++;
    x += mx;
    used2[id] = 1;
    id = -1, mx = 0;
    for (int i = 0; i < v1.size(); i++){
      if (!used1[i] && v1[i].ff <= x){
        if (v1[i].ss > mx){
          mx = v1[i].ss;
          id = i;
        }
      }
    }
    if (id == -1) break;
    ans++;
    used1[id] = 1;
    x += mx;
  }


  x = k;

  memset(used1, 0, sizeof used1);
  memset(used2, 0, sizeof used2);
  while (1){
    int id = -1, mx = 0;
    for (int i = 0; i < v1.size(); i++){
      if (!used1[i] && v1[i].ff <= x){
        if (v1[i].ss > mx){
          mx = v1[i].ss;
          id = i;
        }
      }
    }
    if (id == -1) break;
    cnt++;
    x += mx;
    used1[id] = 1;
    id = -1, mx = 0;
    for (int i = 0; i < v2.size(); i++){
      if (!used2[i] && v2[i].ff <= x){
        if (v2[i].ss > mx){
          mx = v2[i].ss;
          id = i;
        }
      }
    }
    if (id == -1) break;
    cnt++;
    used2[id] = 1;
    x += mx;
  }
  cout << max(ans, cnt);
}

int main (){
  //file(s);
  flash;
  //cin >> tt;
  while (tt--){
    solve();
  }
  return 0;
}



*/