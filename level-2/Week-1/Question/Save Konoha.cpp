#include<bits/stdc++.h>
#define ll long long
using namespace std;



int main() {
  
  int t;cin>>t;
  while(t--) {
    int N , Z; cin >> N >>Z ;
    priority_queue<int> pq;
    
    int arr[N];
    int ans = 0;
    
    for(int i = 0 ; i < N ; i++) {
        cin>>arr[i];
        pq.push(arr[i]);
    }

    for(!pq.empty()) {
      cout<<pq.top()<<" ";
      pq.pop();
    }

    

    cout<<endl;
    
    // while(pq.size() && Z > 0){
    //     int x = pq.top();
    //     Z -= x;
    //     pq.pop();
        
    //     if(x/2>0)
    //     pq.push(x/2);
        
    //     ans++;
    // }
    // if(Z<=0)
    //     cout<<ans<<endl;
    // else
    //     cout<<"Evacuate"<<endl;


  }


  return 0;
}