

#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits(x) __builtin_popcountll(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

#ifdef Priyansh31dec
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

using ll = long long;
using ull = unsigned long long;
using lld = long double;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case " << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 

/*--------------------------------------------------------------------------------------------------------------------------*/
void topo_sort(int curr, vector<vector<int>>& edges, vector<bool>& vis, vector<int>& topoSort, int &inserted){
    vis[curr] = true;
    for(auto i : edges[curr]){
        if(!vis[i]){
            topo_sort(i, edges, vis, topoSort, inserted);
        }
    }
    int n = sz(edges);
    topoSort[n - inserted - 1] = curr; 
    inserted++;
}
void dfs(int curr, vector<vector<int>>& edges, vector<bool>& vis, vector<int>& comp){
    comp.push_back(curr + 1);
    vis[curr] = true;
    for(auto i : edges[curr]){
        if(!vis[i]){
            dfs(i, edges, vis, comp);
        }
    }
}

class SegTree
{
    public:
    const int N = 5000005;
 
    int n;  // array size
    ll   *sum_tree;
    ll  res = 0;
 
    SegTree(vector<int> &arr, int n)
    {
        sum_tree = new ll [N];
        this->n = n;
        build(arr);
    }
 
    void build(vector<int> &arr)
    {
        for (int i = 0; i < n; ++i)
        {
            sum_tree[n+i]=arr[i];
        }
 
        for (int i = n - 1; i > 0; --i)
        {
            sum_tree[i] = sum_tree[i<<1] + sum_tree[i<<1|1];
        }
    }
 
    void result(int l, int r)
    {
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l&1)
            {
                res = res + sum_tree[l++];
            }
 
            if (r&1)
            {
                res = res + sum_tree[--r];
            }
        }
    }
 
    ll  getSum(int l, int r)
    {
        if(l > r)       return 0;
        res = 0;
        result(l, r);
 
        return res;
    }
 
    void update(int p, ll  value)
    {   // set value at position p
        for(sum_tree[p += n] = value; p > 1; p >>= 1)
        {
            sum_tree[p>>1] = (sum_tree[p] + sum_tree[p^1]);
        }
    }


};


 int ans=0;


vector<long long>merge(vector<long long>&v1, vector<long long>&v2){
        long long l1=v1.size();
        long long l2=v2.size();
        vector<long long>v;
        long long pt1=0,pt2=0;
        while(pt1<l1 && pt2<l2){
            if(v1[pt1]<=v2[pt2]){
                v.push_back(v1[pt1]);
                pt1++;
            }else{
                v.push_back(v2[pt2]);
                pt2++;
            }
        }
        while(pt1<l1){
            v.push_back(v1[pt1]);
            pt1++;
        }
        while(pt2<l2){
            v.push_back(v2[pt2]);
            pt2++;
        }
        cout<<"merge ";
        for(auto it:v){
          cout<<it<<" ";
        }

        cout<<endl;
        return v;
}



vector<long long> mergeSort(int l,int h,vector<int>& nums){

        if(l==h)return {nums[l]};

        long long m=(l+h)/2;

        vector<long long>v1 = mergeSort(l,m,nums);

        vector<long long>v2 = mergeSort(m+1,h,nums);


        long long l1=v1.size(), l2=v2.size();
        long long p1=0,p2=0;
        while(p1<l1 && p2<l2){
             if(v1[p1] <= 2*v2[p2]){
                 p1++;
             }else{
                 ans+=l1-p1;
                 p2++;
             }
        }

        for(auto it:v1){
          cout<<it<<" ";
        }

        cout<<" >> v1 and v2 << ";
        for(auto it:v2){
          cout<<it<<" ";
        }

        cout<<endl;
        return merge(v1,v2);
}




void solve() {


   int n;cin>>n;


   vector<int>  arr(n);


    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }

   vector<long long> v=mergeSort(0,n-1,arr);



        cout<<ans;

        
    cout<<endl;
    


}



int main() {
// #ifdef Priyansh31dec
//     freopen("Error.txt", "w", stderr);
// #endif


    fastio();
    auto start1 = high_resolution_clock::now();

    int t=1;
    // cin>>t;
    while(t--)
      solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef Priyansh31dec
    cerr << "Time: " << duration . count() / 1000 << " ms" << endl;
#endif
}








