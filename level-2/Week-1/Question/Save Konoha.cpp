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
        pq.push(-1*arr[i]);
    }

    // while(!pq.empty()) {
    //   cout<<-1*pq.top()<<" ";
    //   pq.pop();
    // }

    // cout<<endl;
    

    while(pq.size() && Z > 0){
        int x = pq.top();
        Z -= x;
        pq.pop();
        
        if(x/2>0)
        pq.push(x/2);
        
        ans++;
    }
    if(Z<=0)
        cout<<ans<<endl;
    else
        cout<<"Evacuate"<<endl;


  }


  return 0;
}


/*
\sectionsep
\section{ACHIEVEMENTS}
\textbullet{} A 4* programmer on CodeChef (Rating: 1860) \\

\textbullet{} Global Rank 76 in CodeChef Jan Starters 72, 2023.  \\

\textbullet{} Global Rank 106 in CodeChef Dec Starters 71, 2022.\\

\textbullet{} Ambassador of internshala from Shree LR Tiwari College.\\

\vspace{2mm}
\sectionsep

*/