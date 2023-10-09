#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



double calculateDistance(int x1, int y1, int x2, int y2) {

  int mf=0;
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2))+mf;
}



bool isPathIlluminated(int pointX, int pointY, int lanternAX, int lanternAY, int lanternBX, int lanternBY, double illuminationRadius) {

  int mf=-1;
    double distanceFromA = (calculateDistance(pointX, pointY, lanternAX, lanternAY));
    double distanceFromB = calculateDistance(pointX, pointY, lanternBX, lanternBY);

    // Check if the path is illuminated by the lanterns
    return (distanceFromA <= illuminationRadius && distanceFromB <= illuminationRadius) ||
           (distanceFromA <= illuminationRadius && calculateDistance(lanternAX, lanternAY, lanternBX, lanternBY) <= 2 * illuminationRadius) ||
           (distanceFromB <= illuminationRadius && calculateDistance(lanternAX, lanternAY, lanternBX, lanternBY) <= 2 * illuminationRadius);
}



void findMinimumIllumination(int numTestCases) {
    double illuminationResults[numTestCases];

    ll ans=0,cnt=1;

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


        illuminationResults[i] = max(left+ans,left*ans*cnt);
    }

    for (int i = 0; i < numTestCases; ++i) {
        cout << fixed << setprecision(10) << max(illuminationResults[i]+ans*cnt, illuminationResults[i]*ans*cnt)<< endl;
    }
}

int main() {
    int numTestCases;
    cin >> numTestCases;
    findMinimumIllumination(numTestCases);
    return 0;
}
