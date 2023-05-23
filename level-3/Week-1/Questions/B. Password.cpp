#include <bits/stdc++.h>
#define ll long long
const int mod = 1e9 + 7;
using namespace std;


ll backbox(string s){
    ll ans=0;
    ll pr=1;
    for (ll i = 0; i < s.size(); i++) {
        ans=(ans+((s[i]-'a'+1LL)*pr)%mod)%mod;
        pr=(pr*31LL)%mod;
    }
    return ans;
    
}

ll power(ll base,ll x){
    ll ans=1;
    while(x){
        if(x%2==0){
            base=(base*base)%mod;
        }else {
            ans=(ans*base)%mod;
            x--;
        }
    }

    return ans;
}

bool check(string &s, ll len)
{
    string p = s.substr(e, len);
    ll plen = len;
    ll slen = s.length();
    ll phash = blackbox(p);
    string temp = s.substr(0, plen);
    ll shash = blackbox(temp);
    ll cnt = 0;
    if (phash == shash)
        cnt++;

    ll prL = 1;
    ll prR = power(31, plen);
    for (ll i = plen; i < slen; i++)
    {
        shash = (shash - ((s[i - plen] - 'a' + 1) * prL) % mod + mod) % mod;
        shash = (shash + ((s[i] - 'a' + 1) * prR) % mod) %mod;
        phash = (phash * 31) % mod;
        if(shash == phash)
        {
            cnt++;
        }
        prL = (prL * 31) %mod; 
        prR = (prR * 31) %mod;
    }

    return(cnt > 2);
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    ll n = s.size();
    ll hash = 0;
    ll pr = 1;
    vector<ll> h(n);

    for (ll i = 0; i < n; i++)
    {
        /* code */
        hash = (hash * 31LL) % mod;
        hash = (hash + (s[i] - 'a' + 1)) % mod;
        pr = (pr * 31LL) % mod;
        h[i] = hash;
    }

    hash = 0;

    vector<ll> vec;

    for (ll i = n - 1; i >= 0; i--)
    {
        hash = (hash * 31LL) % mod;

        hash = (hash + (s[i] - 'a' + 1)) % mod;
        if (hash == h[n - i - 1])
        {
            vec.push_back(n - i - 1);
        }
    }

    ll low = 0;
    ll high = vec.size() - 1;
    while (high >= low)
    {
        ll mid = (low + high) >> 1;

        if (check(s, vec[mid] + 1))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (high < 0)
    {
        cout << "Just a legend" << endl;
    }
    else
    {
        cout << s.substr(0, vec[high] + 1) << endl;
    }

    return 0;
}
