#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 998244353;
ll n;

map<ll,ll> mp;
// ll   f[2][100001],a[2][100001];

ll f(ll i){
  if(i==n)  return 1;
  if(i>n)  return n;

  if(mp.find(i)!=mp.end()){
    return mp[i];
  }

  ll ans=0;

  for (ll x = 2; x <=6; x++)
  {
    /* code */
    ans=(ans+f(x*i)*inv(5))%mod;
  }

  mp[i]=ans;

  return mp[i]%mod;
  
}


void solve(){
  cin>>n;
  cout<<f(1)<<endl;
}

int main() {


  ios_base::sync_with_stdio(0);
  cin.tie(0);



  solve();


}





/*


Problem Statement 
You have an integer  1 and a die that shows integers between  1 and  6 (inclusive) with equal probability. You repeat the following operation while your integer is strictly less than  N:  Cast a die. If it shows  x, multiply your integer by  x. Find the probability, modulo  998244353, that your integer ends up being  N.  How to find a probability modulo  998244353? We can prove that the sought probability is always rational. Additionally, under the constraints of this problem, when that value is represented as  Q P ​   with two coprime integers  P and  Q, we can prove that there is a unique integer  R such that  R×Q≡P(mod998244353) and  0≤R<998244353. Find this  R.


Constraints
2≤N≤10^18   
N is an integer.


Sample Input
6

Output
239578645

One of the possible procedures is as follows.
Initially, your integer is  1. You cast a die, and it shows  2. Your integer becomes  1×2=2. You cast a die, and it shows  4. Your integer becomes  2×4=8. Now your integer is not less than  6, so you terminate the procedure. Your integer ends up being  8, which is not equal to  N=6.  The probability that your integer ends up being  6 is  7/25 ​  . Since  239578645×25≡7(mod998244353), print  239578645.



*/