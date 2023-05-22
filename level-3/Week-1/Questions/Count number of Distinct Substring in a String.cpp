// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the count of
// valid sub-strings
void printSubstrings(string s)
{

	// To store distinct output substrings
	unordered_set<string> us;

	// Traverse through the given string and
	// one by one generate substrings beginning
	// from s[i].
	for (int i = 0; i < s.size(); ++i) {

		// One by one generate substrings ending
		// with s[j]
		string ss = "";
		for (int j = i; j < s.size(); ++j) {

			ss = ss + s[j];
			us.insert(ss);
		}
	}

	// Print all substrings one by one
	for (auto s : us)
		cout << s << " ";
}

// Driver code
int main()
{
	string str = "aaabc";
	printSubstrings(str);
	return 0;
}
