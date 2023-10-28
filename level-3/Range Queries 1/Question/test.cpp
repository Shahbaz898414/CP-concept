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





