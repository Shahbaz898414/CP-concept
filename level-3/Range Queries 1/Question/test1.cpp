
#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits(x) __builtin_popcountll(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

#ifdef Priyansh31dec
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x) ;
#endif

using ll = long long;
using ull = unsigned long long;
using lld = long double;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
ll expo(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}
void extendgcd(ll a, ll b, ll *v)
{
    if (b == 0)
    {
        v[0] = 1;
        v[1] = 0;
        v[2] = a;
        return;
    }
    extendgcd(b, a % b, v);
    ll x = v[1];
    v[1] = v[0] - v[1] * (a / b);
    v[0] = x;
    return;
} // pass an arry of size1 3
ll mminv(ll a, ll b)
{
    ll arr[3];
    extendgcd(a, b, arr);
    return arr[0];
} // for non prime b
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
bool revsort(ll a, ll b) { return a > b; }
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact)
{
    ll val1 = fact[n];
    ll val2 = ifact[n - r];
    ll val3 = ifact[r];
    return (((val1 * val2) % m) * val3) % m;
}
void google(int t) { cout << "Case " << t << ": "; }
vector<ll> sieve(int n)
{
    int *arr = new int[n + 1]();
    vector<ll> vect;
    for (int i = 2; i <= n; i++)
        if (arr[i] == 0)
        {
            vect.push_back(i);
            for (int j = 2 * i; j <= n; j += i)
                arr[j] = 1;
        }
    return vect;
}
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} // only for prime m
ll phin(ll n)
{
    ll number = n;
    if (n % 2 == 0)
    {
        number /= 2;
        while (n % 2 == 0)
            n /= 2;
    }
    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            number = (number / i * (i - 1));
        }
    }
    if (n > 1)
        number = (number / n * (n - 1));
    return number;
} // O(sqrt(N))
ll getRandomNumber(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
/*--------------------------------------------------------------------------------------------------------------------------*/
void topo_sort(int curr, vector<vector<int>> &edges, vector<bool> &vis, vector<int> &topoSort, int &inserted)
{
    vis[curr] = true;
    for (auto i : edges[curr])
    {
        if (!vis[i])
        {
            topo_sort(i, edges, vis, topoSort, inserted);
        }
    }
    int n = sz(edges);
    topoSort[n - inserted - 1] = curr;
    inserted++;
}
void dfs(int curr, vector<vector<int>> &edges, vector<bool> &vis, vector<int> &comp)
{
    comp.push_back(curr + 1);
    vis[curr] = true;
    for (auto i : edges[curr])
    {
        if (!vis[i])
        {
            dfs(i, edges, vis, comp);
        }
    }
}

int gcd(int a, int b)
{
    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // Base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

void solve()
{
  ll n, p, q;
        cin >> n >> p >> q;
        vector<ll> numbers(n);

        ll sum=0;

        vector<ll>  arr;

        for (ll i = 0; i < n; i++) {
            cin >> numbers[i];

             // ll x = numbers.back();
            // numbers.pop_back();
            // ll y = numbers.back();
            // numbers.pop_back();
            // numbers.push_back(x + y);
            // p--;
            sum+=numbers[i];
        }

        // if(sum<0)  return ;

        sort(numbers.begin(), numbers.end());

        ll m=0;



        while (numbers.size() > 2 && p > 0 && numbers[numbers.size() - 2] > 0) {
            ll x = numbers.back();
             // ll x = numbers.back();
            // numbers.pop_back();
            // ll y = numbers.back();
            // numbers.pop_back();
            // numbers.push_back(x + y);
            // p--;
            numbers.pop_back();
             // ll x = numbers.back();
            // numbers.pop_back();
            // ll y = numbers.back();
            // numbers.pop_back();
            // numbers.push_back(x + y);
            // p--;
            ll y = numbers.back();
             // ll x = numbers.back();
            // numbers.pop_back();
            // ll y = numbers.back();
            // numbers.pop_back();
            // numbers.push_back(x + y);
            // p--;
            numbers.pop_back();

            arr.push_back(x+y);
             // ll x = numbers.back();
            // numbers.pop_back();
            // ll y = numbers.back();
            // numbers.pop_back();
            // numbers.push_back(x + y);
            // p--;
            numbers.push_back(x + y);
            p--;
        }



        reverse(numbers.begin(), numbers.end());
         // ll x = numbers.back();
            // numbers.pop_back();
            // ll y = numbers.back();
            // numbers.pop_back();
            // numbers.push_back(x + y);
            // p--;

        while (numbers.size() > 2 && p > 0 && numbers[numbers.size() - 2] < 0) {
            ll x = numbers.back();
             // ll x = numbers.back();
            // numbers.pop_back();
            // ll y = numbers.back();
            // numbers.pop_back();
            // numbers.push_back(x + y);
            // p--;
            numbers.pop_back();
             // ll x = numbers.back();
            // numbers.pop_back();
            // ll y = numbers.back();
            // numbers.pop_back();
            // numbers.push_back(x + y);
            // p--;
            ll y = numbers.back();
             // ll x = numbers.back();
            // numbers.pop_back();
            // ll y = numbers.back();
            // numbers.pop_back();
            // numbers.push_back(x + y);
            // p--;
            numbers.pop_back();
             // ll x = numbers.back();
            // numbers.pop_back();
            // ll y = numbers.back();
            // numbers.pop_back();
            // numbers.push_back(x + y);
            // p--;
            numbers.push_back(x + y);
            arr.push_back(x-y);
             // ll x = numbers.back();
            // numbers.pop_back();
            // ll y = numbers.back();
            // numbers.pop_back();
            // numbers.push_back(x + y);
            // p--;
            p--;
        }

        reverse(numbers.begin(), numbers.end());
         // ll x = numbers.back();
            // numbers.pop_back();
            // ll y = numbers.back();
            // numbers.pop_back();
            // numbers.push_back(x + y);
            // p--;

        while (numbers.size() > 2 && q > 0 && numbers[numbers.size() - 2] > 0) {
            numbers[0] -= numbers[numbers.size() - 2];
             // ll x = numbers.back();
            // numbers.pop_back();
            // ll y = numbers.back();
            // numbers.pop_back();
            // numbers.push_back(x + y);
            // p--;
            numbers.erase(numbers.end() - 2);
             // ll x = numbers.back();
            // numbers.pop_back();
            // ll y = numbers.back();
            // numbers.pop_back();
            // numbers.push_back(x + y);
            // p--;
            q--;
        }

        reverse(numbers.begin(), numbers.end());

        while (numbers.size() > 2 && q > 0 && numbers[numbers.size() - 2] < 0) {
            numbers[0] -= numbers[numbers.size() - 2];

            // ll x = numbers.back();
            // numbers.pop_back();
            // ll y = numbers.back();
            // numbers.pop_back();
            // numbers.push_back(x + y);
            // arr[0]-=numbers[numbers.size() - 2];
            // p--;
            numbers.erase(numbers.end() - 2);
            // arr.erase(numbers.end() - 2);

            // ll x = numbers.back();
            // numbers.pop_back();
            // ll y = numbers.back();
            // numbers.pop_back();
            // numbers.push_back(x + y);
            // p--;
            q--;
        }

        cout << numbers[0] - numbers[numbers.size() - 1] +sum*m << endl;
    
}

int main()
{
    // #ifdef Priyansh31dec
    //     freopen("Error.txt", "w", stderr);
    // #endif
    fastio();
    auto start1 = high_resolution_clock::now();
    int t;
    cin >> t;
    while (t--){
        solve();
    }
       
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef Priyansh31dec
    cerr << "Time: " << duration.count() / 1000 << " ms" << endl;
#endif
}




/*



Chadda and his Wizard friend PSC were exploring the enchanted forest on Halloween, when Chadda stumbled upon an array  A of  N magical numbers which took him into a different world.
 
 
Chadda remembered that PSC gave him two integers P and Q for such a situation.
Using these integers, Chadda can modify the array A as follows:

At most P times, perform the following operation: Pick two elements x and y from A, delete them both from A, and insert   (x+y) into A. This operation can be performed only if A has at least two elements.

At most Q times, perform the following operation:

Pick two elements x and  y from A, delete them both from A, and insert (x−y) into A. This operation can also be performed only if  A has at least two elements. Note that each operation reduces the size of  A by one. The two types of operations (addition and subtraction) can be performed in any order, as long as at most  P addition operations and Q subtraction operations are made.

Let   B denote the final array obtained after performing some (possibly, zero) operations. To return to his original world, Chadda has to find the maximum possible value of max(B)−min(B)


*/



/*



Once upon a time, in a distant land, a mischievous witch spied on a group of people who were enjoying their time together.

Enveloped by a dark desire, she resolved to put an end to their merry gatherings and kill all  N people.  There are N people, and the witch knows that the i-th of them has a strength of   Ai . The witch also knows of M friendships, each between two people. 

Friendship is transitive, that is, if X and Y are friends and Y and Z are friends, then X and   Z are also friends.
The witch wants to kill all these people in a particular sequence known as a spooky sequence.  A sequence   S is called a spooky sequence if it satisfies the following properties:   S contains   N distinct integers, each between  1 1 and   N. That is,   S is a linear order of the   N people. For any  1 ≤  <  ≤  1≤i<j≤N, if    S  i ​   and    S  j ​   are friends, then     ≤    A  S  i ​   ​  ≤A  S  j ​   ​   should hold. That is, for any two friends, one with strictly higher strength cannot appear earlier in the sequence than the other. Find the total number of spooky sequences. The answer can be large, so print it modulo  10^9 + 7.  Input Format The first line of input will contain a single integer   T, denoting the number of test cases. Each test case consists of multiple lines of input. The first line of each test case contains two space-separated integers   N and   M — the number of people and number of friendships, respectively. The next   M lines describe the friendships. The   i-th of these   M lines contains two space-separated integers    u  i ​   and    v  i ​  , denoting a friendship between    u  i ​   and    v  i ​  . The last line contains   N space-separated integers   1 ,  2 , … ,   A  1 ​  ,A  2 ​  ,…,A  N ​   — the strengths of the people. 



*/