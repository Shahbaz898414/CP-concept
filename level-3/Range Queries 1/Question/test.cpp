#include<bits/stdc++.h>
using namespace std;

int q[21][1123456];

int main() {
    string s;
    cin >> s;
    int l = s.length();

    for(int i = 0; i < l; i++) {
        q[0][i + 1] = q[0][i] + (s[i] == '(' ? 1 : -1);
    }

    for(int j = 0; j < 20; j++) {
        for(int i = 0; i <= l; i++) {
            q[j + 1][i] = min(q[j][i], q[j][i + (1 << j)]);
        }
    }

    int m, L, R;


    scanf("%d", &m);


    for(int i = 0; i < m; i++) {
        scanf("%d%d", &L, &R);
        L--;

        int j = 0;
        while((1 << (j + 1)) <= R - L) {
            j++;
        }

        int qq = min(q[j][L], q[j][R - (1 << j) + 1]);
        printf("%d\n", R - L - (q[0][L] + q[0][R] - 2 * qq));
    }

    return 0;
}



/*


Today was my 21th day out of the 100 days  hard challenge.

So today, I solved 5 problems .

1. F - LCS  (https://atcoder.jp/contests/dp/tasks/dp_f)


2. G - Longest Path  (https://atcoder.jp/contests/dp/tasks/dp_g)


3. H - Grid 1 (https://atcoder.jp/contests/dp/tasks/dp_h)


4. M - Candies (https://atcoder.jp/contests/dp/tasks/dp_m)


5. J - Sushi (https://atcoder.jp/contests/dp/tasks/dp_j)


*/


