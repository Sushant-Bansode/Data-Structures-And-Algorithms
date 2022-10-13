/*
Circular rotation of an array using deque in C++

Given an array arr[] of integers and another
integer D, the task is to perform D circular 
rotations on the array and print the modified array. Examples: 

Input: Arr[] = {1, 2, 3, 4, 5, 6}, D = 2 Output: 5 6 1 2 3 4 
Input: Arr[] = {1, 2, 3}, D = 2 Output: 2 3 1
*/

// C++ implementation of the Dequeue approach
#include <bits/stdc++.h>
using namespace std;

// Function to circular rotate
// the array by d elements
void rotate(deque<int> deq,
			int d, int n)
{
	// Push first d elements
	// from last to the beginning
	for (int i = 0; i < d; i++) {
		int val = deq.back();
		deq.pop_back();
		deq.push_front(val);
	}

	// Print the rotated array
	for (int i = 0; i < n; i++) {
		cout << deq[i] << " ";
	}
	cout << endl;
}

// Driver code
int main()
{
	deque<int> v = { 1, 2, 3, 4, 5, 6, 7 };
	int n = v.size();
	int d = 5;

	rotate(v, d % n, n);
}
