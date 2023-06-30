// #include <bits/stdc++.h>
// #define ll long long int
// using namespace std;

// int main()
// {

//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);

//   // ll t;cin>>t;

//   // while(t--) {

//   // }

//   ll n, m;
//   cin >> n;

//   ll a[n], b[n], total = 0, ans;

//   for (int i = 0; i < n; i++)
//   {
//     cin >> a[i];
//   }

//   ll sum = 0;

//   string s;
//   cin >> s;

//   ll len = s.size();

//   return 0;
// }




#include <bits/stdc++.h>
using namespace std;
int main()
{
  int i,mxnum=0,n,sum;
  cin>>n;

  int a[n];


  for(i=0;i<n;i++)cin>>a[i];


  string s;cin>>s;


  for (i=0;i<n;i++){

    mxnum=max(mxnum,a[i]);

    if(s[i]=='0'&&mxnum>i+1) {
      cout<<"NO";
      return 0;
    }
  }


  cout<<"YES";

    return 0;
}

