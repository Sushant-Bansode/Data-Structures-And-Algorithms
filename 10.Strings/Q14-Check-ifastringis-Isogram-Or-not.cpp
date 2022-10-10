/*
Check if a string is Isogram or not

Given a word or phrase, check if it is an isogram or not. 
An Isogram is a word in which no letter occurs more than once

Examples: 
Input: Machine
Output: True
Explanation: “Machine” does not have any character repeating, 
it is an Isogram

Input : Geek
Output : False
Explanation: “Geek” has ‘e’ as repeating character, it is not an Isogram
*/

// CPP code to check string is isogram or not
#include <bits/stdc++.h>

using namespace std;

// function to check isogram
bool check_isogram(string str)
{

	int length = str.length();
	int mapHash[26] = { 0 };

	// loop to store count of chars and check if it is
	// greater than 1
	for (int i = 0; i < length; i++) {
		mapHash[str[i] - 'a']++;

		// if count > 1, return false
		if (mapHash[str[i] - 'a'] > 1) {
			return false;
		}
	}

	return true;
}

// Driver code
int main()
{
	string str = "geeks";
	string str2 = "computer";

	// checking str as isogram
	if (check_isogram(str)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}

	// checking str2 as isogram
	if (check_isogram(str2)) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}

	return 0;
}


// C++ program to check
// If a given string is isogram or not
#include <bits/stdc++.h>
using namespace std;

// Function to check
// If a given string is isogram or not
string is_isogram(string str)
{
	int len = str.length();

	// Convert the string in lower case letters
	for (int i = 0; i < len; i++)
		str[i] = tolower(str[i]);

	sort(str.begin(), str.end());

	for (int i = 0; i < len; i++) {
		if (str[i] == str[i + 1])
			return "False";
	}
	return "True";
}

// Driver code
int main()
{
	string str1 = "Machine";

	// Function call
	cout << is_isogram(str1) << endl;

	string str2 = "isogram";

	// Function call
	cout << is_isogram(str2) << endl;

	string str3 = "GeeksforGeeks";

	// Function call
	cout << is_isogram(str3) << endl;

	string str4 = "Alphabet";

	// Function call
	cout << is_isogram(str4) << endl;

	return 0;
}



