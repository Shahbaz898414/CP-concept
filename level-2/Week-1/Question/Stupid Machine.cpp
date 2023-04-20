#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
	  int n; cin>>n;
	    long long int a[n];
	    for(int i=0;i<n;i++)cin>>a[i];
	    long long int ans=a[0];
	    long long int  m=a[0];
	    for(int i=1;i<n;i++) {
	        m=min(m,a[i]);
	        ans+=m;
	    }

	    cout<<ans<<"\n";
	}
	return 0;
}