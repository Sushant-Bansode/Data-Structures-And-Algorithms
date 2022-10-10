// Recursive C++ program to count number of
// digits in a number
#include <bits/stdc++.h>
using namespace std;

int countDigit(long long n)
{
	if (n/10 == 0)
		return 1;
	return 1 + countDigit(n / 10);
}

// Driver code
int main(void)
{
	long long n = 345289467;
	cout << "Number of digits :" << countDigit(n);
	return 0;
}




