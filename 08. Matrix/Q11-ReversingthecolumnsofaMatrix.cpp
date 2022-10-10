/*
Program to reverse columns in given 2D Array (Matrix)

Given a 2D array arr[][]of integers of size M x N, 
where N is the number of columns and M is the 
number of rows in the array. The task is to 
reverse every column of the given 2D array

Input: arr[][] =  {{3, 2, 1}
                          {4, 5, 6},
                          {9, 8, 7}}

Output:  9 8 7
              4 5 6
              3 2 1

Input: arr[][] = {{7, 9}, 
                         {1, 5}, 
                         {4, 6},
                         {19, 3}}


Output:  19 3
               4 6
               1 5
               7 9
*/

// C++ implementation of the
// above approach
#include <bits/stdc++.h>
using namespace std;

const int M = 3;
const int N = 3;

// A utility function
// for swapping two elements.
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Print the arr[][]
void printMatrix(int arr[M][N])
{

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
}

// Function to reverse
// the given 2D arr[][]
void reverseColumnArray(int arr[M][N])
{

	// Print the arr[][] before
	// reversing every column
	printMatrix(arr);
	cout << endl;

	// Traverse each column of arr[][]
	for (int i = 0; i < N; i++) {
		// Initialise start and end index
		int start = 0;
		int end = M - 1;

		// Till start < end, swap the
		// element at start and end index
		while (start < end) {
			// Swap the element
			swap(&arr[start][i], &arr[end][i]);

			// Increment start and decrement
			// end for next pair of swapping
			start++;
			end--;
		}
	}

	// Print the arr[][] after
	// reversing every column
	printMatrix(arr);
}

// Driver Code
int main()
{
	int arr[][3]
		= { { 3, 2, 1 }, { 4, 5, 6 }, { 9, 8, 7 } };

	// Function call
	reverseColumnArray(arr);
	return 0;
}
