// C++ Iterative program to Count set
// bits in an integer
#include <bits/stdc++.h>
using namespace std;

/* Function to get no of set bits in binary
representation of positive integer n */
unsigned int countSetBits(unsigned int n)
{
	unsigned int count = 0;
	while (n) {
		count += n & 1;
		n >>= 1;
	}
	return count;
}

/* Program to test function countSetBits */
int main()
{
	int i = 9;
	cout << countSetBits(i);
	return 0;
}

// Time Complexity: O(logn) 
// Auxiliary Space: O(1)

// cpp implementation of recursive approach to find the
// number of set bits in binary representation of positive
// integer n
#include <bits/stdc++.h>
using namespace std;

// recursive function to count set bits
int countSetBits(int n)
{
	// base case
	if (n == 0)
		return 0;
	else
		// if last bit set add 1 else add 0
		return (n & 1) + countSetBits(n >> 1);
}

// driver code
int main()
{
	int n = 9;
	// function calling
	cout << countSetBits(n);
	return 0;
}

// Time Complexity: O(log n)
// Auxiliary Space: O(log n) for recursive stack space


/* Brian Kernighan’s Algorithm: 

 1  Initialize count: = 0
   2  If integer n is not zero
      (a) Do bitwise & with (n-1) and assign the value back to n
          n: = n&(n-1)
      (b) Increment count by 1
      (c) go to step 2
   3  Else return count */

// C++ program to Count set
// bits in an integer
#include <iostream>
using namespace std;
class gfg {
	/* Function to get no of set bits in binary
representation of passed binary no. */
public:
	unsigned int countSetBits(int n)
	{
		unsigned int count = 0;
		while (n) {
			n &= (n - 1);
			count++;
		}
		return count;
	}
};
/* Program to test function countSetBits */
int main()
{
	gfg g;
	int i = 9;
	cout << g.countSetBits(i);
	return 0;
}

// Time Complexity: O(logn)
// Auxiliary Space: O(1)

// CPP implementation for recursive
// approach to find the number of set
// bits using Brian Kernighan’s Algorithm
#include <bits/stdc++.h>
using namespace std;

// recursive function to count set bits
int countSetBits(int n)
{
	// base case
	if (n == 0)
		return 0;
	else
		return 1 + countSetBits(n & (n - 1));
}

// driver code
int main()
{
	// get value from user
	int n = 9;

	// function calling
	cout << countSetBits(n);

	return 0;
}
// Time Complexity: O(logn)
// Auxiliary Space: O(1)