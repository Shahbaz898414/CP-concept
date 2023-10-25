#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long testCases;
    cin >> testCases;

    while (testCases--) {
        long long n, p, q;
        cin >> n >> p >> q;
        vector<long long> numbers(n);

        for (long long i = 0; i < n; i++) {
            cin >> numbers[i];
        }

        sort(numbers.begin(), numbers.end());

        while (numbers.size() > 2 && p > 0 && numbers[numbers.size() - 2] > 0) {
            long long x = numbers.back();
            numbers.pop_back();
            long long y = numbers.back();
            numbers.pop_back();
            numbers.push_back(x + y);
            p--;
        }

        reverse(numbers.begin(), numbers.end());

        while (numbers.size() > 2 && p > 0 && numbers[numbers.size() - 2] < 0) {
            long long x = numbers.back();
            numbers.pop_back();
            long long y = numbers.back();
            numbers.pop_back();
            numbers.push_back(x + y);
            p--;
        }

        reverse(numbers.begin(), numbers.end());

        while (numbers.size() > 2 && q > 0 && numbers[numbers.size() - 2] > 0) {
            numbers[0] -= numbers[numbers.size() - 2];
            numbers.erase(numbers.end() - 2);
            q--;
        }

        reverse(numbers.begin(), numbers.end());

        while (numbers.size() > 2 && q > 0 && numbers[numbers.size() - 2] < 0) {
            numbers[0] -= numbers[numbers.size() - 2];
            numbers.erase(numbers.end() - 2);
            q--;
        }

        cout << numbers[0] - numbers[numbers.size() - 1] << endl;
    }

    return 0;
}
