#include <iostream>
#include <vector>
using namespace std;

int findOptimalLevel(vector<int>& energyArr, int K) {
    int n = energyArr.size();
    int totalEnergy = K;
    int requiredEnergy = 0;
    int optimalLevel = -1;

    for (int i = 0; i < n; ++i) {
        totalEnergy += energyArr[i];
        if (totalEnergy < 0) {
            requiredEnergy -= totalEnergy;
            totalEnergy = 0;
            optimalLevel = i;
        }
    }

    if (requiredEnergy > K) {
        return -1; 
    }

    return optimalLevel + 1;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> energyArr(N);
    for (int i = 0; i < N; ++i) {
        cin >> energyArr[i];
    }

    int result = findOptimalLevel(energyArr, K);
    cout << result << endl;

    return 0;
}
