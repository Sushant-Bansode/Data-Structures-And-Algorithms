/*
Given a circular array of size n, find the maximum subarray sum
of the non-empty subarray.
Examples: 
Input: arr[] = {8, -8, 9, -9, 10, -11, 12}
Output: 22 
Explanation: Subarray 12, 8, -8, 9, -9, 10 gives the maximum sum,
that is 22.

Input: arr[] = {10, -3, -4, 7, 6, 5, -4, -1} 
Output:  23 
Explanation: Subarray 7, 6, 5, -4, -1, 10 gives the maximum sum, 
that is 23.

Input: arr[] = {-1, 40, -14, 7, 6, 5, -4, -1}
Output: 52 
Explanation: Subarray 7, 6, 5, -4, -1, -1, 40 gives the maximum sum,
that is 52.
*/
/*
Maximum Circular Subarray Sum using Kadane's Algorithm:

The idea is to modify Kadane's algorithm to find a 
minimum contiguous subarray sum and the maximum 
contiguous subarray sum, then check for the maximum 
value between the max_value and the value left after 
subtracting min_value from the total sum.

Illustration:

Input: arr[] = {8, -8, 9, -9, 10, -11, 12}, N = 7

sum = 11

Initialise: 
curr_max = arr[0], max_so_far = arr[0], curr_min = arr[0], 
min_so_far = arr[0]

At i = 1:

curr_max = max(curr_max + arr[1], arr[1]) = max(8 + (-8), -8) = 0
max_so_far = max(max_so_far, curr_max) = max(8, 0) = 8
curr_min = min(curr_min + a[1], a[1]) = min(8 + (-8), -8) = -8
min_so_far = min(curr_min, min_so_far) = min(-8, 8) = -8
At i = 2:

curr_max = max(curr_max + arr[2], arr[2]) = max(0 + 9, 9) = 9
max_so_far = max(max_so_far, curr_max) = max(8, 9) = 9
curr_min = min(curr_min + a[2], a[2]) = min(-8 + 9, 9) = 1
min_so_far = min(curr_min, min_so_far) = min(1, -8) = -8
At i = 3:

curr_max = max(curr_max + arr[3], arr[3]) = max(9 + (-9), -9) = 0
max_so_far = max(max_so_far, curr_max) = max(9, 0) = 9
curr_min = min(curr_min + a[3], a[3]) = min(1 + (-9), -9) = -9
min_so_far = min(curr_min, min_so_far) = min(-9, -8) = -9
At i = 4:

curr_max = max(curr_max + arr[4], arr[4]) = max(0 + 10, 10) = 10
max_so_far = max(max_so_far, curr_max) = max(9, 10) = 10
curr_min = min(curr_min + a[4], a[4]) = min(-9 + 10, 10) = 1
min_so_far = min(curr_min, min_so_far) = min(1, -9) = -9
At i = 5:

curr_max = max(curr_max + arr[5], arr[5]) = max(10 + (-11), -11) = -1
max_so_far = max(max_so_far, curr_max) = max(10, -1) = 10
curr_min = min(curr_min + a[5], a[5]) = min(1 + (-11), -11) = -11
min_so_far = min(curr_min, min_so_far) = min(-11, -9) = -11
At i = 6:

curr_max = max(curr_max + arr[6], arr[6]) = max(-1 + 12, 12) = 12
max_so_far = max(max_so_far, curr_max) = max(10, 12) = 12
curr_min = min(curr_min + a[6], a[6]) = min(-11+ 12, 12) = 1
min_so_far = min(curr_min, min_so_far) = min(1, -11) = -11
ans = max(max_so_far, sum – min_so_far) = (12, 11 – (-11)) = 22

Hence, maximum circular subarray sum is 22 */

// C++ program for maximum contiguous circular sum problem
#include <bits/stdc++.h>
using namespace std;

// The function returns maximum
// circular contiguous sum in a[]
int maxCircularSum(int a[], int n)
{
	// Corner Case
	if (n == 1)
		return a[0];

	// Initialize sum variable which store total sum of the array.
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}

	// Initialize every variable with first value of array.
	int curr_max = a[0], max_so_far = a[0], curr_min = a[0], min_so_far = a[0];

	// Concept of Kadane's Algorithm
	for (int i = 1; i < n; i++) {
		// Kadane's Algorithm to find Maximum subarray sum.
		curr_max = max(curr_max + a[i], a[i]);
		max_so_far = max(max_so_far, curr_max);

		// Kadane's Algorithm to find Minimum subarray sum.
		curr_min = min(curr_min + a[i], a[i]);
		min_so_far = min(min_so_far, curr_min);
	}

	if (min_so_far == sum)
		return max_so_far;

	// returning the maximum value
	return max(max_so_far, sum - min_so_far);
}

/* Driver program to test maxCircularSum() */
int main()
{
	int a[] = { 11, 10, -20, 5, -3, -5, 8, -13, 10 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << "Maximum circular sum is " << maxCircularSum(a, n) << endl;
	return 0;
}
