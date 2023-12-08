#include <bits/stdc++.h>
using namespace std;


const int N = 3e5+9;
int d1[N], d2[N];
vector<int> g[N];
void dfs(int v, int p=-1, int d=0) {
    d1[v] = d;
    for(auto nei : g[v])
        if(nei!=p)
            dfs(nei,v,d+1);
}



int main() {

  int n; cin>>n;
    for(int i=0;i<n-1;++i) {
        int a,b; cin>>a>>b; --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0);
    dfs(max_element(d1,d1+n)-d1);
    memcpy(d2,d1,n*4);
    dfs(max_element(d1,d1+n)-d1);
    int diam = *max_element(d1,d1+n);
    for(int i=0;i<n;++i) cout<< diam + (max(d1[i],d2[i])==diam) << '\n';

  
    
  
  return 0;
}



/*



#include <bits/stdc++.h>

using namespace std;

const int N = 3e5+9;
int d1[N], d2[N];
vector<int> g[N];
void dfs(int v, int p=-1, int d=0) {
    d1[v] = d;
    for(auto nei : g[v])
        if(nei!=p)
            dfs(nei,v,d+1);
}

int main() {
    int n; cin>>n;
    for(int i=0;i<n-1;++i) {
        int a,b; cin>>a>>b; --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0);
    dfs(max_element(d1,d1+n)-d1);
    memcpy(d2,d1,n*4);
    dfs(max_element(d1,d1+n)-d1);
    int diam = *max_element(d1,d1+n);
    for(int i=0;i<n;++i) cout<< diam + (max(d1[i],d2[i])==diam) << '\n';
}







#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int n,ma,m,s,f[300010],a[300010],t,sum[300010];
vector<int>v[300010];

void dfs(int x,int c,int y,int k){
	if(c>ma){
		ma=c;
		t=k;
	}
	if(c==ma){
		t++;
		a[t]=x;
	}
	for(auto u:v[x]){
		if(u!=y) dfs(u,c+1,x,k);
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n;
	for(int x,y,i=1;i<n;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0,0,0);
	dfs(a[1],0,0,t);
	dfs(a[2],0,0,t);
//	for(int i=1;i<=s;i++){
//		dfs(a[i],0,0,t);
//	}
	for(int i=1;i<=t;i++){
		sum[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(sum[i]) cout<<ma+1<<endl;
		else cout<<ma<<endl;
	}
	return 0;
}
    	    	   	  	 			  		    	


*/



/*


#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5;

vector <int> g[N*3 + 5];
int mx=0;

unordered_set <int> se[2];

void dfs(int u,int p,int depth,int f){
	if(mx<depth){
		mx=depth;
		se[f].clear();
		se[f].insert(u);
	}
	else if(mx==depth){
		se[f].insert(u);
	}
	for(auto v:g[u]){
		if(v!=p){
			dfs(v,u,depth+1,f);
		}
	}
}

int solve(int n){
	mx=0;
	
	dfs(1,-1,0,0);
	
	dfs(*se[0].begin(),-1,0,1);
	
	return mx;
}

signed main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	int h = solve(n);
	
	for(int i=1;i<=n;i++){
		if((se[0].count(i) >0)||(se[1].count(i) >0)){
			cout<<mx+1<<endl;
		} else{
			cout<<mx<<endl;
		}
	}
}



*/