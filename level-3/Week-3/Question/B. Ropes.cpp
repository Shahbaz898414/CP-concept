

#include<bits/stdc++.h>
using namespace std;
#define ll long long


int prd(vector<int>  &a,int  k,double x)
{
    if(x==0)  return true;

    int cnt=0;

    for (int i = 0; i < a.size(); i++)
    {
        /* code */
        cnt+=a[i]/x;
    }

    return cnt>=k;
    
}

int main() {
    int n,k; cin >> n>>k;
    vector<int> a(n);
    for(ll i = 0; i < n; i++) {
        cin>>a[i];
    }

    double l=0,r=1e8,mid;

    int lp=100;

    while(lp--){
        mid=l+(r-l)/2;
        if(prd(a,k,mid)){
            l= mid;
        }else{
            r=mid;
        }
    }

    cout<<l<<endl;


}












/*


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iomanip>

using namespace std;
#define MOD 1000000007
#define INF 5e18
typedef long long ll;

int prd(vector<int> &a, int k, double x)
{
    if (x == 0) return true;
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i)
        cnt += a[i] / x;
    return cnt >= k;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    for (auto &i : a) cin >> i;

    double l = 0, r = 1e8, mid;
    int lp = 100;
    while (lp--)
    {
        mid = l + (r - l) / 2;
        if (prd(a, k, mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << '\n';
}

*/
