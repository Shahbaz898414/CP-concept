#include <bits/stdc++.h>
using namespace std;

int main()
{

    
    int t;cin>>t;
    
    while(t--) {
        int n;cin>>n;
        
        
        int a[n];
       long long int alt=0;
        
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        for(int i=0;i<n;i++) { 
            if(i%2==0) {
                alt-=a[i];
            }else {
                alt+=a[i];
            }
                
        }
        
        // ghbg
        
        if(n%2==1 || alt>=0) {
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}