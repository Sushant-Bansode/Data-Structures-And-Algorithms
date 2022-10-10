/*
Minimum operations required to make each row and column of matrix equals
Difficulty Level : Hard
Last Updated : 07 Oct, 2022
Read
Discuss

Given a square matrix of size N X N. Find a minimum number of operations
 that are required such that the sum of elements on each row and 
 column becomes equal. In one operation, increment any value 
 of the cell of the matrix by 1. In the first line print the 
 minimum operation required and in the next n lines, print n integers 
 representing the final matrix after the procedure. 

Example: 

Input: {{1, 2},
           {3, 4}}
Output: 4
              {{4, 3}, 
              {3, 4}}
Explanation: Increment value of cell(0, 0) by 3. 
                       Increment value of cell(0, 1) by 1
                      Hence total 4 operation are required

Input: {{1, 2, 3},
            {4, 2, 3},
           {3, 2, 1}}
Output: 6
              {{2, 4, 3}, 
              {4, 2, 3}, 
             {3, 3, 3}} 
Explanation: Increment value of cell(0, 0) by 1. 
                       Increment value of cell(0, 1) by 2. 
                       Increment value of cell(2, 1) by 1.
                       Increment value of cell(2, 2) by 2.
                       Hence total 6 operation are required  
*/

// C++ Program to Find minimum number of operation required
// such that sum of elements on each row and column becomes
// same*/
#include <bits/stdc++.h>
using namespace std;

// Function to find minimum operation required to make sum
// of each row and column equals
int findMinOpeartion(int matrix[][2], int n)
{
	// Initialize the sumRow[] and sumCol[] array to 0
	int sumRow[n], sumCol[n];
	memset(sumRow, 0, sizeof(sumRow));
	memset(sumCol, 0, sizeof(sumCol));
	// Calculate sumRow[] and sumCol[] array
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			sumRow[i] += matrix[i][j];
			sumCol[j] += matrix[i][j];
		}
	// Find maximum sum value in either row or in column
	int maxSum = 0;
	for (int i = 0; i < n; ++i) {
		maxSum = max(maxSum, sumRow[i]);
		maxSum = max(maxSum, sumCol[i]);
	}
	int count = 0;
	for (int i = 0, j = 0; i < n && j < n;) {
		// Find minimum increment required in either row or
		// column
		int diff
			= min(maxSum - sumRow[i], maxSum - sumCol[j]);
		// Add difference in corresponding cell, sumRow[]
		// and sumCol[] array
		matrix[i][j] += diff;
		sumRow[i] += diff;
		sumCol[j] += diff;
		// Update the count variable
		count += diff;
		// If ith row satisfied, increment ith value for
		// next iteration
		if (sumRow[i] == maxSum)
			++i;
		// If jth column satisfied, increment jth value for
		// next iteration
		if (sumCol[j] == maxSum)
			++j;
	}
	return count;
}

// Utility function to print matrix
void printMatrix(int matrix[][2], int n)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << matrix[i][j] << " ";
		cout << "\n";
	}
}

// Driver code
int main()
{
	int matrix[][2] = { { 1, 2 }, { 3, 4 } };
	cout << findMinOpeartion(matrix, 2) << "\n";
	printMatrix(matrix, 2);
	return 0;
}

