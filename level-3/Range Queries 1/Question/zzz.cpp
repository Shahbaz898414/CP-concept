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

   ll x=0;

   vector<ll>  arr(n);



   for (ll i = 0; i < n; i++) {
      cin>>x;

   }
  


}




int main()
{

    int t;cin>>t;
    while(t--)
    solve();
    return 0;
}




/*


Today was my 24th day out of the 100 days  hard challenge.

So today, I solved 5 problems .

1. Binary Substitution  (https://www.codechef.com/problems/SUBSBIN)


2. Sum of Goodness  (https://www.codechef.com/problems/SEQGOODNESS)


3. Xor Equation (https://www.codechef.com/problems/XOREQN)


4. Dividing into Groups (https://www.codechef.com/problems/DIVIDE_GROUP)


5. Cherry and Bits (https://www.codechef.com/problems/CENS20A)





 int cnt1 = 0, cnt2 = 0, ze = 0, ze2 = 0;

       
        for (int num : nums1) {
            cnt1 += num;
            if (num == 0) ze++;
        }
        for (int num : nums2) {
            cnt2 += num;
            if (num == 0) ze2++;
        }

        
        if (cnt1 == cnt2) return cnt1;

        
        if ((cnt1 + cnt2) % 2 != 0 || (ze + ze2) == 0) return -1;

      
        int sum = (cnt1 + cnt2) / 2;

   
        if (sum < max(cnt1 - ze, cnt2 - ze2)) return -1;

       
        int diff = sum - max(cnt1 - ze, cnt2 - ze2);

       
        if (diff <= ze + ze2) return sum;

        
        return -1;

*/