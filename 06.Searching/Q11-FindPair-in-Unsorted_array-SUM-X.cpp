/*
Given an array A[] of n numbers and another number x, 
the task is to check whether or not there exist two 
elements in A[] whose sum is exactly x. 
// Two Pointers.

Examples: 

Input: arr[] = {0, -1, 2, -3, 1}, x= -2
Output: Yes
Explanation:  If we calculate the sum of the output,1 + (-3) = -2

Input: arr[] = {1, -2, 1, 0, 5}, x = 0
Output: No
*/


// C++ program to check if given array
// has 2 elements whose sum is equal
// to the given value

#include <bits/stdc++.h>
using namespace std;

// Function to check if array has 2 elements
// whose sum is equal to the given value
bool hasArrayTwoCandidates(int A[], int arr_size, int sum)
{
	int l, r;

	/* Sort the elements */
	sort(A, A + arr_size);

	/* Now look for the two candidates in
	the sorted array*/
	l = 0;
	r = arr_size - 1;
	while (l < r) {
		if (A[l] + A[r] == sum)
			return 1;
		else if (A[l] + A[r] < sum)
			l++;
		else // A[i] + A[j] > sum
			r--;
	}
	return 0;
}

/* Driver program to test above function */
int main()
{
	int A[] = { 1, 4, 45, 6, 10, -8 };
	int n = 16;
	int arr_size = sizeof(A) / sizeof(A[0]);

	// Function calling
	if (hasArrayTwoCandidates(A, arr_size, n))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
