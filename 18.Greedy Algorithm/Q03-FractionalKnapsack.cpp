/*
C++ Program for the Fractional Knapsack Problem

Pre-requisite: Fractional Knapsack Problem

Given two arrays weight[] and profit[] the weights and profit of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item.

Examples:

Input: weight[] = {10, 20, 30}, profit[] = {60, 100, 120}, N= 50
Output: Maximum profit earned = 240
Explanation: 
Decreasing p/w ratio[] = {6, 5, 4}
Taking up the weight values 10, 20, (2 / 3) * 30 
Profit = 60 + 100 + 120 * (2 / 3) = 240

Input: weight[] = {10, 40, 20, 24}, profit[] = {100, 280, 120, 120}, N = 60
Output: Maximum profit earned = 440
Explanation: 
Decreasing p/w ratio[] = {10, 7, 6, 5}
Taking up the weight values 10, 40, (1 / 2) * 120 
Profit = 100 + 280 + (1 / 2) * 120 = 440
*/
 
// GREEDY 
// C++ program to solve fractional
// Knapsack Problem
#include <bits/stdc++.h>

using namespace std;

// Structure for an item which stores
// weight & corresponding value of Item
struct Item {
	int value, weight;

	// Constructor
	Item(int value, int weight)
		: value(value), weight(weight)
	{
	}
};

// Comparison function to sort Item
// according to val/weight ratio
bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.value / a.weight;
	double r2 = (double)b.value / b.weight;
	return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack(struct Item arr[],
						int N, int size)
{
	// Sort Item on basis of ratio
	sort(arr, arr + size, cmp);

	// Current weight in knapsack
	int curWeight = 0;

	// Result (value in Knapsack)
	double finalvalue = 0.0;

	// Looping through all Items
	for (int i = 0; i < size; i++) {

		// If adding Item won't overflow,
		// add it completely
		if (curWeight + arr[i].weight <= N) {
			curWeight += arr[i].weight;
			finalvalue += arr[i].value;
		}

		// If we can't add current Item,
		// add fractional part of it
		else {
			int remain = N - curWeight;
			finalvalue += arr[i].value
						* ((double)remain
							/ arr[i].weight);

			break;
		}
	}

	// Returning final value
	return finalvalue;
}

// Driver Code
int main()
{
	// Weight of knapsack
	int N = 60;

	// Given weights and values as a pairs
	Item arr[] = { { 100, 10 },
				{ 280, 40 },
				{ 120, 20 },
				{ 120, 24 } };

	int size = sizeof(arr) / sizeof(arr[0]);

	// Function Call
	cout << "Maximum profit earned = "
		<< fractionalKnapsack(arr, N, size);
	return 0;
}

// C++ program to Fractional Knapsack
// Problem using STL
#include <bits/stdc++.h>
using namespace std;

// Function to find maximum profit
void maxProfit(vector<int> profit,
			vector<int> weight, int N)
{

	// Number of total weights present
	int numOfElements = profit.size();
	int i;

	// Multimap container to store
	// ratio and index
	multimap<double, int> ratio;

	// Variable to store maximum profit
	double max_profit = 0;
	for (i = 0; i < numOfElements; i++) {

		// Insert ratio profit[i] / weight[i]
		// and corresponding index
		ratio.insert(make_pair(
			(double)profit[i] / weight[i], i));
	}

	// Declare a reverse iterator
	// for Multimap
	multimap<double, int>::reverse_iterator it;

	// Traverse the map in reverse order
	for (it = ratio.rbegin(); it != ratio.rend();
		it++) {

		// Fraction of weight of i'th item
		// that can be kept in knapsack
		double fraction = (double)N / weight[it->second];

		// if remaining_weight is greater
		// than the weight of i'th item
		if (N >= 0
			&& N >= weight[it->second]) {

			// increase max_profit by i'th
			// profit value
			max_profit += profit[it->second];

			// decrement knapsack to form
			// new remaining_weight
			N -= weight[it->second];
		}

		// remaining_weight less than
		// weight of i'th item
		else if (N < weight[it->second]) {
			max_profit += fraction
						* profit[it->second];
			break;
		}
	}

	// Print the maximum profit earned
	cout << "Maximum profit earned is:"
		<< max_profit;
}

// Driver Code
int main()
{
	// Size of list
	int size = 4;

	// Given profit and weight
	vector<int> profit(size), weight(size);

	// Profit of items
	profit[0] = 100, profit[1] = 280,
	profit[2] = 120, profit[3] = 120;

	// Weight of items
	weight[0] = 10, weight[1] = 40,
	weight[2] = 20, weight[3] = 24;

	// Capacity of knapsack
	int N = 60;

	// Function Call
	maxProfit(profit, weight, N);
}
