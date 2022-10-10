// Two Pointers Technique -:
/*
Two pointers is really an easy and effective technique that is
typically used for searching pairs in a sorted array.
Given a sorted array A (sorted in ascending order), 
having N integers, find if there exists 
any pair of elements (A[i], A[j]) such that their sum is equal to X.

Now let’s see how the two-pointer technique works. 
We take two pointers, one representing the first element 
and other representing the last element of the array, 
and then we add the values kept at both the pointers. 
If their sum is smaller than X then we shift the
left pointer to right or if their sum is greater than X 
then we shift the right pointer to left, 
in order to get closer to the sum.
We keep moving the pointers until we get the sum as X. 

*/

// C++ Program Illustrating Naive Approach to
// Find if There is a Pair in A[0..N-1] with Given Sum
// Using Two-pointers Technique

// Importing required libraries
#include <iostream>
#include <algorithm>

using namespace std;

// Two pointer technique based solution to find
// if there is a pair in A[0..N-1] with a given sum.
int isPairSum(int A[], int N, int X)
{
	// represents first pointer
	int i = 0;

	// represents second pointer
	int j = N - 1;

	while (i < j) {

		// If we find a pair
		if (A[i] + A[j] == X)
			return 1;

		// If sum of elements at current
		// pointers is less, we move towards
		// higher values by doing i++
		else if (A[i] + A[j] < X)
			i++;

		// If sum of elements at current
		// pointers is more, we move towards
		// lower values by doing j--
		else
			j--;
	}
	return 0;
}

// Driver code
int main()
{
	// array declaration
	int arr[] = { 2, 3, 5, 8, 9, 10, 11 };
	
	// value to search
	int val = 17;
	
	// size of the array
	int arrSize = *(&arr + 1) - arr;
	
	// array should be sorted before using two-pointer technique
	sort(arr, arr+7);

	// Function call
	cout << (bool)isPairSum(arr, arrSize, val);

	return 0;
}
