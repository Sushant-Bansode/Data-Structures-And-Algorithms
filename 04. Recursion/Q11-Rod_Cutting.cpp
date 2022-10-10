/*Given a rod of length n inches and an array of prices that includes prices
 of all pieces of size smaller than n. Determine the maximum value 
 obtainable by cutting up the rod and selling the pieces. 
 For example, if the length of the rod is 8 and the values 
 of different pieces are given as the following, then the 
 maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6) 

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 1   5   8   9  10  17  17  20
And if the prices are as following, then the maximum obtainable 
value is 24 (by cutting in eight pieces of length 1) 

length   | 1   2   3   4   5   6   7   8  
--------------------------------------------
price    | 3   5   8   9  10  17  17  20

A naive solution to this problem is to generate all configurations
of different pieces and find the highest-priced configuration. 
This solution is exponential in terms of time complexity. 
*/


// A recursive solution for Rod cutting problem
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;

// A utility function to get the maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

/* Returns the best obtainable price for a rod of length n
and price[] as prices of different pieces */
int cutRod(int price[], int index, int n)
{
	// base case
	if (index == 0) {
		return n * price[0];
	}
	//At any index we have 2 options either
	//cut the rod of this length or not cut
	//it
	int notCut = cutRod(price,index - 1,n);
	int cut = INT_MIN;
	int rod_length = index + 1;

	if (rod_length <= n)
		cut = price[index]
			+ cutRod(price,index,n - rod_length);

	return max(notCut, cut);
}

/* Driver program to test above functions */
int main()
{
	int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "Maximum Obtainable Value is "
		<< cutRod(arr, size - 1, size);
	getchar();
	return 0;
}


