/*Search an element in a sorted and rotated Array
Difficulty Level : Medium
Last Updated : 08 Aug, 2022
Read
Discuss

Given a sorted and rotated array arr[] of size N and a key, the task is to find the key in the array.

Note: Find the element in O(logN) time and assume that all the elements are distinct.

Example:  

Input  : arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}, key = 3
Output : Found at index 8


Input  : arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}, key = 30
Output : Not found

Input : arr[] = {30, 40, 50, 10, 20}, key = 10   
Output : Found at index 3

The idea is to instead of two or more passes of binary search, the result can be found in one pass of binary search. 

The idea is to create a recursive function to implement the binary search where the search region is [l, r]. For each recursive call:

We calculate the mid value as mid = (l + h) / 2
Then try to figure out if l to mid is sorted, or (mid+1) to h is sorted
Based on that decide the next search region and keep on doing this till the element is found or l overcomes h.
Follow the steps mentioned below to implement the idea:  

Use a recursive function to implement binary search to find the key:
Find middle-point mid = (l + h)/2 
If the key is present at the middle point, return mid.
Else if the value at l is less than the one at mid then arr[l . . . mid] is sorted
If the key to be searched lies in the range from arr[l] to arr[mid], recur for arr[l . . . mid].
Else recur for arr[mid+1 . . . h]  
Else arr[mid+1. . . h] is sorted: 
If the key to be searched lies in the range from arr[mid+1] to arr[h], recur for arr[mid+1. . . h].
Else recur for arr[l. . . mid] 
Follow the below illustration for a better understanding:

Illustration:

Input arr[] = {3, 4, 5, 1, 2}, key = 1
Initially low = 0, high = 4.

low = 0, high = 4:
        => mid = 2
        => arr[mid] = 5, which is not the desired value.
        => arr[low] < arr[mid] So, the left half is sorted.
        => key < arr[low], So the next search region is 3 to 4.

low = 3, high = 4:
        => mid = 3
        => arr[mid] = 1 = key
        => So the element is found at index 3.

The element is found at index 3.

Below is the implementation of the above idea:  */



// Search an element in sorted and rotated
// array using single pass of Binary Search
#include <bits/stdc++.h>
using namespace std;

// Returns index of key in arr[l..h] if
// key is present, otherwise returns -1
int search(int arr[], int l, int h, int key)
{
	if (l > h)
		return -1;

	int mid = (l + h) / 2;
	if (arr[mid] == key)
		return mid;

	/* If arr[l...mid] is sorted */
	if (arr[l] <= arr[mid]) {
		/* As this subarray is sorted, we can quickly
		check if key lies in half or other half */
		if (key >= arr[l] && key <= arr[mid])
			return search(arr, l, mid - 1, key);
		/*If key not lies in first half subarray,
		Divide other half into two subarrays,
		such that we can quickly check if key lies
		in other half */
		return search(arr, mid + 1, h, key);
	}

	/* If arr[l..mid] first subarray is not sorted, then
	arr[mid... h] must be sorted subarray */
	if (key >= arr[mid] && key <= arr[h])
		return search(arr, mid + 1, h, key);

	return search(arr, l, mid - 1, key);
}

// Driver program
int main()
{
	int arr[] = { 4, 5, 6, 7, 8, 9, 1, 2, 3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 3;
	int i = search(arr, 0, n - 1, key);

	if (i != -1)
		cout << "Index: " << i << endl;
	else
		cout << "Key not found";
}
