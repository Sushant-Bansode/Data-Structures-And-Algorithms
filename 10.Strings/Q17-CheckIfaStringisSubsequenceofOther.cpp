/*
Given two strings, find if first string is a subsequence of second
Difficulty Level : Easy
Last Updated : 22 Jul, 2022
Read
Discuss

Given two strings str1 and str2, find if str1 is a subsequence of str2. A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements (source: wiki). The expected time complexity is linear.

Examples : 

Input: str1 = "AXY", str2 = "ADXCPY"
Output: True (str1 is a subsequence of str2)

Input: str1 = "AXY", str2 = "YADXCP"
Output: False (str1 is not a subsequence of str2)

Input: str1 = "gksrek", str2 = "geeksforgeeks"
Output: True (str1 is a subsequence of str2)
*/

// Recursive C++ program to check
// if a string is subsequence
// of another string
#include <cstring>
#include <iostream>
using namespace std;

// Returns true if str1[] is a
// subsequence of str2[]. m is
// length of str1 and n is length of str2
bool isSubSequence(char str1[], char str2[], int m, int n)
{

	// Base Cases
	if (m == 0)
		return true;
	if (n == 0)
		return false;

	// If last characters of two
	// strings are matching
	if (str1[m - 1] == str2[n - 1])
		return isSubSequence(str1, str2, m - 1, n - 1);

	// If last characters are
	// not matching
	return isSubSequence(str1, str2, m, n - 1);
}

// Driver program to check whether str1 is subsequence of str2 or not.
int main()
{
	char str1[] = "gksrek";
	char str2[] = "geeksforgeeks";
	int m = strlen(str1);
	int n = strlen(str2);
	isSubSequence(str1, str2, m, n) ? cout << "Yes "
									: cout << "No";
	return 0;
}

/*Iterative C++ program to check
If a string is subsequence of another string*/

#include <bits/stdc++.h>
using namespace std;

/*Returns true if s1 is subsequence of s2*/
bool issubsequence(string& s1, string& s2)
{
	int n = s1.length(), m = s2.length();
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (s1[i] == s2[j])
			i++;
		j++;
	}
	/*If i reaches end of s1,that mean we found all
	characters of s1 in s2,
	so s1 is subsequence of s2, else not*/
	return i == n;
}
int main()

{
	string s1 = "gksrek";
	string s2 = "geeksforgeeks";
	if (issubsequence(s1, s2))
		cout << "gksrek is subsequence of geekforgeeks" << endl;
	else
		cout << "gksrek is not a subsequence of geekforgeeks" << endl;
	return 0;
}
