/* Minimum Group Flips to Make Binary Array Elements Same

Given a binary array, we need to convert this array into an array that
either contains all 1s or all 0s.  We need to do it 
using the minimum number of group flips. 

Examples : 

Input : arr[] = {1, 1, 0, 0, 0, 1}
Output :  From 2 to 4
Explanation : We have two choices, we make all 0s or do all 1s.  We need to do two group flips to make all elements 0 and one group flip to make all elements 1.  Since making all elements 1 takes least group flips, we do this.
Input : arr[] = {1, 0, 0, 0, 1, 0, 0, 1, 0, 1}
Output :  
From 1 to 3
From 5 to 6
From 8 to 8
Input : arr[] = {0, 0, 0}
Output :  
Explanation : Output is empty, we need not to make any change
Input : arr[] = {1, 1, 1}
Output :  
Explanation : Output is empty, we need not to make any change
Input : arr[] = {0, 1}
Output :   
From 0 to 0  
OR
From 1 to 1
Explanation :  Here number of flips are same either we make all elements as 1 or all elements as 0.
 

 
A Naive Solution is to traverse do two traversals of the array.
We first traverse to find the number of groups of 0s
and the number of groups of 1.  We find the minimum of these two.
Then we traverse the array and flip
the 1s if groups of 1s are less. Otherwise, we flip 0s. */

/* How to do it with one traversal of array ?
An Efficient Solution is based on the below facts : 

There are only two types of groups (groups of 0s and groups of 1s)
Either the counts of both groups are same or the difference
between counts is at most 1. For example, in {1, 1, 0, 1, 0, 0}
there are two groups of 0s and two groups of 1s.  In example,
{1, 1, 0, 0, 0, 1, 0, 0, 1, 1}, 
count of groups of 1 is one more than the counts of 0s.
*/

// C++ program to find the minimum
// group flips in a binary array
#include <iostream>
using namespace std;

void printGroups(bool arr[], int n) {

// Traverse through all array elements
// starting from the second element
for (int i = 1; i < n; i++) {
	
	// If current element is not same
	// as previous
	if (arr[i] != arr[i - 1]) {
	
	// If it is same as first element
	// then it is starting of the interval
	// to be flipped.
	if (arr[i] != arr[0])
		cout << "From " << i << " to ";

	// If it is not same as previous
	// and same as first element, then
	// previous element is end of interval
	else
		cout << (i - 1) << endl;
	}
}

// Explicitly handling the end of
// last interval
if (arr[n - 1] != arr[0])
	cout << (n - 1) << endl;
}

int main() {
bool arr[] = {0, 1, 1, 0, 0, 0, 1, 1};
int n = sizeof(arr) / sizeof(arr[0]);
printGroups(arr, n);
return 0;
}
