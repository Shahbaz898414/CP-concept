// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int M = 1e9 + 7;

// int main() {

//   ios_base::sync_with_stdio(false); cin.tie(nullptr);
//   string s;cin>>s;

//   ll len=s.size();

//   return 0;
// }

/*

#include <bits/stdc++.h>
using namespace std;
char s[100001];
int n,k=0,cnt=0,m=0,t,cn=0;
int main(){
//	scanf("%d",&n);
  scanf("%s",s);
  n=strlen(s);
  for(int i=0;i<n;i++){
    if (s[i]=='(') k++;
    if (s[i]==')') k--;
    if (s[i]=='#') cnt++,k--,t=i;
    if (k<0){puts("-1");return 0;}
  }
  for (int i=t+1;i<=n;i++){
    if (s[i]=='(') cn++;
    if (s[i]==')') cn--;
    cn=max(cn,0);
  }if (cn>0){puts("-1");return 0;}
  for (int i=1;i<cnt;i++) puts("1");printf("%d",k+1);
  return 0;
}

*/

#include <bits/stdc++.h>
using namespace std;
string s;
int a, b, c, d;
int main()
{
  cin >> s;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '(')
      a++;
    if (s[i] == ')')
      a--;
    if (s[i] == '#')
    {
      a--;
      b++;
    }
    if (a < 0)
    {
      cout << -1;
      return 0;
    }
  }

  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == '#')
    {
      c++;
      if (b == c)
        d -= a;
      d--;
    }
    if (s[i] == '(')
      d++;
    if (s[i] == ')')
      d--;
    if (d < 0)
    {
      cout << -1;
      return 0;
    }
  }

  for (int i = 1; i < b; i++)
    cout << 1 << endl;
  cout << a + 1;

  return 0;
}
