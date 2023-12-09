#include <bits/stdc++.h>
using namespace std;

#define N 100005
int n, cnt, u[N], v[N], c[N], a[N];

int main()
{

  int i;
  scanf("%d", &n);
  for (i = 0; i < n - 1; i++)
    scanf("%d%d", &u[i], &v[i]);
  for (i = 1; i <= n; i++)
    scanf("%d", &c[i]);
  for (i = 0; i < n - 1; i++)
  {
    if (c[u[i]] != c[v[i]])
    {
      cnt++, a[u[i]]++, a[v[i]]++;
    }
  }
  for (i = 1; i <= n; i++)
  {
    if (a[i] == cnt)
    {
      printf("YES\n%d", i);
      return 0;
    }
  }
  puts("NO");

  return 0;
}

