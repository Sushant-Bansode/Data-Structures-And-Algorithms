// Just switch the 2 lines (Recursion Calling and Printing) for N to 1. 
// -> This Topic Leads to Tail recursion. 
// C++ program to How will you print
// numbers from 1 to 100 without using a loop?
#include <iostream>
using namespace std;

class gfg
{
	
// It prints numbers from 1 to n.
public:
void printNos(unsigned int n)
{
	if(n > 0)
	{
		printNos(n - 1);
		cout << n << " ";
	}
	return;
}
};

// Driver code
int main()
{
	gfg g;
	g.printNos(100);
	return 0;
}

// C++ program
#include <bits/stdc++.h>
using namespace std;

void printNos(int initial, int last)
{
	if (initial <= last) {
		cout << initial << " ";
		printNos(initial + 1, last);
	}
}

int main()
{
	printNos(1, 100);
	return 0;
}


