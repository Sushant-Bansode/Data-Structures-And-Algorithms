/*
Connect n ropes with minimum cost

Given are N ropes of different lengths, the task is to connect these
ropes into one rope with minimum cost, such that the cost to connect
two ropes is equal to the sum of their lengths.

Examples:

Input: arr[] = {4,3,2,6} , N = 4
Output: 29
Explanation:

First, connect ropes of lengths 2 and 3. Now we have three ropes of lengths 4, 6, and 5.
Now connect ropes of lengths 4 and 5. Now we have two ropes of lengths 6 and 9.
Finally connect the two ropes and all ropes have connected.


Input: arr[] = {1, 2, 3} , N = 3
Output: 9
Explanation:

First, connect ropes of lengths 1 and 2. Now we have two ropes of lengths 3 and 3.
Finally connect the two ropes and all ropes have connected.
*/

// C++ program for connecting
// n ropes with minimum cost
#include <bits/stdc++.h>

using namespace std;

// A Min Heap: Collection of min heap nodes
struct MinHeap
{
    unsigned size;     // Current size of min heap
    unsigned capacity; // capacity of min heap
    int *harr;         // Array of minheap nodes
};

// A utility function to create
// a min-heap of a given capacity
struct MinHeap *createMinHeap(unsigned capacity)
{
    struct MinHeap *minHeap = new MinHeap;
    minHeap->size = 0; // current size is 0
    minHeap->capacity = capacity;
    minHeap->harr = new int[capacity];
    return minHeap;
}

// A utility function to swap two min heap nodes
void swapMinHeapNode(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// The standard minHeapify function.
void minHeapify(struct MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->harr[left] < minHeap->harr[smallest])
        smallest = left;

    if (right < minHeap->size && minHeap->harr[right] < minHeap->harr[smallest])
        smallest = right;

    if (smallest != idx)
    {
        swapMinHeapNode(&minHeap->harr[smallest],
                        &minHeap->harr[idx]);
        minHeapify(minHeap, smallest);
    }
}

// A utility function to check
// if size of heap is 1 or not
int isSizeOne(struct MinHeap *minHeap)
{
    return (minHeap->size == 1);
}

// A standard function to extract
// minimum value node from heap
int extractMin(struct MinHeap *minHeap)
{
    int temp = minHeap->harr[0];
    minHeap->harr[0] = minHeap->harr[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// A utility function to insert
// a new node to Min Heap
void insertMinHeap(struct MinHeap *minHeap, int val)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && (val < minHeap->harr[(i - 1) / 2]))
    {
        minHeap->harr[i] = minHeap->harr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->harr[i] = val;
}

// A standard function to build min-heap
void buildMinHeap(struct MinHeap *minHeap)
{
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// Creates a min-heap of capacity
// equal to size and inserts all values
// from len[] in it. Initially, size
// of min heap is equal to capacity
struct MinHeap *createAndBuildMinHeap(int len[], int size)
{
    struct MinHeap *minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->harr[i] = len[i];
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

// The main function that returns
// the minimum cost to connect n
// ropes of lengths stored in len[0..n-1]
int minCost(int len[], int n)
{
    int cost = 0; // Initialize result

    // Create a min heap of capacity
    // equal to n and put all ropes in it
    struct MinHeap *minHeap = createAndBuildMinHeap(len, n);

    // Iterate while size of heap doesn't become 1
    while (!isSizeOne(minHeap))
    {
        // Extract two minimum length
        // ropes from min heap
        int min = extractMin(minHeap);
        int sec_min = extractMin(minHeap);

        cost += (min + sec_min); // Update total cost

        // Insert a new rope in min heap
        // with length equal to sum
        // of two extracted minimum lengths
        insertMinHeap(minHeap, min + sec_min);
    }

    // Finally return total minimum
    // cost for connecting all ropes
    return cost;
}

// Driver program to test above functions
int main()
{
    int len[] = {4, 3, 2, 6};
    int size = sizeof(len) / sizeof(len[0]);
    cout << "Total cost for connecting ropes is "
         << minCost(len, size);
    return 0;
}
