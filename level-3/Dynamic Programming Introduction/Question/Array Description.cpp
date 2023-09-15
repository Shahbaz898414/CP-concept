#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define s 5005
ll inf = 1e18;

ll dp[509][509];

int n,m;
int arr[509][509];

int ar[509];
void print(int id,int x){
		cout<<"TAK"<<endl;
		for(int i=0;i<n;i++){
			if(i == id) cout<<x<<" ";
			else cout<<1<<" ";
		}
		cout<<endl; 
		exit(0);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // ll n,m;
    // cin>>n>>m;

    // for //

	cin>>n>>m;

	for (int i = 0; i < n; i++)
  {
    /* code */
    cin>>ar[i];
  }
  


   
    return 0;

}


