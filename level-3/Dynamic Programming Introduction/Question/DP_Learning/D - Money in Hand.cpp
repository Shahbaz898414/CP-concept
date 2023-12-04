#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = (10e8) + 7;

// ll   f[2][100001],a[2][100001];




int main() {


  ios_base::sync_with_stdio(0);
  cin.tie(0);



   int N, X; cin >> N >> X;


    vector<int> A(N), B(N);


    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }


    vector<bool> dp(X + 1);


    dp[0] = true;


    for (int i = 0; i < N; i++) {


        for (int j = X - 1; j >= 0; j--) {


            if (dp[j]) {


              cout<<j<<" "<<A[i]<<endl;


                for (int k = 1; k <= B[i]; k++) {


                    if (j + A[i] * k > X) break;


                    dp[j + A[i] * k] = true;

                    cout<<j + A[i] * k<<" ";


                }


            }


        }



        cout<<endl;


    }



    if (dp[X]) cout << "Yes" << endl;


    else cout << "No" << endl;



}





/*


Score : 400 points

Problem Statement Takahashi has  N kinds of coins; specifically, for  1≤i≤N, he has  B  i ​   coins worth  A  i ​   yen (the currency in Japan) each.  Determine if Takahashi can pay exactly  X yen (without change) with the coins he currently has.  

Constraints
 1≤N≤50
  1≤X≤10^4
  1≤ Ai ≤100
  1≤ Bi ​≤50 
  Ai ​are pairwise distinct.
  All values in the input are integers.
  Input The input is given from Standard Input in the following format:  N  X A  1 ​    B  1 ​   A  2 ​    B  2 ​   ⋮ A  N ​    B  N

Output
Print Yes if Takahashi can pay exactly  X yen with the coins he currently has; print No otherwise.  Sample Input 1 Copy 2 19 2 3 5 6 Sample Output 1 Copy Yes Takahashi has three  2-yen coins and six  5-yen coins. He can use two  2-yen coins and three  5-yen coins to pay exactly  2×2+5×3=19 yen. Thus, Yes should be printed.  Sample Input 2 Copy 2 18 2 3 5 6 Sample Output 2 Copy No There is no combination of the coins that he can use to pay exactly  18 yen. Thus, No should be printed.  Sample Input 3 Copy 3 1001 1 1 2 1 100 10 Sample Output 3 Copy Yes He need not use all kinds of coins.


*/