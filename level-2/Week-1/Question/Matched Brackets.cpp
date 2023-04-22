#include<bits/stdc++.h>
#define ll long long
using namespace std;



int main() {
  
  int n;
    cin >> n;

    vector<int> stck;
    vector<pair<int, int>> closed;

    int nesting = 0;
    int nesting_pos = -1;

    int longest = 0;
    int longest_pos = -1;

    for (int i = 1; i <= n; i++) {
        int inp;
        cin >> inp;

        if (inp == 1) {
            stck.push_back(i);
            if (stck.size() > nesting) {
                nesting = stck.size();
                nesting_pos = i;
            }
        } else {
            int el = stck.back();
            stck.pop_back();
            closed.push_back({el, i});
        }
    }

    for (auto el: closed) {
        if (el.second - el.first + 1 > longest) {
            longest = el.second - el.first + 1;
            longest_pos = el.first;
        }
    }

    cout << nesting << " " << nesting_pos << " " << longest << " " << longest_pos << endl;




  




  return 0;
}