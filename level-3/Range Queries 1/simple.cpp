// C++ program to show segment tree operations
// like construction, query and update
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

#define ll long long int

// A utility function to get the middle
// index from corner indexes.
int getMid(int s, int e)
{
	return s + (e - s) / 2;
}

/* A recursive function to get the Xor of
values in given range of the array. The
following are parameters for this function.
	st --> Pointer to segment tree
	si --> Index of current node in the segment tree.
		Initially 0 is passed as root is always
		at index 0.
	ss & se --> Starting and ending indexes of
				the segment represented by current
				node, i.e., st[si]
	qs & qe --> Starting and ending indexes of
				query range */
int getXorUtil(int *st, int ss, int se, int qs,
							 int qe, int si)
{
	// If segment of this node is a part of given
	// range, then return the Xor of the segment
	if (qs <= ss && qe >= se)
		return st[si];

	// If segment of this node is outside
	// the given range
	if (se < qs || ss > qe)
		return 0;

	// If a part of this segment overlaps
	// with the given range
	int mid = getMid(ss, se);
	return getXorUtil(st, ss, mid, qs, qe, 2 * si + 1) ^
				 getXorUtil(st, mid + 1, se, qs, qe, 2 * si + 2);
}

/* A recursive function to update the nodes
which have the given index in their range.
The following are parameters
	st, si, ss and se are same as getXorUtil()
	i --> index of the element to be updated.
		This index is in input array.*/
void updateValueUtil(int *st, int ss, int se, int i,
										 int prev_val, int new_val, int si)
{
	// Base Case: If the input index lies outside
	// the range of this segment
	if (i < ss || i > se)
		return;

	// If the input index is in range of this node,
	// then update the value of the node and its children
	st[si] = (st[si] ^ prev_val) ^ new_val;
	if (se != ss)
	{
		int mid = getMid(ss, se);
		updateValueUtil(st, ss, mid, i, prev_val,
										new_val, 2 * si + 1);
		updateValueUtil(st, mid + 1, se, i, prev_val,
										new_val, 2 * si + 2);
	}
}

// The function to update a value in input
// array and segment tree. It uses updateValueUtil()
// to update the value in segment tree
void updateValue(int arr[], int *st, int n,
								 int i, int new_val)
{
	// Check for erroneous input index
	if (i < 0 || i > n - 1)
	{
		printf("Invalid Input");
		return;
	}
	int temp = arr[i];
	// Update the value in array
	arr[i] = new_val;

	// Update the values of nodes in segment tree
	updateValueUtil(st, 0, n - 1, i, temp, new_val, 0);
}

// Return Xor of elements in range from index qs (query start)
// to qe (query end). It mainly uses getXorUtil()
int getXor(int *st, int n, int qs, int qe)
{
	// Check for erroneous input values
	if (qs < 0 || qe > n - 1 || qs > qe)
	{
		printf("Invalid Input");
		return 0;
	}

	return getXorUtil(st, 0, n - 1, qs, qe, 0);
}

// A recursive function that constructs
// Segment Tree for array[ss..se]. si is
// index of current node in segment tree st
int constructSTUtil(int arr[], int ss, int se,
										int *st, int si)
{
	// If there is one element in array,
	// store it in current node of segment
	// tree and return
	if (ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}

	// If there are more than one elements,
	// then recur for left and right subtrees
	// and store the Xor of values in this node
	int mid = getMid(ss, se);
	st[si] = constructSTUtil(arr, ss, mid, st, si * 2 + 1) ^
					 constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);
	return st[si];
}

/* Function to construct segment tree from given array.
This function allocates memory for segment tree and
calls constructSTUtil() to fill the allocated memory */
int *constructST(int arr[], int n)
{
	// Allocate memory for segment tree

	// Height of segment tree
	int x = (int)(ceil(log2(n)));

	// Maximum size of segment tree
	int max_size = 2 * (int)pow(2, x) - 1;

	// Allocate memory
	int *st = new int[max_size];

	// Fill the allocated memory st
	constructSTUtil(arr, 0, n - 1, st, 0);

	// Return the constructed segment tree
	return st;
}

// Driver program to test above functions
int main()
{

	set<long long> magicalNumbers = {
			2, 3, 5, 7, 11, 101, 131, 151, 181, 191, 313, 353, 373, 383, 727, 757, 787, 797, 919, 929,
			10301, 10501, 10601, 11311, 11411, 12421, 12721, 12821, 13331, 13831, 13931, 14341, 14741, 15451,
			15551, 16061, 16361, 16561, 16661, 17471, 17971, 18181, 18481, 19391, 19891, 19991, 30103, 30203,
			30403, 30703, 30803, 31013, 31513, 32323, 32423, 33533, 34543, 34843, 35053, 35153, 35353, 35753,
			36263, 36563, 37273, 37573, 38083, 38183, 38783, 39293, 70207, 70507, 70607, 71317, 71917, 72227,
			72727, 73037, 73237, 73637, 74047, 74747, 75557, 76367, 76667, 77377, 77477, 77977, 78487, 78787,
			78887, 79397, 79697, 79997, 90709, 91019, 93139, 93239, 93739, 94049, 94349, 94649, 94849, 94949,
			95959, 96269, 96469, 96769, 97379, 97579, 97879, 98389, 98689, 1003001, 1008001, 1022201, 1028201,
			1035301, 1043401, 1055501, 1062601, 1065601, 1074701, 1082801, 1085801, 1092901, 1093901, 1114111, 1117111,
			1120211, 1123211, 1126211, 1129211, 1134311, 1145411, 1150511, 1153511, 1160611, 1163611, 1175711, 1177711,
			1178711, 1180811, 1183811, 1186811, 1190911, 1193911, 1196911, 1201021, 1208021, 1212121, 1215121, 1218121,
			1221221, 1235321, 1242421, 1243421, 1245421, 1250521, 1253521, 1257521, 1262621, 1268621, 1273721, 1276721,
			1280821, 1281821, 1286821, 1287821, 1300031, 1303031, 1311131, 1317131, 1327231, 1328231, 1333331, 1335331,
			1338331, 1343431, 1360631, 1362631, 1363631, 1371731, 1374731, 1390931, 1407041, 1409041, 1411141, 1412141,
			1422241, 1437341, 1444441, 1447441, 1452541, 1456541, 1461641, 1463641, 1464641, 1469641, 1486841, 1489841,
			1490941, 1496941, 1508051, 1513151, 1520251, 1532351, 1535351, 1538351, 1542451, 1548451, 1550551, 1556551,
			1557551, 1565651, 1572751, 1579751, 1580851, 1594951, 1597951, 1598951, 1600061, 1609061, 1611161, 1616161,
			1628261, 1630361, 1633361, 1640461, 1643461, 1646461, 1654561, 1657561, 1660661, 1670761, 1684861, 1685861,
			1688861, 1695961, 1703071, 1707071, 1712171, 1714171, 1730371, 1734371, 1737371, 1748471, 1755571, 1761671,
			1764671, 1777771, 1793971, 1802081, 1805081, 1820281, 1823281, 1824281, 1826281, 1829281, 1831381, 1832381,
			1842481, 1851581, 1853581, 1856581, 1865681, 1876781, 1878781, 1879781, 1880881, 1881881, 1883881, 1884881,
			1895981, 1903091, 1908091, 1909091, 1914191, 1917191, 1924291, 1930391, 1936391, 1941491, 1951591, 1952591,
			1963691, 1968691, 1970791, 1976791, 1981891, 1982891, 1984891, 1987891, 1993991, 1995991, 1998991, 3001003,
			3002003, 3007003, 3016103, 3026203, 3064603, 3065603, 3072703, 3073703, 3075703, 3083803, 3089803, 3091903,
			3095903, 3103013, 3106013, 3127213, 3135313, 3140413, 3155513, 3158513, 3160613, 3166613, 3181813, 318481

	};

	int t;
	cin >> t;

	while (t--)
	{
		 int arraySize;
    std::cin >> arraySize;
        
        int arr[arraySize];
        for (int i = 0; i < arraySize; i++)
            std::cin >> arr[i],magicalNumbers.insert(arr[i]);

        std::map<int, std::vector<int>> occurrences;
        int chosenNumber = -1, minDifference = INT_MAX;

				   // for (int i = 0; i < arraySize + 1; i++) {
        //     if (maxDistances[i] != -1) {
        //         if (maxDistances[i] < arraySize - occurrences[i][occurrences[i].size() - 1] - 1)
        //             maxDistances[i] = arraySize - occurrences[i][occurrences[i].size() - 1] - 1;
        //     }
        // }
        std::vector<int> maxDistances(arraySize + 1, -1);
   // for (int i = 0; i < arraySize + 1; i++) {
        //     if (maxDistances[i] != -1) {
        //         if (maxDistances[i] < arraySize - occurrences[i][occurrences[i].size() - 1] - 1)
        //             maxDistances[i] = arraySize - occurrences[i][occurrences[i].size() - 1] - 1;
        //     }
        // }
        for (int i = 0; i < arraySize; i++) {
            if (occurrences[arr[i]].empty())
                occurrences[arr[i]].push_back(-1);
        }

        int diff;
				   // for (int i = 0; i < arraySize + 1; i++) {
        //     if (maxDistances[i] != -1) {
        //         if (maxDistances[i] < arraySize - occurrences[i][occurrences[i].size() - 1] - 1)
        //             maxDistances[i] = arraySize - occurrences[i][occurrences[i].size() - 1] - 1;
        //     }
        // }
        for (int i = 0; i < arraySize; i++) {
            occurrences[arr[i]].push_back(i);

            if (occurrences[arr[i]].size() == 2)
                diff = i - occurrences[arr[i]][occurrences[arr[i]].size() - 2] - 1;
								   // for (int i = 0; i < arraySize + 1; i++) {
        //     if (maxDistances[i] != -1) {
        //         if (maxDistances[i] < arraySize - occurrences[i][occurrences[i].size() - 1] - 1)
        //             maxDistances[i] = arraySize - occurrences[i][occurrences[i].size() - 1] - 1;
        //     }
        // }
            else
                diff = ceil((i - occurrences[arr[i]][occurrences[arr[i]].size() - 2] - 1) / 2.0);

								   // for (int i = 0; i < arraySize + 1; i++) {
        //     if (maxDistances[i] != -1) {
        //         if (maxDistances[i] < arraySize - occurrences[i][occurrences[i].size() - 1] - 1)
        //             maxDistances[i] = arraySize - occurrences[i][occurrences[i].size() - 1] - 1;
        //     }
        // }

            if (maxDistances[arr[i]] < diff)
                maxDistances[arr[i]] = diff;
        }

				int si=0;

				for(auto it:magicalNumbers){
					si++;
					if(si>=diff) break;
				}

        for (int i = 0; i < arraySize + 1; i++) {
            if (maxDistances[i] != -1) {
                if (maxDistances[i] < arraySize - occurrences[i][occurrences[i].size() - 1] - 1)
                    maxDistances[i] = arraySize - occurrences[i][occurrences[i].size() - 1] - 1;
										   // for (int i = 0; i < arraySize + 1; i++) {
        //     if (maxDistances[i] != -1) {
        //         if (maxDistances[i] < arraySize - occurrences[i][occurrences[i].size() - 1] - 1)
        //             maxDistances[i] = arraySize - occurrences[i][occurrences[i].size() - 1] - 1;
        //     }
        // }
            }
        }

        for (int i = 0; i < arraySize + 1; i++) {
            if (maxDistances[i] != -1 && maxDistances[i] < minDifference) {
                minDifference = maxDistances[i];
                chosenNumber = i;

								   // for (int i = 0; i < arraySize + 1; i++) {
        //     if (maxDistances[i] != -1) {
        //         if (maxDistances[i] < arraySize - occurrences[i][occurrences[i].size() - 1] - 1)
        //             maxDistances[i] = arraySize - occurrences[i][occurrences[i].size() - 1] - 1;
        //     }
        // }
            }
        }

        cout << chosenNumber << " " << minDifference << endl;
		}
		return 0;
	}

	

	/*
	
	
Today was my 42th day out of the 100 days  hard challenge.
So today, I solved 6 problems .


1. Multiple of 9 (https://www.codechef.com/problems/MULT9).


2. Fair Distribution (https://www.codechef.com/problems/FAIR_DISTRIB).


3. Clan Expansion (https://www.codechef.com/problems/CLANEXPNSN)


4. Palindromic Prime Numbers (https://www.codechef.com/problems/MD_RIEV).


5. Chess Pairing (https://www.codechef.com/problems/CHESS_PAIR).




#100dayschallenge #challenge #consistency #SegmentTree #lessons
#learning
	
	
	*/