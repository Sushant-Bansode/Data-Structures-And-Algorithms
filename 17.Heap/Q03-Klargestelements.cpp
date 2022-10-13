/*
k largest(or smallest) elements in an array

Write an efficient program for printing k largest elements in an array. Elements in an array can be in any order.
For example: if the given array is [1, 23, 12, 9, 30, 2, 50] and you are asked for the largest 3 elements i.e.,
 k = 3 then your program should print 50, 30, and 23
*/

// C++ code for k largest/ smallest elements in an array
#include <bits/stdc++.h>
using namespace std;

// Function to find k largest array element
void kLargest(vector<int> &v, int N, int K)
{
    // Implementation using
    // a Priority Queue
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; ++i)
    {

        // Insert elements into
        // the priority queue
        pq.push(v[i]);

        // If size of the priority
        // queue exceeds k
        if (pq.size() > K)
        {
            pq.pop();
        }
    }

    // Print the k largest element
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

// Function to find k smallest array element
void kSmalest(vector<int> &v, int N, int K)
{
    // Implementation using
    // a Priority Queue
    priority_queue<int> pq;

    for (int i = 0; i < N; ++i)
    {

        // Insert elements into
        // the priority queue
        pq.push(v[i]);

        // If size of the priority
        // queue exceeds k
        if (pq.size() > K)
        {
            pq.pop();
        }
    }

    // Print the k smallest element
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

// driver program
int main()
{
    // Given array
    vector<int> arr = {11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45};
    // Size of array
    int n = arr.size();
    int k = 3;
    cout << k << " largest elements are : ";
    kLargest(arr, n, k);
    cout << k << " smallest elements are : ";
    kSmalest(arr, n, k);
}

#include <iostream>
using namespace std;

// Swap function to interchange
// the value of variables x and y
int swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

// Min Heap Class
// arr holds reference to an integer
// array size indicate the number of
// elements in Min Heap
class MinHeap
{

    int size;
    int *arr;

public:
    // Constructor to initialize the size and arr
    MinHeap(int size, int input[]);

    // Min Heapify function, that assumes that
    // 2*i+1 and 2*i+2 are min heap and fix the
    // heap property for i.
    void heapify(int i);

    // Build the min heap, by calling heapify
    // for all non-leaf nodes.
    void buildHeap();
};

// Constructor to initialize data
// members and creating mean heap
MinHeap::MinHeap(int size, int input[])
{
    // Initializing arr and size

    this->size = size;
    this->arr = input;

    // Building the Min Heap
    buildHeap();
}

// Min Heapify function, that assumes
// 2*i+1 and 2*i+2 are min heap and
// fix min heap property for i

void MinHeap::heapify(int i)
{
    // If Leaf Node, Simply return
    if (i >= size / 2)
        return;

    // variable to store the smallest element
    // index out of i, 2*i+1 and 2*i+2
    int smallest;

    // Index of left node
    int left = 2 * i + 1;

    // Index of right node
    int right = 2 * i + 2;

    // Select minimum from left node and
    // current node i, and store the minimum
    // index in smallest variable
    smallest = arr[left] < arr[i] ? left : i;

    // If right child exist, compare and
    // update the smallest variable
    if (right < size)
        smallest = arr[right] < arr[smallest]
                       ? right
                       : smallest;

    // If Node i violates the min heap
    // property, swap current node i with
    // smallest to fix the min-heap property
    // and recursively call heapify for node smallest.
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify(smallest);
    }
}

// Build Min Heap
void MinHeap::buildHeap()
{
    // Calling Heapify for all non leaf nodes
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(i);
    }
}

void FirstKelements(int arr[], int size, int k)
{
    // Creating Min Heap for given
    // array with only k elements
    MinHeap *m = new MinHeap(k, arr);

    // Loop For each element in array
    // after the kth element
    for (int i = k; i < size; i++)
    {

        // if current element is smaller
        // than minimum element, do nothing
        // and continue to next element
        if (arr[0] > arr[i])
            continue;

        // Otherwise Change minimum element to
        // current element, and call heapify to
        // restore the heap property
        else
        {
            arr[0] = arr[i];
            m->heapify(0);
        }
    }
    // Now min heap contains k maximum
    // elements, Iterate and print
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
}
// Driver Program
int main()
{

    int arr[] = {11, 3, 2, 1, 15, 5, 4,
                 45, 88, 96, 50, 45};

    int size = sizeof(arr) / sizeof(arr[0]);

    // Size of Min Heap
    int k = 3;

    FirstKelements(arr, size, k);

    return 0;
}
