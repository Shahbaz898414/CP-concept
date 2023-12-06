#include <iostream>
using namespace std;

void findNumbers(int N) {
    if (N % 3 != 0) {
        cout << "-1\n"; // If N is not divisible by 3, no solution exists.
        return;
    }

    int A = N / 3;
    int B = N / 3;
    int C = 1;

    cout << A << " " << B << " " << C << "\n";
}

int main() {
    int T, N;
    cin >> T;

    while (T--) {
        cin >> N;
        findNumbers(N);
    }

    return 0;
}
