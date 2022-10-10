#include <bits/stdc++.h>
using namespace std;

// Naive iterative solution to calculate pow(x, n)
long power(int x, unsigned n)
{
	// Initialize result to 1
	long long pow = 1;

	// Multiply x for n times
	for (int i = 0; i < n; i++) {
		pow = pow * x;
	}

	return pow;
}

// Driver code
int main(void)
{

	int x = 2;
	unsigned n = 3;

	// Function call
	int result = power(x, n);
	cout << result << endl;

	return 0;
}


// C++ program for Naive-Recursive Solution
#include <bits/stdc++.h>
using namespace std;

int power(int x, int n)
{
	// If x^0 return 1
	if (n == 0)
		return 1;
	// If we need to find of 0^y
	if (x == 0)
		return 0;
	// For all other cases
	return x * power(x, n - 1);
}

// Driver Code
int main()
{
	int x = 2;
	int n = 3;
	cout << (power(x, n));
}

// Binary Exponentiation
// Binary exponentiation (also known as exponentiation by squaring) is a trick which allows 
// to calculate a^n using only Log(N) multiplications 
// (instead of O(N) multiplications required by the naive approach).

// First the recursive approach, which is a direct translation of the recursive formula:

// Recursive
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

//Iterative
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
