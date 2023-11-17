#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>

// #define int long long
#define all(x) x.begin(), x.end()
#define vi vector<long long int>

using namespace std;


long long countEqualCombinationPairs(vector<long long int>& a) {
    int n = a.size();
    unordered_map<int, int> freq;

    long long result = 0;

    // Count the frequency of each element in the array
    for (int i = 0; i < n; ++i) {
        freq[a[i]]++;
    }

    // For each unique combination, add the number of pairs to the result
    for (auto& kv : freq) {
        int count = kv.second;
        result += 1LL * count * (count - 1) / 2;
    }

    return result;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    cin >> testCases;

    while (testCases--) {

			long long int size;
    cin >> size;
    vi numbers(size);

    for (long long int i = 0; i < size; i++)
        cin >> numbers[i];


	long long int ans2=	countEqualCombinationPairs(numbers);
	long long int ans3=	-1;




   
	 
	  map<long long int, long long int> frequency;

		
		 unordered_map<long long int, long long int> freq;

    long long ans = 0;

		

    for (long long int i = 0; i < size; i++){
        frequency[numbers[i]]++;
        freq[numbers[i]]++;}



    long long int result = 0;
    long long int mx = 0;


    for (auto element : frequency) 
		   result += element.second * (element.second - 1) / 2;

		for (auto& kv : freq) {
        int count = kv.second;
        ans += 1LL * count * (count - 1) / 2;
    }





    result += frequency[1] * frequency[2];

		mx=max({result,ans,ans2});

		mx=mx-ans2;

		ans2=ans2-mx;

		









		if(result== ans)  cout<<ans<<endl;
		else{
			 cout << max(result,ans2-mx) << endl;
		}
   



    }

    return 0;
}



/*

Today was my 44th day out of the 100 days  hard challenge.
So today, I solved 5 problems .


1. D. Yarik and Musical Notes (https://codeforces.com/contest/1899/problem/D).


2. C. Yarik and Array (https://codeforces.com/contest/1899/problem/C).


3. B. 250 Thousand Tons of TNT (https://codeforces.com/contest/1899/problem/B)


4. A. Game with Integers (https://codeforces.com/contest/1899/problem/A).


5. A. Addition to Segment (https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/A).


My Segment Tree Template :-
struct segtree {
    int size;
    vector<ll> tree;
 
    void build(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2*size, 0);
    }
 
    void add(int l, int r, int v) {
        add(l, r, v, 0, 0, size);
    }
 
    void add(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r) return;
        if (rx <= l) return;
        if (lx >= l && rx <= r) {
            tree[x] += v;
            return;
        }
 
        int m = (lx + rx) / 2;
        add(l, r, v, 2*x+1, lx, m);
        add(l, r, v, 2*x+2, m, rx);
    }
 
    ll get(int idx) {
        return get(idx, 0, 0, size);
    }
 
    ll get(int idx, int x, int lx, int rx) {
        if (rx == lx + 1) {
            return tree[x];
        }
 
        int m = (lx + rx) / 2;
        if (idx < m)
            return get(idx, 2*x+1, lx, m) + tree[x];
        else
            return get(idx, 2*x+2, m, rx) + tree[x];
    }
};


#100dayschallenge #challenge #consistency #SegmentTree #lessons
#learning



*/



/*



*/