K’th Smallest / Largest Element in Unsorted Array | Set 1 Difficulty Level : Medium
                                                                                 Last Updated : 10 Oct,
    2022 Read
        Discuss

            Given an array and a number K where K is smaller than the size of the array.Find the K’th smallest element in the given array.Given that all array elements are distinct.

    Examples :

    Input : arr[] = {7, 10, 4, 3, 20, 15},
            K = 3 Output : 7

            Input : arr[] = {7, 10, 4, 3, 20, 15},
            K = 4 Output : 10

// C++ program to find K'th smallest element using min heap

#include <climits>
#include <iostream>
            using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);

// A class for Min Heap
class MinHeap
{

    int *harr;     // pointer to array of elements in heap
    int capacity;  // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    MinHeap(int a[], int size); // Constructor

    // To minheapify subtree rooted with index i
    void MinHeapify(int i);
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

    int extractMin();                // extracts root (minimum) element
    int getMin() { return harr[0]; } // Returns minimum
};

MinHeap::MinHeap(int a[], int size)
{
    heap_size = size;
    harr = a; // store address of array
    int i = (heap_size - 1) / 2;
    while (i >= 0)
    {
        MinHeapify(i);
        i--;
    }
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin()
{
    if (heap_size == 0)
        return INT_MAX;

    // Store the minimum value.
    int root = harr[0];

    // If there are more than 1 items, move the last item to
    // root and call heapify.
    if (heap_size > 1)
    {
        harr[0] = harr[heap_size - 1];
        MinHeapify(0);
    }
    heap_size--;

    return root;
}

// A recursive method to heapify a subtree with root at
// given index This method assumes that the subtrees are
// already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && harr[l] < harr[i])
        smallest = l;

    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;

    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to return k'th smallest element in a given array
int kthSmallest(int arr[], int N, int K)
{
    // Build a heap of n elements: O(n) time
    MinHeap mh(arr, N);

    // Do extract min (K-1) times
    for (int i = 0; i < K - 1; i++)
        mh.extractMin();

    // Return root
    return mh.getMin();
}

// Driver's code
int main()
{
    int arr[] = {12, 3, 5, 7, 19};
    int N = sizeof(arr) / sizeof(arr[0]), K = 2;

    // Function call
    cout << "K'th smallest element is "
         << kthSmallest(arr, N, K);
    return 0;
}
