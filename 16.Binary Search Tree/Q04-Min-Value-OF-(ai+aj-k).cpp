/*
You are given an array of n integer and an integer K. Find the number of total unordered pairs {i, j} such that absolute value of (ai + aj – K), i.e., |ai + aj – k| is minimal possible where i != j.
Examples:


Input : arr[] = {0, 4, 6, 2, 4},
            K = 7
Output : Minimal Value = 1
         Total  Pairs = 5
Explanation : Pairs resulting minimal value are :
              {a1, a3}, {a2, a4}, {a2, a5}, {a3, a4}, {a4, a5}

Input : arr[] = {4, 6, 2, 4}  , K = 9
Output : Minimal Value = 1
         Total Pairs = 4
Explanation : Pairs resulting minimal value are :
              {a1, a2}, {a1, a4}, {a2, a3}, {a2, a4}
*/

// C++ program to find number of pairs
// and minimal possible value
#include <bits/stdc++.h>
using namespace std;

// function for finding pairs and min value
void pairs(int arr[], int n, int k)
{
    // initialize smallest and count
    int smallest = INT_MAX, count = 0;
    set<int> s;

    // iterate over all pairs
    s.insert(arr[0]);
    for (int i = 1; i < n; i++)
    {
        // Find the closest elements to k - arr[i]
        int lower = *lower_bound(s.begin(),
                                 s.end(),
                                 k - arr[i]);

        int upper = *upper_bound(s.begin(),
                                 s.end(),
                                 k - arr[i]);

        // Find absolute value of the pairs formed
        // with closest greater and smaller elements.
        int curr_min = min(abs(lower + arr[i] - k),
                           abs(upper + arr[i] - k));

        // is abs value is smaller than smallest
        // update smallest and reset count to 1
        if (curr_min < smallest)
        {
            smallest = curr_min;
            count = 1;
        }

        // if abs value is equal to smallest
        // increment count value
        else if (curr_min == smallest)
            count++;
        s.insert(arr[i]);

    } // print result

    cout << "Minimal Value = " << smallest << "\n";
    cout << "Total Pairs = " << count << "\n";
}

// driver program
int main()
{
    int arr[] = {3, 5, 7, 5, 1, 9, 9};
    int k = 12;
    int n = sizeof(arr) / sizeof(arr[0]);
    pairs(arr, n, k);
    return 0;
}
