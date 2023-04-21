#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Solution {
public:
    bool isValid(string x) {
        stack<char> temp;
       for (int i = 0; i < x.size(); i++) {
          if(temp.empty()) {
            temp.push(x[i]);
          }else if((temp.top()=='(' and x[i]==')')
                  || (temp.top()=='[' and x[i]==']') ||
                  (temp.top()=='{' and x[i]=='}')) {
                    temp.pop();
          }else {
            temp.push(x[i]);
          }
       }


       if(temp.empty()) return true;
       return false;
    }
};

int main() {
    vector<int> nums({4, 5, 8, 2}), stream({3, 5, 10, 9, 4});
    KthLargest* obj = new KthLargest(3, nums);
    for(auto num: stream) cout<<obj->add(num)<<" ";
}