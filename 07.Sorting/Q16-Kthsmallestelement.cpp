/*
Given an array and a number K where K is smaller than the size of the
array. Find the K'th smallest element in the given array. Given 
that all array elements are distinct.

Examples:  
Input: arr[] = {7, 10, 4, 3, 20, 15}, K = 3 
Output: 7

Input: arr[] = {7, 10, 4, 3, 20, 15}, K = 4 
Output: 10 

*/

// C++ program to find K'th smallest element
#include <bits/stdc++.h>
using namespace std;

// Function to return K'th smallest element in a given array
int kthSmallest(int arr[], int N, int K)
{
	// Sort the given array
	sort(arr, arr + N);

	// Return k'th element in the sorted array
	return arr[K - 1];
}

// Driver's code
int main()
{
	int arr[] = { 12, 3, 5, 7, 19 };
	int N = sizeof(arr) / sizeof(arr[0]), K = 2;

	// Function call
	cout << "K'th smallest element is "
		<< kthSmallest(arr, N, K);
	return 0;
}

// Nlog(N).

// C++ code to implement the approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the kth smallest array element
int kthSmallest(int arr[], int N, int K)
{

	// For finding min element we need (Max heap)priority
	// queue
	priority_queue<int> pq;

	for (int i = 0; i < K; i++) {
		// First push first K elememts into heap
		pq.push(arr[i]);
	}
	// Now check from k to last element
	for (int i = K; i < N; i++) {

		// If current element is < top that means
		// there are other k-1 lesser elements
		// are present at bottom thus, pop that element
		// and add kth largest element into the heap till
		// curr at last all the greater element than kth
		// element will get pop off and at the top of heap
		// there will be kth smallest element
		if (arr[i] < pq.top()) {
			pq.pop();
			// Push curr element
			pq.push(arr[i]);
		}
	}

	// Return top of element
	return pq.top();
}

// Driver's code:
int main()
{
	int N = 10;
	int arr[N] = { 10, 5, 4, 3, 48, 6, 2, 33, 53, 10 };
	int K = 4;

	// Function call
	cout << "Kth Smallest Element is: "
		<< kthSmallest(arr, N, K);
}

O(Klog K + (N - K)log K)
O(K)