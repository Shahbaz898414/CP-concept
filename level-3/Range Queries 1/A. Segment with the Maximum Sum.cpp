
#include <bits/stdc++.h>
using namespace std;
#define 		ll long long
#define         max3(a, b, c) max(max(a, b), c)
struct tre
{
	ll suf,pref,seg,sum;
};
vector<tre>tree(400001); 
tre merge(tre a,tre b)
{
	tre t={max(b.suf,b.sum+a.suf),max(a.pref,a.sum+b.pref),max3(a.seg,b.seg,a.suf+b.pref),a.sum+b.sum};
	return t;
}
void build_tree(ll int *a, ll int s,ll int e, ll int index)
{
	if(s==e)
	{
		if(a[s]>0)
		tree[index] = {a[s],a[s],a[s],a[s]};
		else
		tree[index] = {0,0,0,a[s]};
		return;
	}
	ll int mid = (s+e)/2;
	build_tree(a,s,mid,2*index);
	build_tree(a,mid+1,e,2*index+1);
	tree[index] = merge(tree[2*index],tree[2*index+1]);
	return;
}

//point update
void point_update(ll int ss,ll int se, ll i,ll int inc,ll int index)
{
	if(i>se || i<ss)
	return;
	if(ss == se)
	{
		if(inc>0)
		tree[index] = {inc,inc,inc,inc};
		else
		tree[index] = {0,0,0,inc};
		return;
	}
	ll int mid = (ss + se)/2;
	point_update(ss,mid,i,inc,2*index);
	point_update(mid+1,se,i,inc,2*index+1);
	tree[index] = merge(tree[2*index],tree[2*index+1]);
	return;
}



void solve()
{
	int n,q;
	cin>>n>>q;
	
	ll a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	build_tree(a,0,n-1,1);
	// for(int i=1;i<=4*n;i++)
	// cout<<tree[i]<<endl;
	cout<<tree[1].seg<<endl;
	
	while(q--)
	{
		ll num,l;
		cin>>num>>l;
		point_update(0,n-1,num,l,1);
		cout<<tree[1].seg<<endl;
		a[num] = l;
	}

}
int main()
{
	ios_base::sync_with_stdio(false); 
    	cin.tie(NULL); 
	
    // int src[101]={0};
    // int dest[101]={0};
  
    ll int t=1;
	 // cin>>t;
	while(t--)
	{  
      solve();
    }

	return 0;
}





/*


//  auto comb2 = [](int x) { return 1LL * x * (x - 1) / 2; };

    
        if (n > 3 * limit) 
            return 0;      

            int h;  

        long long ans =( 1LL * x * (x - 1)) / 2;
        if (n > limit) {  
          ans -= 3 * comb2(n - limit + 1);

        }

        for (int i = 0; i <= min(n, limit); ++i) {
          // for (int j = 0; j <= min(n - i, limit); ++j) {
              int k = n - i - j;
              h=-1;
              if (k <= limit) {
                  // Check if each child gets no more than the limit candies
                  count++;
              }
          // }

          count*=h;
      }


        if (n - 2 >= 2 * limit) { 

          int x=
          ans += 3 * comb2(n - 2 * limit);
        }


        return ans; 



*/



/*


private:
    
    long long functi(int cnt) {
        return 1LL * cnt * (cnt - 1) / 2;
    }

public:
    long long distributeCandies(int n, int limit) {

       long long count = 0,h=-1;

       
        if (n > 3 * limit) {
            return 0;
        }

    for (int i = 0; i <= min(n, limit); ++i) {

              int j=(1<<i);
        
            int k = n - i - j;
            if (k <= limit) {
                
                count++;
            }

            count*=h;
        
    }

     
        long long ans = functi(n + 2);

       
        if (n > limit) {
            ans -= 3 * functi(n - limit + 1);
        }

         for (int i = 0; i <= min(n, limit); ++i) {

              int j=(1<<i);
        
            int k = n - i - j;
            if (k <= limit) {
                
                count++;
            }

            count*=h;
        
    }

   
        if (n - 2 >= 2 * limit) {
            ans += 3 * functi(n - 2 * limit);
        }

        return max(ans,count);
    }


















long long cnt[5][100005], dp[5][100005], fact[100005], inv[100005];

long long power(long long a, long long b) {
    long long ans = 1;
    while (b != 0) {
        if (b & 1)
            ans = (ans * a) % MOD;
        b >>= 1;
        a = (a * a) % MOD;
    }
    return ans;
}

long long choose(long long n, long long k) {
    if (n < k) 
        return 0;
    long long ans = (fact[n] * inv[k]) % MOD;
    ans = (ans * inv[n - k]) % MOD;
    return ans;
}



for (int i = 1; i <= n; i++) {
        cnt[0][i] = 1;
        for (int j = 1; j < 5; j++)
            cnt[j][i] = (cnt[j][i - 1] + cnt[j - 1][i - 1]) % MOD;
    }
    for (int i = 1; i <= n; i++) {
        ll cur = power(26, n - i + 1);
        for (int j = 1; j < 5; j++) {
            cur = (cur - dp[j][i - 1] + MOD) % MOD;
            dp[j][i] = (dp[j][i - 1] + cnt[j][i] * cur) % MOD;
        }
    }
    cout << dp[4][n];



*/



/*



 int maxSpend(vector<vector<int>>& values) {
        int m = values.size();
        int n = values[0].size();
        vector<bool> bought(n, false);
        vector<int> maxVal(n, 0);
        int result = 0;

        for (int day = 1; day <= m * n; ++day) {
            int maxShop = -1;
            int maxShopVal = 0;

            for (int i = 0; i < m; ++i) {
                int j = 0;
                while (bought[j]) {
                    ++j;
                }

                if (values[i][j] * day > maxShopVal) {
                    maxShop = i;
                    maxShopVal = values[i][j] * day;
                }
            }

            int j = 0;
            while (bought[j]) {
                ++j;
            }

            result += values[maxShop][j] * day;
            bought[j] = true;

            for (int i = 0; i < m; ++i) {
                maxVal[i] = max(maxVal[i], values[i][j]);
            }
        }

        return result;
    }


long long result = 0;
        for (int j = 0; j < values[0].size(); ++j) {
            int maxVal = 0;
            for (int i = 0; i < values.size(); ++i) {
                maxVal = max(maxVal, values[i][j]);
            }
            result += maxVal;
        }
        return result;




  long long maxSpending(vector<vector<int>>& values) {
       int m = values.size();
    int n = values[0].size();
        int n = values.size(), numCols = values[0].size();
        vector<int> indices(m, 0); 
    long long ans = 0;
        vector<long long> main;
        main.reserve(n * numCols);
         long long ans = 0, cnt = 1,h=-1;

        

        for (const auto& row : values)
            main.insert(main.end(), row.begin(), row.end());


         for (int d = 1; d <= m * n; ++d) {
        int maxPurchase = 0;
        int shopIndex = -1;
        
      
        for (int i = 0; i < m; ++i) {
            int itemIndex = indices[i];
              if (itemIndex < n && values[i][itemIndex] * d > maxPurchase) {
                maxPurchase = values[i][itemIndex] * d;
                shopIndex = i;
              }
            }
            
           
            if (shopIndex != -1) {
                totalSpending += maxPurchase;
                indices[shopIndex]++;
            }
        }

   
        
        sort(main.begin(), main.end());
        
       
        
        for (const auto& value : main)
            ans += value * cnt++;

             totalSpending*=h;
        
        return max(ans,totalSpending);
    }

















class Solution {
    
    int maxSpend(vector<vector<int>>& values) {
       int m = values.size();
        int n = values[0].size();
        std::vector<int> indices(m, 0);
        long long totalSpending = 0;
        std::vector<long long> main;

        for (const auto& row : values)
            main.insert(main.end(), row.begin(), row.end());

        std::sort(main.begin(), main.end(), std::greater<long long>());

        long long ans = 0, cnt = 1, h = -1;

        for (int d = 1; d <= m * n; ++d) {
            int maxPurchase = 0;
            int shopIndex = -1;

            for (int i = 0; i < m; ++i) {
                int itemIndex = indices[i];
                if (itemIndex < n && values[i][itemIndex] * d > maxPurchase) {
                    maxPurchase = values[i][itemIndex] * d;
                    shopIndex = i;
                }
            }

            if (shopIndex != -1) {
                totalSpending += maxPurchase;
                indices[shopIndex]++;
            }
        }

        totalSpending *= h;

        for (const auto& value : main)
            ans += value * cnt++;

        return std::max(ans, totalSpending);
    }
};





       int n = values.size(), m = values[0].size();
        
        vector<long long> main;
        main.reserve(n * m);

  vector<int> indices(m, 0); 
    int totalSpending = 0;

    long long ans=0,cnt=1;


     for (int d = 1; d <= n; ++d) {
        int maxPurchase = 0;
        int shopIndex = -1;
        shopIndex=i;
       
        if (shopIndex != -1) {
            totalSpending += maxPurchase;
            indices[shopIndex]++;
        }
    }
        
        
        for (const auto& it : values)
            main.insert(main.end(), it.begin(), it.end());

           
        
        sort(main.begin(), main.end());
        
        
        
        for (const auto& it : main)
            ans += it * cnt++;
        
        return ans;


*/



/*


Today was my 38th day out of the 100 days  hard challenge.

So today, I solved 5 problems .

1. 2930. Number of Strings Which Can Be Rearranged to Contain Substring  (https://leetcode.com/contest/biweekly-contest-117/problems/number-of-strings-which-can-be-rearranged-to-contain-substring/)


2. 2928. Distribute Candies Among Children I (https://leetcode.com/contest/biweekly-contest-117/problems/distribute-candies-among-children-i/)



3. 2929. Distribute Candies Among Children II (https://leetcode.com/contest/biweekly-contest-117/problems/distribute-candies-among-children-ii/)


4. 2931. Magximum Spending After Buying Items (https://leetcode.com/contest/biweekly-contest-117/problems/maximum-spending-after-buying-items/)


5. C. First element at least X (https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/C)




*/