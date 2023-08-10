#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1000000009;
const int mx = 1e6;
ll a[mx];
ll b[mx];

int main()
{

  // ll t; cin >> t;
  // while (t--) {

  ll n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  for (int i = 1; i <= n; i++)
    cin >> b[i];

  int l = 1;
  int r = n + 3;
  int mid;

  // }

  return 0;
}

/*


#include <iostream>
using namespace std;
#define N 60005
int x[N],v[N];
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> x[i];
    for(int i=1;i<=n;i++) cin >> v[i];
    double tmin=0,tmax=1e9;
    for(int i=1;i<=100;i++)
    {
        double tmid=(tmin+tmax)/2;
        double xmin=0,xmax=1e9;
        for(int i=1;i<=n;i++)
        {
            xmin=max(xmin,x[i]-v[i]*tmid);
            xmax=min(xmax,x[i]+v[i]*tmid);
        }
        if(xmin>=xmax) tmin=tmid;
        else tmax=tmid;
    }
    printf("%.12lf\n",tmax);
    return 0;
}



*/

/*

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool isPossible(ll *p, ll *v, ll n, double t){
    double left=-1e9,right=1e9;
    for(ll i=0; i<n; i++){
        left=max(left,p[i]-v[i]*t);
        right=min(right,p[i]+v[i]*t);
    }
    if(left<=right) return true;
    return false;
}

int main(){

    ll n; cin>>n;
    ll p[n]; ll v[n];

    for(ll i=0; i<n; i++) cin>>p[i];
    for(ll i=0; i<n; i++) cin>>v[i];

    double l=0.0,r=1e9,mid;
    while(r-l>1e-6){
        mid=l+(r-l)/2;
        if(isPossible(p,v,n,mid)){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    // printf("%.9lf ",r);
    cout << fixed;
    cout << setprecision(12);
    cout<<r;
    return 0;
}

*/
