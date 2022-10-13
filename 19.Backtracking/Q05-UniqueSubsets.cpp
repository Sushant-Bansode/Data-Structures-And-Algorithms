/*
Given an array A[] of positive integers, print all the unique non-empty subsets of the array 

Note: The set can not contain duplicate elements, so any repeated subset should be considered only once in the output.

Examples: 

Input: A[] = {1, 5, 6}
Output: {{1}, {1, 5}, {1, 6}, {5}, {5, 6}, {6}, {1, 5, 6}}
Explanantion: The number of all the non-empty possible subsets will be 2N-1. 
Here it will be {1}, {1, 5}, {1, 6}, {5}, {5, 6}, {6} and {1, 5, 6}


Input: A[] = {1, 2, 2}
Output: {{1}, {1, 2}, {1, 2, 2}, {2}, {2, 2}}

*/
// C++ code to implement the Backtracking approach

#include <bits/stdc++.h>
using namespace std;

// Helper function to find all unique subsets
void findSubsets(vector<int>& v, int idx,
				vector<int>& subset,
				set<vector<int> >& result)
{
	// If the current subset is not empty
	// insert it into the result
	if (!subset.empty())
		result.insert(subset);

	// Iterate over every element in the array
	for (int j = idx; j < v.size(); j++) {

		// Pick the element and move ahead
		subset.push_back(v[j]);
		findSubsets(v, j + 1, subset, result);

		// Backtrack to drop the element
		subset.pop_back();
	}
}

// Function to return all unique subsets
vector<vector<int> > solve(vector<int>& v)
{
	// To store the resulting subsets
	set<vector<int> > result;
	vector<int> subset;

	// Helper function call
	findSubsets(v, 0, subset, result);

	vector<vector<int> > res;
	for (auto v : result)
		res.push_back(v);

	return res;
}

// Driver code
int main()
{
	vector<int> A = { 1, 2, 2 };

	// Function call
	vector<vector<int> > result = solve(A);

	// Print all unique subsets
	for (auto v : result) {
		for (int i : v) {
			cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}
