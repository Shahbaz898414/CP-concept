#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long

long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

bool findABC(ll N)
{
    // If N is divisible by 3, A and B can be N/3 and C can be set to 1, satisfying the equation.
    int a, b, c;
    if (N % 3 == 0)
    {

        //   if(N%2==0){
        //     cout << N / 3 << " " << N / 3 << " " << 2 << "\n";
        //   }else
        //     cout << N / 3 << " " << N / 3 << " " << 1 << "\n";

        return 1;
    }
    else
    {
        // If N is not divisible by 3, there is no possible solution as per the trick used.
        return 1;
    }
}

int main()
{
    int testCases;
    cin >> testCases;

    for (int t = 0; t < testCases; ++t)
    {
        ll arraySize;
        cin >> arraySize;

        ll a, b, c;

        a = arraySize / 3;
        b = arraySize / 3;
        c = 1;

        bool fl = false;

        if (arraySize % 3 == 0)
        {

            // if (arraySize % 2 == 0)
            // {
            // cout << arraySize / 3 << " " << arraySize / 3 << " " << 2 << "\n";
            fl = true;
            // }
            // else

            // cout << arraySize / 3 << " " << arraySize / 3 << " " << 1 << "\n";
        }
        else
        {
            // If N is not divisible by 3, there is no possible solution as per the trick used.
            //    return 0;
            fl = false;
        }

        ll cnt = 0, g = 0;

        // ll lc=lcm(a,b);

        ll i = 1;



        vector<ll> arr, brr;

        ll sum = 0;
        while (i < arraySize - 1 and findABC(i))
        {

            ll k;
            ll j = i;

            // findABC(j);

            if (arraySize % 3 == 0)
            {
                brr.push_back(arraySize / 3);
                brr.push_back(arraySize / 3);
                brr.push_back(1);
            }

            while (j < arraySize - 1  and k >= 0)
            {
                if (!(((arraySize - i+ sum*g)) % (2 * j) ))
                {

                    arr.push_back(1);

                    arr.push_back(i);

                    arr.push_back((j * (arraySize - i)) / (2 * j));

                    cnt = 1;

                    break;
                }

                if(cnt==1) break;
                j = 2 * j;

                brr.pop_back();

                k = abs(j - i);
            }
            i = i * 2;

            sum += abs(2 * j - i + k)*g;

            if(cnt==1) break;
        }

        if (cnt == 0)
            cout << -1 << endl;
        else
        {
            for (auto it : arr)
            {
                cout << it + sum * g << " ";

                sum = sum / 2;
            }

            cout << endl;
        }
    }

    return 0;
}



/*


10 kg aata
5 packet tel
1kg tuwal dal
2kg chana dal
1/2kg laal masur ki dal
1/2 kg chana and vatana
1/4 jira
1 packet namak
chura and biscut

wheem bar soup

sarafXL 

khajur




*/


/*


Today was my 63th day out of the 100 days  hard challenge.
So today, I solved 5 problems .


1. 404 Not Found (https://www.codechef.com/problems/ERROR404).


2. Exams  (https://www.codechef.com/problems/EXAMCHEF).


3. Reach Codetown (https://www.codechef.com/problems/CODETOWN)


4. Beautiful Strings (https://www.codechef.com/problems/BEAUTYSTR).


5. Prefixing  (https://www.codechef.com/problems/FIX).


6. LCM Mania  (https://www.codechef.com/problems/LCMMANIA).





#100dayschallenge #challenge #consistency #Cp #lessons #learning
#competitiveprogramming


*/