#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

// using namespace std;

#define ll long long
typedef pair<ll, ll> II;
typedef vector<II> VII;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define PB push_back
#define F first
#define S second

int main(){
   int t=1;
//    cin>>t;

   while(t--){
   int n,k,d=2; 
    cin>>n>>k;
	vector<int> a;
	while (d<=n && k)
	{


        cout<<d<<" ";


		if (k==1) d=n;


		if (n%d==0)  n/=d, a.push_back(d), k--;


		else d++;


	}


    cout<<endl;


	if (k==0)
		for (int v: a) cout<<v<<' ';
	else
		cout<<-1;
    
   }
}