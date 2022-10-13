/*
Find K most occurring elements in the given Array

Given an array of N numbers and a positive integer K. The problem is
to find K numbers with the most occurrences, i.e., the top K numbers
having the maximum frequency. If two numbers have the same frequency
then the number with a larger value should be given preference. The
numbers should be displayed in decreasing order of their frequencies.
It is assumed that the array consists of at least K numbers.

Examples:
Input: arr[] = {3, 1, 4, 4, 5, 2, 6, 1}, K = 2
Output: 4 1
Explanation:
Frequency of 4 = 2, Frequency of 1 = 2
These two have the maximum frequency and 4 is larger than 1.

Input: arr[] = {7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9}, K = 4
Output: 5 11 7 10
Explanation:
Frequency of 5 = 3, Frequency of 11 = 2, Frequency of 7 = 2, Frequency of 10 = 1
These four have the maximum frequency and 5 is largest among rest.
*/

// C++ implementation to find k numbers with most
// occurrences in the given array Using MAX_HEAP.

#include <bits/stdc++.h>
using namespace std;

// Comparison function defined for the priority queue
struct compare
{
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        // If frequencies of two elements are same
        // then the larger number should come first
        if (p1.second == p2.second)
            return p1.first < p2.first;

        // Insert elements in the priority queue on the
        // basis of decreasing order of frequencies
        return p1.second < p2.second;
    }
};

// Function to print the k numbers with most occurrences
void print_N_mostFrequentNumber(int arr[], int N, int K)
{
    // unordered_map 'mp' implemented as frequency hash
    // table
    unordered_map<int, int> mp;
    for (int i = 0; i < N; i++)
        mp[arr[i]]++;

    // priority queue 'pq' implemented as max heap on the
    // basis of the comparison operator 'compare' element
    // with the highest frequency is the root of 'pq' in
    // case of conflicts, larger element is the root
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   compare>
        pq(mp.begin(), mp.end());

    // Display the top k numbers
    cout << K << " numbers with most occurrences are:\n";
    for (int i = 1; i <= K; i++)
    {
        cout << pq.top().first << " ";
        pq.pop();
    }
}

// Driver's code
int main()
{
    int arr[] = {3, 1, 4, 4, 5, 2, 6, 1};
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 2;

    // Function call
    print_N_mostFrequentNumber(arr, N, K);
    return 0;
}
