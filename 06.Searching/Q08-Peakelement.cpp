/*
Given an array arr[] of integers. Find a peak element i.e.
 an element that is not smaller than its neighbors. 
Note: For corner elements, we need to consider only one neighbor. 

Example:

Input: array[]= {5, 10, 20, 15}
Output: 20
Explanation: The element 20 has neighbors 10 and 15, 
both of them are less than 20.

Input: array[] = {10, 20, 15, 2, 23, 90, 67}
Output: 20 or 90
Explanation: The element 20 has neighbors 10 and 15,
 both of them are less than 20, similarly 90 has neighbors 23 and 67.

Find a peak element using recursive Binary Search
Below is the idea to solve the problem.

Using Binary Search, check if the middle element is the 
peak element or not. If the middle element is not the 
peak element, then check if the element on the right side 
is greater than the middle element then there is always 
a peak element on the right side. If the element on the 
left side is greater than the middle element then 
there is always a peak element on the left side. 

*/

// A C++ program to find a peak element
// using divide and conquer
#include <bits/stdc++.h>
using namespace std;

// A binary search based function
// that returns index of a peak element
int findPeakUtil(int arr[], int low,
				int high, int n)
{
	// Find index of middle element
	// low + (high - low) / 2
	int mid = low + (high - low) / 2;

	// Compare middle element with its
	// neighbours (if neighbours exist)
	if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&
		(mid == n - 1 || arr[mid + 1] <= arr[mid]))
		return mid;

	// If middle element is not peak and its
	// left neighbour is greater than it,
	// then left half must have a peak element
	else if (mid > 0 && arr[mid - 1] > arr[mid])
		return findPeakUtil(arr, low, (mid - 1), n);

	// If middle element is not peak and its
	// right neighbour is greater than it,
	// then right half must have a peak element
	else
		return findPeakUtil(
			arr, (mid + 1), high, n);
}

// A wrapper over recursive function findPeakUtil()
int findPeak(int arr[], int n)
{
	return findPeakUtil(arr, 0, n - 1, n);
}

// Driver Code
int main()
{
	int arr[] = { 1, 3, 20, 4, 1, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Index of a peak point is "
		<< findPeak(arr, n);
	return 0;
}

// Time Complexity: O(log N), Where N is the number of elements in the input array. 
// Auxiliary Space: O(log N), As recursive call is there, hence implicit stack is used.

// For Iterative Binary Search It Becomes O(1).




