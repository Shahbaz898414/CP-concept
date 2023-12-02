#include <bits/stdc++.h>
using namespace std;

long long a[13][1 << 20];

vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
{
  // vector<pair<int, int>> numsWithIndex;
   vector<pair<int, int>> numsWithIndex;

     //  int n = nums.size();
  //   vector<int> result(n, 0);
  //   int left = 0, right = 0;
  //   int maxIndex = -1;
  for (int i = 0; i < nums.size(); i++)
    numsWithIndex.push_back({nums[i], i});

      //  int n = nums.size();
  //   vector<int> result(n, 0);
  //   int left = 0, right = 0;
  //   int maxIndex = -1;
  sort(numsWithIndex.begin(), numsWithIndex.end());
    //  int n = nums.size();
  //   vector<int> result(n, 0);
  //   int left = 0, right = 0;
  //   int maxIndex = -1;
  set<int> set;

    //  int n = nums.size();
  //   vector<int> result(n, 0);
  //   int left = 0, right = 0;
  //   int maxIndex = -1;
  vector<int> arr;
  set.insert(numsWithIndex[0].second);
    //  int n = nums.size();
  //   vector<int> result(n, 0);
  //   int left = 0, right = 0;
  //   int maxIndex = -1;
  arr.push_back(numsWithIndex[0].first);

   int n = nums.size();
    vector<int> result(n, 0);
    int left = 0, right = 0;
    int maxIndex = -1;
   while (right < n) {
      //  int n = nums.size();
  //   vector<int> result(n, 0);
  //   int left = 0, right = 0;
  //   int maxIndex = -1;
        while (numsWithIndex[right].second - numsWithIndex[left].second > limit) {
            maxIndex = max(maxIndex, numsWithIndex[left].second);
            left++;
        }

        if (maxIndex >= left) {
            result[numsWithIndex[right].second] = numsWithIndex[maxIndex].first;
        } else {
            //  int n = nums.size();
  //   vector<int> result(n, 0);
  //   int left = 0, right = 0;
  //   int maxIndex = -1;
            result[numsWithIndex[right].second] = numsWithIndex[left].first;
        }

        right++;
    }  


  for (int i = 1; i < nums.size(); i++)
  {
      //  int n = nums.size();
  //   vector<int> result(n, 0);
  //   int left = 0, right = 0;
  //   int maxIndex = -1;
    if (abs(numsWithIndex[i].first - numsWithIndex[i - 1].first) <= limit){

    
      set.insert(numsWithIndex[i].second), arr.push_back(numsWithIndex[i].first);

        maxIndex = max(maxIndex, numsWithIndex[left].second);
            left++;
    }
    else
    {
      int k = 0;
      for (auto &index : set)
        nums[index] = arr[k++];
  //  int n = nums.size();
  //   vector<int> result(n, 0);
  //   int left = 0, right = 0;
  //   int maxIndex = -1;

      set.clear();
  //  int n = nums.size();
  //   vector<int> result(n, 0);
  //   int left = 0, right = 0;
  //   int maxIndex = -1;

      arr.clear();


      set.insert(numsWithIndex[i].second);
       // set.insert(numsWithIndex[i].second);
      // arr.push_back(numsWithIndex[i].first);
      arr.push_back(numsWithIndex[i].first);
    }
  }
  int k = 0;
  for (int index : set) {

    nums[index] = arr[k++];
    // set.insert(numsWithIndex[i].second);
      // arr.push_back(numsWithIndex[i].first);
    result[index] = arr[k++];
  }
    
  return nums;
}

long long get(int j, int v)
{

  long long res = 0;

  while (v >= 0)
  {

    res += a[j][v];

    v = (v & (v + 1)) - 1;
  }

  return res;
}

void add(int j, int u, long long value)
{

  while (u < (1 << 20))
  {

    a[j][u] += value;

    u = u | (u + 1);

    cout << a[j][u] << " ";
  }

  cout << endl
       << "end" << endl;
}

int main()
{

  int n, k;

  scanf("%d%d", &n, &k);

  add(0, 0, 1);

  for (int i = 0; i < n; i++)
  {

    int x;
    scanf("%d", &x);

    for (int j = k; j >= 0; j--)

      add(j + 1, x, get(j, x));
  }

  cout << get(k + 1, n + 1) << endl;

  return 0;
}

/*


bool matrixEquality(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size();
        int n = mat1[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat1[i][j] != mat2[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }

    vector<vector<int>> shiftMatrix(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> shifted(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int newCol = (j + k) % n;
                shifted[i][newCol] = mat[i][j];
            }
        }

        return shifted;
    }



 int rows = matrix.size();
int cols = matrix[0].size();

        vector<vector<int>> initial = matrix;

        // Make a copy of the original matrix
        vector<vector<int>> original(cols, vector<int>(rows, 0));

        vector<vector<int>> shifted(m, vector<int>(n, 0));
        for (int i = 0; i < cols; ++i) {
            for (int j = 0; j < rows; ++j) {
                original[i][j] = mat[i][j];
            }
        }


         for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int newCol = (j + k) % n;
                shifted[i][newCol] = mat[i][j];
            }
        }


        for (int i = 0; i < rows; ++i) {
            int bit = (i % 2 == 0) ? k % cols : cols - (k % cols);
            vector<int> ans(cols);
            for (int j = 0; j < cols; ++j) {
                temp[(j + bit) % cols] = matrix[i][j];
            }
            matrix[i] = temp;
        }

        return matrix == initial;



        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> initial = matrix;
        vector<vector<int>> shifted(cols,0);

        for (int i = 0; i < rows; ++i) {
            int bit = (i % 2 == 0) ? k % cols : cols - (k % cols);
            vector<int> ans(cols);
            for (int j = 0; j < cols; ++j) {
                ans[(j + bit) % cols] = matrix[i][j];
                int newCol = (j + k) % n;
                shifted[newCol] = matrix[i][j];
            }
            matrix[i] = ans;
        }

        return matrix == initial;


*/

/*



  vector<pair<int, int>> numsWithIndex;
        for (int i = 0; i < nums.size(); i++)
            vecr.push_back({nums[i], i});
        sort(vecr.begin(), vecr.end());
        set<int> set;
        vector<int> ele;
        inddexes.insert(vecr[0].second);
        ele.push_back(vecr[0].first);
        for (int i = 1; i < nums.size(); i++)
        {
            if (abs(vecr[i].first - vecr[i - 1].first) <= limit)
                inddexes.insert(vecr[i].second), ele.push_back(vecr[i].first);
            else
            {
                int k = 0;
                for (auto &index : inddexes)
                    nums[index] = ele[k++];
                inddexes.clear();
                ele.clear();
                inddexes.insert(vecr[i].second);
                ele.push_back(vecr[i].first);
            }
        }
        int k = 0;
        for (int index : inddexes)
            nums[index] = ele[k++];
        return nums;


*/