#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  
  int a,b,c,d;cin>>a>>b>>c>>d;
   int m2=max(a,b);
   int m1=min(a,b);
   int m3=min(c,d);
   int m4=max(c,d);

   if(m3>m2){
    cout<<-1<<endl;
   }else {
    if(m1==m3) 
      cout<<m2<<" "<<m3<<endl;
    else {
      if(m2>m4){
        cout<<m3<< " "<<m4<<endl;
      }else {
        cout<<m3<<" "<<m2<<endl;
      }
    }  

   }

   




  return 0;
}