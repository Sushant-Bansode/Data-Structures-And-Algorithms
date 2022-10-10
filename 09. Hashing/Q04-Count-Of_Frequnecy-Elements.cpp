/*Given an array which may contain duplicates, print all elements and their 
frequencies.

Examples: 

Input :  arr[] = {10, 20, 20, 10, 10, 20, 5, 20}
Output : 10 3
         20 4
         5  1

Input : arr[] = {10, 20, 20}
Output : 10 1
         20 2 */

// CPP program to count frequencies of array items
#include <bits/stdc++.h>
using namespace std;

void countFreq(int arr[], int n)
{
	unordered_map<int, int> mp;

	// Traverse through array elements and
	// count frequencies
	for (int i = 0; i < n; i++)
		mp[arr[i]]++;

	// Traverse through map and print frequencies
	for (auto x : mp)
		cout << x.first << " " << x.second << endl;
}

int main()
{
	int arr[] = { 10, 20, 20, 10, 10, 20, 5, 20 };
	int n = sizeof(arr) / sizeof(arr[0]);
	countFreq(arr, n);
	return 0;
}
