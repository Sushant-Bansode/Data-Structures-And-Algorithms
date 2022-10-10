// C++ program to implement insert
// operation in an unsorted array.
// Coding implementation of inserting an element at the end:
#include <iostream>
using namespace std;

// Inserts a key in arr[] of given capacity.
// n is current size of arr[]. This
// function returns n + 1 if insertion
// is successful, else n.
int insertSorted(int arr[], int n, int key, int capacity)
{

	// Cannot insert more elements if n is
	// already more than or equal to capacity
	if (n >= capacity)
		return n;

	arr[n] = key;

	return (n + 1);
}

// Driver Code
int main()
{
	int arr[20] = { 12, 16, 20, 40, 50, 70 };
	int capacity = sizeof(arr) / sizeof(arr[0]);
	int n = 6;
	int i, key = 26;

	cout << "\n Before Insertion: ";
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";

	// Inserting key
	n = insertSorted(arr, n, key, capacity);

	cout << "\n After Insertion: ";
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}

// 2. Insert at any position
// C Program to Insert an element
// at a specific position in an Array

#include <stdio.h>

// Function to insert element
// at a specific position
void insertElement(int arr[], int n, int x, int pos)
{
	// shift elements to the right
	// which are on the right side of pos
	for (int i = n - 1; i >= pos; i--)
		arr[i + 1] = arr[i];

	arr[pos] = x;
}

// Driver's code
int main()
{
	int arr[15] = { 2, 4, 1, 8, 5 };
	int n = 5;

	printf("Before insertion : ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	printf("\n");

	int x = 10, pos = 2;

	// Function call
	insertElement(arr, n, x, pos);
	n++;

	printf("After insertion : ");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}

// C++ program to implement delete operation in a
// unsorted array

#include <iostream>
using namespace std;

// To search a key to be deleted
int findElement(int arr[], int n, int key);

// Function to delete an element
int deleteElement(int arr[], int n, int key)
{
	// Find position of element to be deleted
	int pos = findElement(arr, n, key);

	if (pos == -1) {
		cout << "Element not found";
		return n;
	}

	// Deleting element
	int i;
	for (i = pos; i < n - 1; i++)
		arr[i] = arr[i + 1];

	return n - 1;
}

// Function to implement search operation
int findElement(int arr[], int n, int key)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == key)
			return i;

	return -1;
}

// Driver's code
int main()
{
	int i;
	int arr[] = { 10, 50, 30, 40, 20 };

	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 30;

	cout << "Array before deletion\n";
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	

	// Function call
	n = deleteElement(arr, n, key);

	cout << "\n\nArray after deletion\n";
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}
