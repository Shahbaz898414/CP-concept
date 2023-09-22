#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool canMakePalindrome(string s) {
    int n = s.length();
    
    // Try removing each possible substring.
    for (int i = 0; i < n; i++) {
        string left = s.substr(0, i);
        string right = s.substr(i);
        string newString = left + right.substr(1); // Remove the current substring.
        
        if (isPalindrome(newString)) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int n;cin>>n;
    string s;
    cin >> s;

    if (canMakePalindrome(s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

