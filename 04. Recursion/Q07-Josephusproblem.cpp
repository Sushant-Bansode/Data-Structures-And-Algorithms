/*  JOSEPHUS-PROBLEM 
There are N people standing in a circle waiting to be executed.
 The counting out begins at some point in the circle and proceeds
around the circle in a fixed direction. 
In each step, a certain number of people are skipped and
the next person is executed. The elimination proceeds around the circle 
(which is becoming smaller and smaller as the executed people are removed), 
until only the last person remains, who is given freedom. 

Given the total number of persons N and a number k which indicates
that k-1 persons are skipped and the kth person is killed in a circle.
The task is to choose the person in the initial circle that survives. */

/*Josephus Problem using Recursion:
Below is the idea to solve the problem:

The problem has the following recursive structure. 
josephus(n, k) = (josephus(n – 1, k) + k-1) % n + 1 and josephus(1, k) = 1

After the first person (kth from the beginning) is killed, 
n-1 persons are left. Make recursive call for Josephus(n - 1, k) 
to get the position with n-1 persons. But the position returned 
by Josephus(n - 1, k) will consider the position starting from k%n + 1.
 So make adjustments to the position returned by Josephus(n - 1, k). */

// C++ code to implement the idea

#include <bits/stdc++.h>
using namespace std;

// Recursive function to implement the Josephus problem
int josephus(int n, int k)
{
	if (n == 1)
		return 1;
	else
		// The position returned by josephus(n - 1, k)
		// is adjusted because the recursive call
		// josephus(n - 1, k) considers the
		// original position k % n + 1 as position 1
		return (josephus(n - 1, k) + k - 1) % n + 1;
}

// Driver code
int main()
{
	int n = 14;
	int k = 2;
	cout << "The chosen place is " << josephus(n, k);
	return 0;
}

// TIME COMPLEXITY = O(N).
// AUXILIARY SPACE = O(N).