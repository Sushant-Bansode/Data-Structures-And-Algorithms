// C program to check whether a number
// is Palindrome or not.
#include <stdio.h>
/* Iterative function to reverse digits of num*/
int reverseDigits(int num)
{
	int rev_num = 0;
	while (num > 0) {
		rev_num = rev_num * 10 + num % 10;
		num = num / 10;
	}
	return rev_num;
}

/* Function to check if n is Palindrome*/
int isPalindrome(int n)
{

	// get the reverse of n
	int rev_n = reverseDigits(n);

	// Check if rev_n and n are same or not.
	if (rev_n == n)
		return 1;
	else
		return 0;
}

/*Driver program to test reversDigits*/
int main()
{
	int n = 4562;
	printf("Is %d a Palindrome number? -> %s\n", n,
		isPalindrome(n) == 1 ? "true" : "false");

	n = 2002;
	printf("Is %d a Palindrome number? -> %s\n", n,
		isPalindrome(n) == 1 ? "true" : "false");
	return 0;
}


// C++ implementation for Palindrome String (For No. Convert to String then ViceVersa.)
#include <iostream>
using namespace std;

// Function to check palindrome
int checkPalindrome(string str)
{
	// Calculating string length
	int len = str.length();

	// Traversing through the string
	// upto half its length
	for (int i = 0; i < len / 2; i++) {
	
		// Comparing i th character
		// from starting and len-i
		// th character from end
		if (str[i] != str[len - i - 1])
			return false;
	}

	// If the above loop doesn't return then it is
	// palindrome
	return true;
}

// Driver Code
int main()
{ // taking number as string
	string st
		= "112233445566778899000000998877665544332211";
	if (checkPalindrome(st) == true)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
