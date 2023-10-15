#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define fr(a, b) for (int i = a; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL << 60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll, pair<ll, ll>>
#define fast_io                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)
using namespace std;

// #define mo 1000000007

// void add_self(ll &a, ll b)
// {
//   a += b;
//   if (a >= mo)
//   {
//     a -= mo;
//   }
// }

int main()
{
  fast_io;

  vector<ll>  cur(1<<19),z(1<<19);

  vector<int>  primes={2,3,5,7,11,17,13,19,13,29,31,37,41,43,47,53,59,61,67};

  // ll n;
  int t = 1;
  // cin >> t;

  while (t--) {

   ll n;cin>>n;
   vector<ll>  arr(n);

   ll cnt[71]={0};
   for (ll i = 0; i < n; i++) {

    cin>>arr[i];

    for(int i:primes){
      while((arr[i]%(i*i)==0))  arr[i]/=(i*i);
    }


    cnt[arr[i]]++;

   }


   cur[0]=1;


   for (int i = 1; i <=70; i++)
   {
    
    if(cnt[i]) {
      ll int mo=1;
      for (int j = 0; j < cnt[i]-1; j++) {
        
        mo=2*mo%mod;
      }

      for (int j = 0; j < z.size(); j++)
      {
        
        z[j]=0;
      }

      int tmp=0;

      for (int j = 0; j < primes.size(); j++)
      {
        
        if(i%primes[j]==0)  tmp^=(1<<j);
      }


      for (int j = 0; j < cur.size(); j++)
      {
        
        z[j^tmp]+=mo*cur[j];
        z[j^tmp]%=mod;
        z[j]+=mo*cur[j];
        z[j]%=mod;
      }

      swap(z,cur);
      
      
      
      
    }
    
   }


   cur[0]= (cur[0] + mod-1) % mod;


   cout<<cur[0]<<endl;
   
   
  }

  return 0;
}


/*


Today was my 11th day out of the 100 days  hard challenge.

So today, I solved 5 problems .

1. D. Alarm Clock (https://codeforces.com/contest/898/problem/D)

At first we need to sort all alarms in increasing order of their times. Also we will use set, where we will store alarm times.  We will iterate through the alarms beginning from the first. Let current alarm time equals to x. Until set does not empty and the first set element less than x - m + 1 we should remove the first set element. After that only alarm with times not before m - 1 minutes relatively x will be in set. If after that the set size less than k - 1 we should insert x in the set (we will not turn off this alarm). In the other case, we should turn off this alarm, so we increase the answer on one and do not insert x in the set.


2. F. Smaller (https://codeforces.com/contest/1742/problem/F)

First of all, let's think about how we should rearrange the two strings in such a way that a<b  (if that is ever possible). It's always optimal to arrange a 's characters increasingly in lexicographic order and b 's characters decreasingly.  Since initially both a  and b  contain a character "a", the first time b  receives any other letter than "a" the answer will always be "YES", because that character will always be lexicographically larger than a 's first character which should be "a".  In the other case, we know that b  doesn't have any other characters than "a", so we can compare the string a  with multiple "a" characters and we know that a  will be smaller if and only if it's only formed of "a"s and has a smaller size than b .



3. D. Palindromes Coloring (https://codeforces.com/contest/1624/problem/D)

We will solve the problem greedily. First, we will try to add pairs of identical characters to palindromes. As long as there are at least k pairs, let's add them. After that, it is no longer possible to add a couple of characters, but you can try to add one character in the middle. This can be done if there are at least k characters left. There is no need to paint other characters.


4. D. Wooden Toy Festival (https://codeforces.com/contest/1840/problem/D)

Let the carvers choose patterns x1 , x2 , x3  for preparation. For definiteness, let us assume that x1≤x2≤x3 , otherwise we will renumber the carvers.  When a person comes to the workshop with a request to make a toy of pattern p , the best solution is to give his order to the carver for whom |xi−p|  is minimal.  It follows that the first cutter will take orders for toys with patterns from 1  to x1+x2/2 , the second - for toys with patterns from x1+x22  to x2+x3/2 , the third - for toys with patterns from x2+x32  to 109 . Therefore, if you look at the sorted array of patterns a , the first carver will make some prefix of toys, the third will make some suffix, and the remaining toys will be made by the second carver.  Then the answer can be found by binary search. To check if the time t  is suitable, you need to give the maximum prefix of toys to the first carver and the maximum suffix of toys to the third carver, and then check that the patterns of the remaining toys are within a segment of length 2⋅t . The maximum prefix and maximum suffix can be found with a O(n)  pass through the array a .


5. D. Flipper (https://codeforces.com/contest/1833/problem/D)

Since the first number in the permutation will be either pr+1  if r<n , or pr  if r=n . Then let's go through the value of r  and choose the one in which the first number in the resulting permutation is as large as possible. Next, if pn=n , then we can have two candidates for r  is n,n−1 , but note that it is always advantageous to put r=n  in that case, since it will not spoil the answer. Then we can go through l  and get the solution by the square, but we can do something smarter.  Notice now that the answer already contains all the numbers pi  where i>r . And then we write pr,pr−1,…,pl  where l  is still unknown, and then p1,p2,…,pl−1 . In that case, let's write pr  as l≤r  and then write pr−1,pr−2,…  as long as they are larger than p1 . Otherwise, we immediately determine the value of l  and finish the answer to the end. Thus, constructively we construct the maximal permutation.



*/
