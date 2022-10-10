/*
Inversion Count for an array indicates - 
how far (or close) the array is from being sorted. 
If the array is already sorted, then the inversion count 
is 0, but if the array is sorted in reverse order, 
the inversion count is the maximum. 

Given an array a[]. The task is to find the inversion count of a[]. 
Wher two elements a[i] and a[j] form an inversion if a[i] > a[j] 
and i < j

Examples: 

Input: arr[] = {8, 4, 2, 1}
Output: 6
Explanation: Given array has six 
inversions: (8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).

Input: arr[] = {1, 20, 6, 4, 5}
Output: 5
Explanation: Given array has five 
inversions: (20, 6), (20, 4), (20, 5), (6, 4), (6, 5). 
*/


// C++ program to Count
// Inversions in an array
// using Merge Sort
#include <bits/stdc++.h>
using namespace std;

int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid,
		int right);

// This function sorts the
// input array and returns the
// number of inversions in the array
int mergeSort(int arr[], int array_size)
{
	int temp[array_size];
	return _mergeSort(arr, temp, 0, array_size - 1);
}

// An auxiliary recursive function
// that sorts the input array and
// returns the number of inversions in the array.
int _mergeSort(int arr[], int temp[], int left, int right)
{
	int mid, inv_count = 0;
	if (right > left) {
		// Divide the array into two parts and
		// call _mergeSortAndCountInv()
		// for each of the parts
		mid = (right + left) / 2;

		// Inversion count will be sum of
		// inversions in left-part, right-part
		// and number of inversions in merging
		inv_count += _mergeSort(arr, temp, left, mid);
		inv_count += _mergeSort(arr, temp, mid + 1, right);

		// Merge the two parts
		inv_count += merge(arr, temp, left, mid + 1, right);
	}
	return inv_count;
}

// This function merges two sorted arrays
// and returns inversion count in the arrays.
int merge(int arr[], int temp[], int left, int mid,
		int right)
{
	int i, j, k;
	int inv_count = 0;

	i = left;
	j = mid;
	k = left;
	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];

			// this is tricky -- see above
			// explanation/diagram for merge()
			inv_count = inv_count + (mid - i);
		}
	}

	// Copy the remaining elements of left subarray
	// (if there are any) to temp
	while (i <= mid - 1)
		temp[k++] = arr[i++];

	// Copy the remaining elements of right subarray
	// (if there are any) to temp
	while (j <= right)
		temp[k++] = arr[j++];

	// Copy back the merged elements to original array
	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}

// Driver code
int main()
{
	int arr[] = { 1, 20, 6, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int ans = mergeSort(arr, n);
	cout << " Number of inversions are " << ans;
	return 0;
}

