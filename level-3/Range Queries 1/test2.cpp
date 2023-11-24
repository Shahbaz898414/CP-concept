#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

int main()
{
    int t;
    cin >> t;

    while (t--)
    {

        ll arraySize, g = 0;
        cin >> arraySize;
        ll odd=0,even=0;
        vector<ll> elements(arraySize);

        vector<ll> evenNumbers, oddNumbers, main;

        for (int i = 0; i < arraySize; i++)
        {
            cin >> elements[i];
            
            // ll rightValue = (evenNumbers[j] - evenNumbers[i]) / 2;
            // main.push_back(rightValue + leftValue);
            // leftPart.push_back(leftValue);
            // rightPart.push_back(rightValue);
            if (elements[i] % 2 == 0)
            {
                evenNumbers.push_back(elements[i]);
            }
            else
            {
                oddNumbers.push_back(elements[i]);
            }

            main.push_back(elements[i]);
        }

        if (evenNumbers.size() % 2 != 0)
        {
            cout << -1 << endl;
            continue;
        }

        vector<ll> leftPart, rightPart;

        sort(oddNumbers.begin(), oddNumbers.end());
        sort(main.begin(), main.end());
        
            // ll rightValue = (evenNumbers[j] - evenNumbers[i]) / 2;
            // main.push_back(rightValue + leftValue);
            // leftPart.push_back(leftValue);
            // rightPart.push_back(rightValue);
        sort(evenNumbers.begin(), evenNumbers.end());

        ll i = 0, j = evenNumbers.size() - 1;
        while (i < j)
        {
            ll leftValue = (evenNumbers[i] + evenNumbers[j]) / 2;

            ll rightValue = (evenNumbers[j] - evenNumbers[i]) / 2;
            main.push_back(rightValue + leftValue);
            
            // ll rightValue = (evenNumbers[j] - evenNumbers[i]) / 2;
            // main.push_back(rightValue + leftValue);
            // leftPart.push_back(leftValue);
            // rightPart.push_back(rightValue);
            leftPart.push_back(leftValue);
            rightPart.push_back(rightValue);
            i++, j--;
        }

        sort(main.begin(), main.end());

        i = 0, j = oddNumbers.size() - 1;
        while (i < j)
        {
            ll leftValue = (oddNumbers[i] + oddNumbers[j]) / 2;
            ll rightValue = (oddNumbers[j] - oddNumbers[i]) / 2;
            main.push_back(leftValue + leftValue);
            leftPart.push_back(leftValue);

            main.push_back((leftValue + leftValue) / 2);
            rightPart.push_back(rightValue);
            i++, j--;
        }

        // sort(leftPart.begin(), leftPart.end());
        sort(main.begin(), main.end());
        
            // ll rightValue = (evenNumbers[j] - evenNumbers[i]) / 2;
            // main.push_back(rightValue + leftValue);
            // leftPart.push_back(leftValue);
            // rightPart.push_back(rightValue);
        // sort(rightPart.begin(), rightPart.end());

        for (int i = 0; i < leftPart.size(); i++)
        {
            
            // ll rightValue = (evenNumbers[j] - evenNumbers[i]) / 2;
            // main.push_back(rightValue + leftValue);
            // leftPart.push_back(leftValue);
            // rightPart.push_back(rightValue);
            cout << leftPart[i] + (main[i] * g)  << " ";
        }

        for (int i = 0; i < rightPart.size(); i++)
        {
            
            // ll rightValue = (evenNumbers[j] - evenNumbers[i]) / 2;
            // main.push_back(rightValue + leftValue);
            // leftPart.push_back(leftValue);
            // rightPart.push_back(rightValue);
            cout << rightPart[i] + (main[i] * g)  << " ";
        }

        cout << endl;
    }

    return 0;
}

/*




Consider an array A of size N: A1 ,A2 ,…,AN ​  , where N is even. The AlterEgo of this array A, is another array B, which is computed as follows:
1. Start with an empty array B. For i ranging from  1 1 to 2 2 N ​  , insert the elements     2 ) (A  i ​  +A  i+  2 N ​   ​  ) and     2 ∣ ∣A  i ​  −A  i+  2 N ​   ​  ∣ to the end of array B. Here   ∣ ∣x∣ refers to absolute value of x. Rearrange the array B in some random order. As you can see, because of the third point, an array A can have multiple AlterEgo arrays.  Given an array B of even length N, your job is to find if there exists an array A such that B is the AlterEgo of A. And if it does exist, find such an array A with the maximum possible sum of elements.  That is, if there is no array A such that B is an AlterEgo of A, print  − 1 −1. Else print an array A such that B is an AlterEgo of A, and the sum of the elements of this array A is as large as possible. If there are multiple arrays possible with the maximum sum, print any.  Input Format The first line of input will contain a single integer T, denoting the number of test cases. Each test case consists of two lines of input. The first line of each test case contains a single integer N — the number of elements in the array. The second line of each test case contains N space-separated integers 1  2 , …  B  1 ​  ,B  2 ​  ,…,B  N ​   — the elements of the array. Output Format For each test case, output on a new line, either  − 1 −1, or N space separated integers denoting array A. If there are multiple arrays possible with the maximum sum, print any.  Constraints 1  ≤ 1 0 5 1≤T≤10  5   1  ≤ 3 ⋅ 1 0 5 1≤N≤3⋅10  5  N is even. 1  ≤ 1 0 5 1≤B  i ​  ≤10  5   The sum of N over all test cases won't exceed  3 ⋅ 1 0 5 3⋅10  5  .







Today was my 49th day out of the 100 days  hard challenge.
So today, I solved 5 problems .


1. Alter Ego (https://www.codechef.com/problems/ALT).


2. Minimum XOR (https://www.codechef.com/problems/MINMXOR).


3. Best of N Sets (https://www.codechef.com/problems/BESTOFTENNIS)


4. B. Applying MAX to Segment (https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/B).


5. C. Assignment to Segment (https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/C).


#100dayschallenge #challenge #consistency #Cp #lessons  #learning




*/