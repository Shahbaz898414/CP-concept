#include <bits/stdc++.h>
using namespace std;
#define ll long long

string fact( vector<vector<char>> &arr)
{

  for ( auto &row : arr)
  {
    if (row[0] == row[1] && row[0] == row[2])
    {
      if (row[0] == 'X')
        return "X";
      else if (row[0] == 'O')
        return "O";
      else if (row[0] == '+')
        return "+";
    }
  }

  for (int col = 0; col < 3; col++)
  {
    if (arr[0][col] == arr[1][col] && arr[0][col] == arr[2][col])
    {
      if (arr[0][col] == 'X')
        return "X";
      else if (arr[0][col] == 'O')
        return "O";
      else if (arr[0][col] == '+')
        return "+";
    }
  }

  if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2])
  {
    if (arr[0][0] == 'X')
      return "X";
    else if (arr[0][0] == 'O')
      return "O";
    else if (arr[0][0] == '+')
      return "+";
  }

  if (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0])
  {
    if (arr[0][2] == 'X')
      return "X";
    else if (arr[0][2] == 'O')
      return "O";
    else if (arr[0][2] == '+')
      return "+";
  }

  return "DRAW";
}

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    vector<vector<char>> arr(3, vector<char>(3));
    for (int i = 0; i < 3; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        cin >> arr[i][j];
      }
    }

    string s = fact(arr);
    cout << s << endl;
  }

  return 0;
}


/*

*

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define pb push_back
#define loop(n) for(long long i=0;i<n;i++)
#define rloop(n) for(long long i=n-1;i>=0;i--)

////////////////////////////////////////////

ll m=1e9+7;

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return (res%m * res%m * a)%m;
    else
        return res%m * res%m;
}


//////////////////////////////////////////////////
bool compare(const pair<int, int>& a,
                const pair<int, int>& b)
{
    if (a.first != b.first)
        return (a.first < b.first);
    else
       return (a.second > b.second);
}

//////////////////////////////////////////////

signed main(){

      ios::sync_with_stdio(false);
      cin.tie(nullptr);

      #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output2.txt","w",stdout);
       #endif

int test_cases;
cin>>test_cases;
while(test_cases--){

ll n,m,h,x;
cin>>n>>m>>h;

vector<pair<ll,ll>>vv;
ll b,g;
loop(n){
  vector<ll>v;
  for(int j=0;j<m;j++){
    cin>>x;
    v.pb(x);
  }
  sort(v.begin(), v.end());

  ll one=0,two=0;
  int z=0;
  for( z=0;z<m;z++){
    two+=v[z];
    one+=(two);
    if(two>h)break;
  }
  if(z==m)z--;
  if(two>h){z--;one-=two;}


  vv.pb({z,one});
  if(i==0){
    b=z;
    g=one;
  }
}
sort(vv.rbegin(),vv.rend(),compare);

ll final=0;
for(auto it:vv){
  final++;
  if(it.first==b && it.second==g){
    break;
  }

}
cout<<final<<"\n";
}
    return 0;
}


*/


/*


#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define int long long



void sol(){
    
  int n;
  cin>>n;
//   int ans=0;


for(int i=2;i<=sqrt(n);i++){
    
    int ans = i*i + i + 1;
    int count=i*i;
    for(int j=2;j<n;j++){
        if(ans==n){
            cout<<"yes"<<endl;
            return;
        }
        
        if(ans>n){
            break;
        }
        count*=i;
        ans+=count;
        
        
    }
    
    
    
}
  
  
  
  cout<<"no"<<endl;
  
  
    
    
    return;
}

signed main() {
   int t;
   cin>>t;
   while(t--){
       sol();
   }
   
   
   return 0;
}

*/









