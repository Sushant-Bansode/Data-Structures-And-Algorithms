// Kadane's Algorithm OR Maximum Sum Sub-Array. 
// Given an array arr[] of size N. The task is to find the 
// sum of the contiguous subarray within a arr[] with the largest sum. 

/*The idea of Kadane’s algorithm is to maintain a variable
max_ending_here that stores the maximum sum contiguous subarray
ending at current index and a variable max_so_far stores 
the maximum sum of contiguous subarray found so far, 
Everytime there is a positive-sum value in max_ending_here 
compare it with max_so_far and update max_so_far 
if it is greater than max_so_far.*/


// C++ program to print largest contiguous array sum
#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int size)
{
	int max_so_far = INT_MIN, max_ending_here = 0;

	for (int i = 0; i < size; i++) {
		max_ending_here = max_ending_here + a[i];
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;

		if (max_ending_here < 0)
			max_ending_here = 0;
	}
	return max_so_far;
}

// Driver Code
int main()
{
	int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	int n = sizeof(a) / sizeof(a[0]);

	// Function Call
	int max_sum = maxSubArraySum(a, n);
	cout << "Maximum contiguous sum is " << max_sum;
	return 0;
}

// C++ program to print largest contiguous array sum

#include <climits>
#include <iostream>
using namespace std;

int maxSubArraySum(int a[], int size)
{
	int max_so_far = INT_MIN, max_ending_here = 0,
		start = 0, end = 0, s = 0;

	for (int i = 0; i < size; i++) {
		max_ending_here += a[i];

		if (max_so_far < max_ending_here) {
			max_so_far = max_ending_here;
			start = s;
			end = i;
		}

		if (max_ending_here < 0) {
			max_ending_here = 0;
			s = i + 1;
		}
	}
	cout << "Maximum contiguous sum is " << max_so_far
		<< endl;
	cout << "Starting index " << start << endl
		<< "Ending index " << end << endl;
}

/*Driver program to test maxSubArraySum*/
int main()
{
	int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
	int n = sizeof(a) / sizeof(a[0]);
	int max_sum = maxSubArraySum(a, n);
	return 0;
}

/*Output
Maximum contiguous sum is 7
Starting index 2
Ending index 6 
*/