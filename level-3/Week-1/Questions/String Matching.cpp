#include <bits/stdc++.h>
using namespace std;

#define ll long long

int const mod=1e9+7;


long long getHas(string s){
  long long h=0;

  for(auto c:s)  h=( h*31+( c-'a'+1 ) )%mod;

  return h;

}

int mpow(int a, int b, int m) // (a^b)%mod
{
	if (b == 0)
		return 1;
	int x = mpow(a, b / 2, m);
	x = (x * x) % m;
	if (b % 2)
	{
		x = (x * a) % m;
	}
	return x;
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();
 
    if(m>n){
        cout << 0 << endl;
        return 0;
    }
 
    vector<int> p_pow(n+1,1); // (p^i)%mod
    vector<int> inverse_p_pow(n+1,-1); // (1/p^i) % mod
    for(int i = 1;i <=n; i+=1) p_pow[i] = (p_pow[i-1]*31)%mod;
 
    inverse_p_pow[n] = mpow(p_pow[n],mod-2,mod);
 
    for(int i = n-1; i>=0; i--) inverse_p_pow[i] = ((31)*inverse_p_pow[i+1])%mod;
 
    vector<int> prefixHash(n); 
    for(int i =0;i<n; i+=1){
        prefixHash[i] = (a[i]-'a'+1)*p_pow[i];
        if(i) prefixHash[i] += prefixHash[i-1];
        prefixHash[i] %= mod;
    }


    int hashToCompare = 0; 
    for(int i =0;i <m; i+=1){
        hashToCompare += (b[i]-'a'+1)*p_pow[i];
        hashToCompare %= mod;
    }
    int answer =0;
    
    for(int i =0;i<n; i+=1){
        if((i+m-1)>=n) break;
        int substringHash = prefixHash[i+m-1];
        if(i){
            substringHash -= prefixHash[i-1];
        }
        substringHash = (substringHash%mod + mod)%mod;
        int denominator = inverse_p_pow[i];  // we need to divide the hash by p^i
        substringHash = (substringHash*denominator)%mod;
        if(substringHash == hashToCompare) answer += 1;
    }
    cout << answer << endl;



   
    return 0;
}