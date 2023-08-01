#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lld long long int

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin >> t;
  while (t--)
  {
    int n;
        cin>>n;
        int a[2*n];
        for(int i=0;i<2*n;i++)
        {
            cin>>a[i];
        }
        sort(a,a + 2*n); 
        int maxm=0,mc=1;
        for(int i=0;i<2*n ;i++)
        {
            if(a[i]==a[i+1])
            {
                mc++;
            }
            else
            {   
                maxm=max(maxm,mc);
                mc=1;
            }
        }
    int dis= 2*n - maxm;
    int zero= (maxm - dis)/2;
    if(zero-dis>1)
    {
        cout<<"NO"<<endl;
    }
    else
    cout<<"YES"<<endl;
    
  }

  return 0;
}