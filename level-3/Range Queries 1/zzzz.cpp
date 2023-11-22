#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        long long arraySize;
        cin >> arraySize;
        vector<long long> elements(arraySize);

        vector<long long> evenNumbers, oddNumbers;

        for (int i = 0; i < arraySize; i++) {
            cin >> elements[i];
            if (elements[i] % 2 == 0) {
                evenNumbers.push_back(elements[i]);
            } else {
                oddNumbers.push_back(elements[i]);
            }
        }

        if (evenNumbers.size() % 2 != 0) {
            cout << -1 << endl;
            return 0;
        }

        sort(oddNumbers.begin(), oddNumbers.end());
        sort(evenNumbers.begin(), evenNumbers.end());

        vector<long long> leftPart, rightPart;

        long long i = 0, j = evenNumbers.size() - 1;
        while (i < j) {
            long long leftValue = (evenNumbers[i] + evenNumbers[j]) / 2;
            long long rightValue = (evenNumbers[j] - evenNumbers[i]) / 2;
            leftPart.push_back(leftValue);
            rightPart.push_back(rightValue);
            i++, j--;
        }

        i = 0, j = oddNumbers.size() - 1;
        while (i < j) {
            long long leftValue = (oddNumbers[i] + oddNumbers[j]) / 2;
            long long rightValue = (oddNumbers[j] - oddNumbers[i]) / 2;
            leftPart.push_back(leftValue);
            rightPart.push_back(rightValue);
            i++, j--;
        }

        sort(leftPart.begin(), leftPart.end());
        sort(rightPart.begin(), rightPart.end());

        for (int i = 0; i < leftPart.size(); i++) {
            cout << leftPart[i] << " ";
        }

        for (int i = 0; i < rightPart.size(); i++) {
            cout << rightPart[i] << " ";
        }

        cout << endl;
    }

    return 0;
}
