#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct segtree
{
  struct node
  {
    int max;
    int modify;
  };

  const int NO_OP = INT_MAX;

  int size;
  vector<node> tree;

  void build(int n)
  {
    size = 1;
    while (size < n)
      size *= 2;
    tree.assign(2 * size, {0, NO_OP});
  }

  int _modify(int a, int b)
  {
    if (a == NO_OP)
      return b;
    return a + b;
  }

  void propagate(int x, int lx, int rx)
  {
    if (tree[x].modify == NO_OP || rx == lx + 1)
      return;
    tree[2 * x + 1].modify = _modify(tree[2 * x + 1].modify, tree[x].modify);
    tree[2 * x + 1].max = tree[2 * x + 1].max + tree[x].modify;
    tree[2 * x + 2].modify = _modify(tree[2 * x + 2].modify, tree[x].modify);
    tree[2 * x + 2].max = tree[2 * x + 2].max + tree[x].modify;
    tree[x].modify = NO_OP;
  }

  void update(int l, int r, int v)
  {
    update(l, r, v, 0, 0, size);
  }

  void update(int l, int r, int v, int x, int lx, int rx)
  {
    propagate(x, lx, rx);
    if (lx >= r)
      return;
    if (rx <= l)
      return;
    if (lx >= l && rx <= r)
    {
      tree[x].modify = v;
      tree[x].max += v;
    }
    else
    {
      int m = (lx + rx) / 2;
      update(l, r, v, 2 * x + 1, lx, m);
      update(l, r, v, 2 * x + 2, m, rx);
      tree[x].max = max(tree[2 * x + 1].max, tree[2 * x + 2].max);
    }
  }

  int get(int v, int l)
  {
    return get(v, l, 0, 0, size);
  }

  int get(int v, int l, int x, int lx, int rx)
  {
    propagate(x, lx, rx);

    if (rx <= l)
      return -1;
    if (tree[x].max < v)
      return -1;
    if (rx == lx + 1)
      return lx;

    int m = (lx + rx) / 2;
    int res = get(v, l, 2 * x + 1, lx, m);
    if (res == -1)
      res = get(v, l, 2 * x + 2, m, rx);
    return res;
  }
};

int main(void)
{
  int n, m;
  cin >> n >> m;

  

  return 0;
}



/*











#include<bits/stdc++.h>
using namespace std;
long long n,m,k,q,p,i,j,a[11][100002],ans;
int main(){
    cin>>n>>k; q=n;
    while (q--){
        cin>>p;
        for (i=k; i>=0; i--){
            m=0;
            if (i>0) for (j=p-1; j>0; j-=j&-j) m+=a[i][j];
            else m=1;
            if (i<k) for (j=p; j<=n; j+=j&-j) a[i+1][j]+=m;
            else ans+=m;
        }
    }
    cout<<ans;
}













#include<stdio.h>
#define ll long long
ll tr[12][100010];
int n,k;
int lowbit(int x){return x&-x;}
ll query(int x,int i){
	ll s=0;
	while(i>0){
		s+=tr[x][i];
		i-=lowbit(i);
	}
	return s;
}
void add(int x,int i,ll a){
	while(i<=n){
		tr[x][i]+=a;
		i+=lowbit(i);
	}
}
int main(){
	int i,j,x;
	ll t;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		for(j=k+1;j>0;j--){
			t=(j==1)?1:query(j-1,x-1);
			add(j,x,t);
		}
	}
	printf("%I64d",query(k+1,n));
}











#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll bit[(int)(1e5+1)][12]; int n, K;
void update(int i, int k, ll val){
	for(; i<=n; i+=i&-i) bit[i][k] += val;
}
ll query(int i, int k){
	ll res = 0;
	for(; i; i-=i&-i) res += bit[i][k];
	return res;
}
int main(){
	scanf("%d %d", &n, &K); ++K;
	ll ans = 0; 
	for(int i = 0, x; i<n; ++i){
		scanf("%d", &x);
		for(int k = 1; k<=K; ++k){
			ll T;
			if(k == 1) T = 1;
			else T = query(x-1, k-1); 
			update(x, k, T);
			if(k == K) ans += T;
		}
	}
	printf("%I64d", ans);
}













#include <iostream>
#include <cstdio>

using namespace std;

long long a[13][1<<20];

long long get(int j,int v)
{
    long long res = 0;
    while(v>=0)
    {
        res+=a[j][v];
        v = (v&(v+1))-1;
    }
    return res;
}
void add(int j,int u,long long value)
{
    while(u<(1<<20))
    {
        a[j][u]+=value;
        u = u | (u+1);
    }
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    add(0,0,1);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        for(int j=k;j>=0;j--)
            add(j+1,x,get(j,x));
    }
    cout << get(k+1,n+1)<<endl;
    return 0;
}



*/