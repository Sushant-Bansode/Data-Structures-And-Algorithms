// Prefix-Sum
/*
Given an array arr[] of size n, its prefix sum array is another
array prefixSum[] of the same size, such that the value of 
prefixSum[i] is arr[0] + arr[1] + arr[2] … arr[i].

Examples : 

Input  : arr[] = {10, 20, 10, 5, 15}
Output : prefixSum[] = {10, 30, 40, 45, 60}
Explanation : While traversing the array, update the element by adding it with its previous element.
prefixSum[0] = 10, 
prefixSum[1] = prefixSum[0] + arr[1] = 30, 
prefixSum[2] = prefixSum[1] + arr[2] = 40 and so on. */

// C++ program for Implementing prefix sum array
#include <bits/stdc++.h>
using namespace std;

// Fills prefix sum array
void fillPrefixSum(int arr[], int n, int prefixSum[])
{
	prefixSum[0] = arr[0];
	// Adding present element with previous element
	for (int i = 1; i < n; i++)
		prefixSum[i] = prefixSum[i - 1] + arr[i];
}

// Driver Code
int main()
{
	int arr[] = { 10, 4, 16, 20 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int prefixSum[n];
	fillPrefixSum(arr, n, prefixSum);
	for (int i = 0; i < n; i++)
		cout << prefixSum[i] << " ";
}

/*Given an array arr[] of size n. Given Q queries and in each query 
given L and R, print sum of array elements from index L to R.
Implementation: */

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int pf[N];

int main()
{
	int n = 6;
	int a[] = { 3, 6, 2, 8, 9, 2 };

	pf[0] = a[0];
	for (int i = 1; i < n; i++) {
		pf[i] = pf[i - 1] + a[i];
		// cout<<pf[i];
	}
	int q = 4;
	vector<vector<int> > query
		= { { 2, 3 }, { 4, 6 }, { 1, 5 }, { 3, 6 } };
	for (int i = 0; i < q; i++) {
		int l = query[i][0], r = query[i][1];
		if (r > n || l < 1) {
			cout << "Please input in range 1 to " << n
				<< endl;
			continue;
		}
		if (l == 1)
			cout << pf[r-1] << endl;
		else
			cout << pf[r-1] - pf[l - 2] << endl;
	}
	return 0;
}

