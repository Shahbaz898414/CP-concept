#include <bits/stdc++.h>
using namespace std;


long long a[13][1 << 20];


long long get(int j, int v) {


  long long res = 0;


  while (v >= 0) {


    res += a[j][v];


    v = (v & (v + 1)) - 1;


  }


  return res;


}


void add(int j, int u, long long value) {


  while (u < (1 << 20)) {


    a[j][u] += value;


    u = u | (u + 1);

    cout<<a[j][u]<<" ";


  }

  cout<<endl<<"end"<<endl;

}


int main() {


  int n, k;


  scanf("%d%d", &n, &k);


  add(0, 0, 1);


  for (int i = 0; i < n; i++) {


    int x;scanf("%d", &x);


    for (int j = k; j >= 0; j--)


      add(j + 1, x, get(j, x));


  }


  cout << get(k + 1, n + 1) << endl;


  return 0;
}


