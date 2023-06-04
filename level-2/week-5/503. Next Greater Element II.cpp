#include <bits/stdc++.h>

#define ll long long
using namespace std;

class Solution
{
public:
  vector<int> nextGreaterElements(vector<int> &nums)
  {

  }
};

int main()
{
  int n;
  cin >> n;

  vector<int> v(n);

  for (int i = 0; i < n; i++)
  {

    cin >> arr[i];
  }

  vector<int> num = nextGreaterElements(v);

  for (auto it : num)
  {
    cout << it << " ";
  }

  cout << endl;
}

/*


/////////////////////////////////////////////////////
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n = a.size();
        vector<int>v(n,-1);
        stack<int>st;
        for(int i = 2*n - 1; i >= 0; i--)
        {
            // we pop out all elements smaller than current element
            while(!st.empty() && (a[i%n] >= st.top()))
            {
                st.pop();
            }

            // if stack is empty means no greater element is there
            // if not empty we make answer at that index equal to top element
            if(!st.empty() && (i < n))
            {
                v[i] = st.top();
            }

            st.push(a[i%n]);
        }

        return v;
    }
};

/////////////////////////////////////////////////////////

class Solution {
public:
vector<int>ans;
    vector<int> nextGreaterElements(vector<int>& nums) {
      for(int i=0;i<nums.size();i++){
          int num=nums[i];
          int count=0;
          int j=i;
          while(count<nums.size()){
              cout<<nums[j]<<"  "<<num<<endl;
              if(nums[j]>num) {
            ans.push_back(nums[j]);
            break ;
              }
              if(j == nums.size()-1) j=-1;
                j++;
              count++;
          }
          if(count == nums.size()) ans.push_back(-1);
      }
      return ans;
    }
};


///////////////////////////////////////////////////////////////


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

    vector<int> vec;

    for(int i=0;i<nums.size();i++){

      bool flag=false;
      int k=i+1;
       int idx=INT_MIN;

        while(idx!=i){

            idx=k%nums.size();
            if(nums[idx]>nums[i]){
                flag=true;
                vec.push_back(nums[idx]);
                break;
            }
            k++;

        }
         if(!flag) vec.push_back(-1);
    }
        return vec;

    }
};

*/
