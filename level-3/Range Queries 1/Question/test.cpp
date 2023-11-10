#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;



int main() {

    int t;cin>>t;

    while(t--){

    int n,m;cin>>n>>m;

    vector<int>  v1(n);

    int main=0;

    int f=0,j=0;



    for (int i = 0; i < n; i++)
    {
        /* code */
        cin>>v1[i];
    }

    for (int i = 0; i < m; i++){
        main += (v1[i] % 2);
        f+=(v1[i]%2!=0);
    }
        
    int ghn=0,b=0;

    if(main) ghn=1,b=3;

     for (int i = m; i < n; i++)
    {
        main += (v1[i] % 2);
        main -= (v1[i - m] % 2);
         f += (v1[i] % 2!=0);
        f -= (v1[i - m] % 2!=0);
        if (main)
            ghn++;

            if(f) b++;

            b=b*j;
    }
    cout << max(ghn,j )<< endl;
   
   
    }
  
    return 0;
}



