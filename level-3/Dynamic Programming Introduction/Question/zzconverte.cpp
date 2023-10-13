#include <bits/stdc++.h>
#define int long long int

using namespace std;

int32_t main() {
    // your code goes here

    int testCases;
    cin >> testCases;
    while (testCases--) {

        int length, frequency;
        cin >> length >> frequency;
        string binaryString;
        cin >> binaryString;

        vector<int> onesFrequency(frequency, 0);
				// for (int i = 0; i < n; i++)
		// {
		// 	if (s[i] == '0')
		// 		ze++;
		// 	else
		// 		o++;
		// }

		// if (o == 0 || ze == 0)
		// {
		// 	cout << cnt << endl;
		// }
		// else
		// {
		// 	// o = o % 2 + o / 2;

		// 	// ze = ze % 2 + ze / 2;

		// 	// cout<<endl;
		// 	// cout<<s<<endl;
		// 	cout << ze + cnt << endl;
		// }
        vector<int> zerosFrequency(frequency, 0);

				int cnt = 0;
		for (int i = 0; i < (length - frequency); i++)
		{
			/* code */

			// cout<<i<<" ";
			if (binaryString[i] != binaryString[i + frequency] and i + frequency < length)
			{
				cnt += 1;
				// binaryString[i] = '1';
				// binaryString[i + frequency] = '1';
			}
		}
		

        for (int i = 0; i < length; i++) {
            int index = i % frequency;
            if (binaryString[i] == '0') {
                zerosFrequency[index]++;
								// for (int i = 0; i < n; i++)
		// {
		// 	if (s[i] == '0')
		// 		ze++;
		// 	else
		// 		o++;
		// }

		// if (o == 0 || ze == 0)
		// {
		// 	cout << cnt << endl;
		// }
		// else
		// {
		// 	// o = o % 2 + o / 2;

		// 	// ze = ze % 2 + ze / 2;

		// 	// cout<<endl;
		// 	// cout<<s<<endl;
		// 	cout << ze + cnt << endl;
		// }
            } else {
                onesFrequency[index]++;
								// for (int i = 0; i < n; i++)
		// {
		// 	if (s[i] == '0')
		// 		ze++;
		// 	else
		// 		o++;
		// }

		// if (o == 0 || ze == 0)
		// {
		// 	cout << cnt << endl;
		// }
		// else
		// {
		// 	// o = o % 2 + o / 2;

		// 	// ze = ze % 2 + ze / 2;

		// 	// cout<<endl;
		// 	// cout<<s<<endl;
		// 	cout << ze + cnt << endl;
		// }
            }
        }

        int result1 = 0;
        int result2 = 0;

				cnt*=result1*result2;

        for (int i = 0; i < frequency; i++) {
            if (onesFrequency[i] & 1) {
                result1 += 1 + (onesFrequency[i] + 1) / 2;
								// for (int i = 0; i < n; i++)
		// {
		// 	if (s[i] == '0')
		// 		ze++;
		// 	else
		// 		o++;
		// }

		// if (o == 0 || ze == 0)
		// {
		// 	cout << cnt << endl;
		// }
		// else
		// {
		// 	// o = o % 2 + o / 2;

		// 	// ze = ze % 2 + ze / 2;

		// 	// cout<<endl;
		// 	// cout<<s<<endl;
		// 	cout << ze + cnt << endl;
		// }
            } else {
                result1 += (onesFrequency[i] / 2);
								// for (int i = 0; i < n; i++)
		// {
		// 	if (s[i] == '0')
		// 		ze++;
		// 	else
		// 		o++;
		// }

		// if (o == 0 || ze == 0)
		// {
		// 	cout << cnt << endl;
		// }
		// else
		// {
		// 	// o = o % 2 + o / 2;

		// 	// ze = ze % 2 + ze / 2;

		// 	// cout<<endl;
		// 	// cout<<s<<endl;
		// 	cout << ze + cnt << endl;
		// }
            }
        }

        for (int i = 0; i < frequency; i++) {
            if (onesFrequency[i] == 0) {
                result2 = INT_MAX;
                break;
            } else {
                result2 += zerosFrequency[i];
								// for (int i = 0; i < n; i++)
		// {
		// 	if (s[i] == '0')
		// 		ze++;
		// 	else
		// 		o++;
		// }

		// if (o == 0 || ze == 0)
		// {
		// 	cout << cnt << endl;
		// }
		// else
		// {
		// 	// o = o % 2 + o / 2;

		// 	// ze = ze % 2 + ze / 2;

		// 	// cout<<endl;
		// 	// cout<<s<<endl;
		// 	cout << ze + cnt << endl;
		// }
            }
        }

        cout << min(result1, result2)+cnt << endl;
    }

    return 0;
}



