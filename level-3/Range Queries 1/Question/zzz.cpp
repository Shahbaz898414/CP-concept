#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

class SegTree
{
public:
    const int N = 5000005;
    int n; // array size
    ll *sum_tree;
    ll res = 0;

    SegTree(vector<int> &arr, int n)
    {
        sum_tree = new ll[N];
        this->n = n;
        build(arr);
    }

    void build(vector<int> &arr)
    {
        for (int i = 0; i < n; ++i)
        {
            sum_tree[n + i] = arr[i];
        }

        for (int i = n - 1; i > 0; --i)
        {
            sum_tree[i] = sum_tree[i << 1] + sum_tree[i << 1 | 1];
        }
    }

    void result(int l, int r)
    {
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
            {
                res = res + sum_tree[l++];
            }

            if (r & 1)
            {
                res = res + sum_tree[--r];
            }
        }
    }

    ll getSum(int l, int r)
    {
        if (l > r)
            return 0;
        res = 0;
        result(l, r);

        return res;
    }

    void update(int p, ll value)
    { // set value at position p
        for (sum_tree[p += n] = value; p > 1; p >>= 1)
        {
            sum_tree[p >> 1] = (sum_tree[p] + sum_tree[p ^ 1]);
        }
    }
};

void solve() {


   ll n;cin>>n;

   ll sum=0;

   vector<ll>  arr(n);

   for (ll i = 0; i < n; i++) {
      cin>>arr[i];

      sum+=arr[i];
   }
   if(n==2)  cout<<"YES"<<endl;
   else {

    if(sum%2==0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }


   }
   


}




int main()
{

    int t;cin>>t;
    while(t--)
    solve();
    return 0;
}
