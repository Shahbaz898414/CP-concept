#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
    }
};

int main() {


}

/*


class Solution {    
public:
    void help(int i,string digits,string mapping[],string sol,vector<string>&ans){
        if(i==digits.length()){
            ans.push_back(sol);
            return;
        }

        int num=digits[i]-'0';
        string val=mapping[num];

        for(int j=0;j<val.length();j++){
            sol.push_back(val[j]);
            help(i+1,digits,mapping,sol,ans);
            sol.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string sol;
        if(digits.length()==0){
            return ans;
        }
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        help(0,digits,mapping,sol,ans);
        return ans;
    }
};



/////////////////////////////////////////////////////////////////////////////\\\\\\\


class Solution {
public:
    vector<string>ans;
    map<int,string>mp;
    void backtrack(string& dig,int start,string &temp){
        
        if(start==dig.size())ans.push_back(temp);

          for(auto x:mp[dig[start]-'0']){
              temp.push_back(x);
              backtrack(dig,start+1,temp);
              temp.pop_back();
          }
    }
    vector<string> letterCombinations(string dig) {
        if(dig=="") return ans;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        string temp;
        backtrack(dig,0,temp);
        return ans;
    }
};

*/