/*
Find the Largest number with given number of digits and sum of digits
Given an integer s and d, The task is to find the largest number
with given digit sum s and the number of digits d.

Examples: 
Input: s = 9, d = 2
Output: 90

Input: s = 20, d = 3
Output: 992

*/

// C++ program to find the largest number that can be
// formed from given sum of digits and number of digits.
#include <iostream>
using namespace std;

// Prints the smallest possible number with digit sum 's'
// and 'm' number of digits.
void findLargest(int m, int s)
{
	// If sum of digits is 0, then a number is possible
	// only if number of digits is 1.
	if (s == 0) {
		(m == 1) ? cout << "Largest number is " << 0
				: cout << "Not possible";
		return;
	}

	// Sum greater than the maximum possible sum.
	if (s > 9 * m) {
		cout << "Not possible";
		return;
	}

	// Create an array to store digits of result
	int res[m];

	// Fill from most significant digit to least
	// significant digit.
	for (int i = 0; i < m; i++) {
		// Fill 9 first to make the number largest
		if (s >= 9) {
			res[i] = 9;
			s -= 9;
		}

		// If remaining sum becomes less than 9, then
		// fill the remaining sum
		else {
			res[i] = s;
			s = 0;
		}
	}

	cout << "Largest number is ";
	for (int i = 0; i < m; i++)
		cout << res[i];
}

// Driver code
int main()
{
	int s = 9, m = 2;
	findLargest(m, s);
	return 0;
}
