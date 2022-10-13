/*
Sliding Window Maximum (Maximum of all subarrays of size K)

Given an array and an integer K, find the maximum for each and every
contiguous subarray of size K.

Examples : 

Input: arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}, K = 3 
Output: 3 3 4 5 5 5 6
Explanation: Maximum of 1, 2, 3 is 3
                       Maximum of 2, 3, 1 is 3
                       Maximum of 3, 1, 4 is 4
                       Maximum of 1, 4, 5 is 5
                       Maximum of 4, 5, 2 is 5 
                       Maximum of 5, 2, 3 is 5
                       Maximum of 2, 3, 6 is 6

Input: arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13}, K = 4 
Output: 10 10 10 15 15 90 90
Explanation: Maximum of first 4 elements is 10, similarly for next 4 
                       elements (i.e from index 1 to 4) is 10, So the sequence 
                       generated is 10 10 10 15 15 90 90
*/                       

// CPP program for the above approach
#include <bits/stdc++.h>
using namespace std;

// A Dequeue (Double ended queue) based
// method for printing maximum element of
// all subarrays of size k
void printKMax(int arr[], int N, int K)
{

	// Create a Double Ended Queue,
	// Qi that will store indexes
	// of array elements
	// The queue will store indexes
	// of useful elements in every
	// window and it will
	// maintain decreasing order of
	// values from front to rear in Qi, i.e.,
	// arr[Qi.front[]] to arr[Qi.rear()]
	// are sorted in decreasing order
	std::deque<int> Qi(K);

	/* Process first k (or first window)
	elements of array */
	int i;
	for (i = 0; i < K; ++i) {

		// For every element, the previous
		// smaller elements are useless so
		// remove them from Qi
		while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])

			// Remove from rear
			Qi.pop_back();

		// Add new element at rear of queue
		Qi.push_back(i);
	}

	// Process rest of the elements,
	// i.e., from arr[k] to arr[n-1]
	for (; i < N; ++i) {

		// The element at the front of
		// the queue is the largest element of
		// previous window, so print it
		cout << arr[Qi.front()] << " ";

		// Remove the elements which
		// are out of this window
		while ((!Qi.empty()) && Qi.front() <= i - K)

			// Remove from front of queue
			Qi.pop_front();

		// Remove all elements
		// smaller than the currently
		// being added element (remove
		// useless elements)
		while ((!Qi.empty()) && arr[i] >= arr[Qi.back()])
			Qi.pop_back();

		// Add current element at the rear of Qi
		Qi.push_back(i);
	}

	// Print the maximum element
	// of last window
	cout << arr[Qi.front()];
}

// Driver's code
int main()
{
	int arr[] = { 12, 1, 78, 90, 57, 89, 56 };
	int N = sizeof(arr) / sizeof(arr[0]);
	int K = 3;

	// Function call
	printKMax(arr, N, K);
	return 0;
}
