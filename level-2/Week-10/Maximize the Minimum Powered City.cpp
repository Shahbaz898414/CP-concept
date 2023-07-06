#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define Time cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
#define pb push_back
#define mp make_pair
#define line cout << endl;
#define ff first
#define ss second
#define vi vector<int>
#define no cout << "NO" << endl;
#define yes cout << "YES" << endl;
#define printv(v)                      \
  for (int i = 0; i < (v.size()); i++) \
  {                                    \
    cout << v[i] << " ";               \
  }                                    \
  line;
#define onesbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define sp(x, y) fixed << setprecision(y) << x
#define w(x) \
  int x;     \
  cin >> x;  \
  while (x--)
#define tk(x) \
  int x;      \
  cin >> x;
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
#define debug(x)     \
  cerr << #x << " "; \
  _print(x);         \
  cerr << endl;
#else
#define debug(x)
#endif
template <class T>
void _print(T t)
{
  cerr << t;
}

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
void _print(vector<vector<T>> v)
{
  cerr << "[\n";
  for (int l = 0; l < v.size(); l++)
  {
    {
      for (int k = 0; k < v[l].size(); k++)
        cerr << v[l][k] << " ";
    }
    cerr << "\n";
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

// const long long inf = 1e18;
// const int MOD = 998244353;
// const int MAX = 1e6;

bool isValid(string s)
{
  int len = s.size();
  for (int i = 0; i < len / 2; i++)
  {
    if (s[i] != s[len - 1 - i])
      return false;
  }
  return true;
}

void rotateMatrix(vector<vector<int>> &v, int n)
{
  for (int i = 0; i < n / 2; i++)
  {
    for (int j = i; j < n - i - 1; j++)
    {
      int ptr = v[i][j];
      v[i][j] = v[n - 1 - j][i];
      v[n - 1 - j][i] = v[n - 1 - i][n - 1 - j];
      v[n - 1 - i][n - 1 - j] = v[j][n - 1 - i];
      v[j][n - 1 - i] = ptr;
    }
  }
}

// ll m = 998244353;



// long long erfd(long long a, long long b)
// {
//   if (b == 0)
//     return 1;
//   long long ans = erfd(a, b / 2);
//   if (b % 2)
//     return (ans % m * ans % m * a) % m;
//   else
//     return ans % m * ans % m;
// }



int f(int d)
{
  for (int j = 2; j <= sqrt(d); j++)
  {
    if (d % j == 0)
      d = f(d + 1);
  }

  return d;
}



unsigned long long gcd(unsigned long long x, unsigned long long y)
{
  if (y == 0)
    return x;
  return gcd(y, x % y);
}



long long maxPower(vector<int>& v, int r, int k) {
      int n=v.size();



}




int32_t main() {
 
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // int t;
  // cin >> t;
  // while (t--)
  // {


  int n,r,k;
  cin >> n >>r>>k;
  vector<int>  arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

 cout<< maxPower(arr,r,k);

 


  // cout<<n*(m)<<endl;

  // }

  

  return 0;
}


/*

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size(); 
        long long lo = 0, hi = 2e10; 
        while (lo < hi) {
            long long mid = lo + (hi-lo+1)/2, prefix = 0; 
			int kk = k; 
			bool ok = true; 
			vector<int> ss = stations; 
            for (int i = 0; i < n+r; ++i) {
                if (i < n) prefix += ss[i]; 
                if (i >= 2*r+1) prefix -= ss[i-2*r-1]; 
                if (i >= r && prefix < mid) {
                    if (kk < mid - prefix) {
						ok = false; 
						break; 
					}						
                    kk -= mid - prefix; 
                    if (i < n) ss[i] += mid - prefix; 
                    prefix = mid; 
                }
            }
            if (ok) lo = mid; 
            else hi = mid-1; 
        }
        return lo; 
    }
};


*/


/*


class Solution {
public:
    bool check(long long  mid , vector<long long>  ans, int r , int k){
        long long sum=0;
        int n=ans.size();
        for(int i=0;i<r;i++)
            sum+=ans[i];
        for(int i=0;i<n;i++){
            sum+=((i+r<=n-1)?ans[i+r]:0)-((i-r-1>=0)?ans[i-r-1]:0);
            if(sum<mid){
                    if(mid-sum>k)
                        return false;
                if(i+r<=n-1)ans[i+r]+=mid-sum;
                k-=mid-sum;
                sum=mid;
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        long long  l=0;
        long long h=k;
        int n=stations.size();
        for(int i=0;i<n;i++)
            h+=1LL*stations[i];
        vector<long long> ans(n);
        for(int i=0;i<n;i++)
            ans[i]=stations[i];
        while(l<h){
            long long  mid=h+(l-h)/2;
            if(check(mid,ans,r,k))
                l=mid;
            else
                h=mid-1;
        }
        return l;
    }
};


*/




/*


class Solution {
public:
    #define ll long long

    bool check(vector<ll>&arr,int r,int k,ll mid,ll n){
        ll sum=0;
        vector<ll>container(n,0);
        for(ll i=0;i<n;i++){
            sum+=container[i];
            ll diff=mid-(arr[i]+sum);
            if(diff>0){
                if(k<diff){
                    return false;
                }
                k-=diff;
                sum+=diff;
                if(i+(r<<1)+1<n){
                    container[i+(r<<1)+1]-=diff;
                }
            }
        }
        return true;
    }

    vector<ll> pre(vector<int>&stations,ll n,int r){
        ll sum=0,i=0;
        vector<ll>answer(n);
        while(i<n && i<=r){
            sum+=stations[i];
            answer[i]=sum;
            i++;
        }
        while(i<n){
            sum+=stations[i]-stations[i-r-1];
            answer[i]=sum;
            i++;
        }
        return answer;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        ll n=stations.size(),sum=0;
        vector<ll>arr(n),prefix=pre(stations,n,r);
        reverse(stations.begin(),stations.end());
        vector<ll>suffix=pre(stations,n,r);
        reverse(suffix.begin(),suffix.end());
        reverse(stations.begin(),stations.end());
        for(ll i=0;i<n;i++){
            arr[i]=prefix[i]+suffix[i]-stations[i];
        }
        ll low=0,high=1e18,mid,answer;
        while(low<=high){
            mid=(low+high)>>1;
            if(check(arr,r,k,mid,n)){
                answer=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return answer;
    }
};

*/








/*


class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        long long left = 1;
        long long right = 0;

        for(int ele: stations) {
            right += ele;
        }
        right += k+1;

        long long pre_sum = 0;
        vector<long long> cur_powers;
        for(int i=0;i<stations.size();i++) {
            pre_sum += stations[i];
            if(i>=r+1) {
                pre_sum -= stations[i-r-1];
            }
            cur_powers.push_back(pre_sum);
        }


        long long suffix_sum = 0;
        for(int i=stations.size()-1;i>=0;i--) {
            if(i+r+1<stations.size()) {
                suffix_sum -= stations[i+r+1];
            }

            cur_powers[i] += suffix_sum;
            suffix_sum += stations[i];
        }


        std::function<bool(long long, int)> check_func = [&](long long mid, int k) {
            long long pre_sum = 0;
            vector<long long> tmp(cur_powers.size(), 0);
            long long cur = 0;
            long long total_add = 0;

            for(int i=0;i<cur_powers.size();i++) {
                if(i-r-1>=0) {
                    cur -= tmp[i-r-1];
                }

                if(cur_powers[i] + cur < mid) {
                    long long add = mid-cur_powers[i]-cur;
                    if(i+r<cur_powers.size()) {
                        tmp[i+r] = add;
                    }else {
                        tmp[tmp.size()-1] = add;
                    }

                    cur += add;
                    total_add+=add;
                }

                if(total_add>k) {
                    return false;
                }
            }
             return true;    
        };

        while(left < right) {
            long long mid = (left+right)/2;
            bool check_flag = check_func(mid, k);
            if(check_flag) {
                left = mid+1;
            }else {
                right = mid;
            }
        }


        return left-1;
    }

    
};


*/