#include<bits/stdc++.h>
using namespace std;
#define ll long long



double calculateDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

bool isPathIlluminated(int pointX, int pointY, int lanternAX, int lanternAY, int lanternBX, int lanternBY, double illuminationRadius) {
    double distanceFromA = calculateDistance(pointX, pointY, lanternAX, lanternAY);
    double distanceFromB = calculateDistance(pointX, pointY, lanternBX, lanternBY);

    // Check if the path is illuminated by the lanterns
    return (distanceFromA <= illuminationRadius && distanceFromB <= illuminationRadius) ||
           (distanceFromA <= illuminationRadius && calculateDistance(lanternAX, lanternAY, lanternBX, lanternBY) <= 2 * illuminationRadius) ||
           (distanceFromB <= illuminationRadius && calculateDistance(lanternAX, lanternAY, lanternBX, lanternBY) <= 2 * illuminationRadius);
}

void findMinimumIllumination(int numTestCases) {
    double illuminationResults[numTestCases];

    for (int i = 0; i < numTestCases; ++i) {
        int pointX, pointY, lanternAX, lanternAY, lanternBX, lanternBY;
        std::cin >> pointX >> pointY >> lanternAX >> lanternAY >> lanternBX >> lanternBY;

        double left = 0;
        double right = std::max(calculateDistance(lanternAX, lanternAY, pointX, pointY), calculateDistance(lanternBX, lanternBY, pointX, pointY));

        // Binary search to find the minimum illuminationRadius
        for (int j = 0; j < 100; ++j) {
            double mid = (left + right) / 2;

            if (isPathIlluminated(pointX, pointY, lanternAX, lanternAY, lanternBX, lanternBY, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        illuminationResults[i] = left;
    }

    for (int i = 0; i < numTestCases; ++i) {
        cout << fixed << setprecision(10) << illuminationResults[i] << endl;
    }
}

int main() {
    int numTestCases;
    std::cin >> numTestCases; // Number of test cases
    findMinimumIllumination(numTestCases);
    return 0;
}
