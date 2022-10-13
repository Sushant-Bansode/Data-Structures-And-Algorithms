Given a string, str, the task is to remove all the duplicate adjacent characters from the given string.

Examples:

Input: str= “azxxzy”
Output: ay 
Removal of “xx” modifies the string to “azzy”. 
Now, the removal of “zz” modifies the string to “ay”. 
Since the string “ay” doesn’t contain duplicates, the output is ay.

Input: “aaccdd”
Output: Empty String

// C++ program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to remove adjacent
// duplicate elements
string ShortenString(string str1)
{
	
	// Store the string without
	// duplicate elements
	stack<char> st;
	
	// Store the index of str
	int i = 0;
	
	// Traverse the string str
	while (i < str1.length())
	{
		
		// Checks if stack is empty or top of the
		// stack is not equal to current character
		if (st.empty() || str1[i] != st.top())
		{
			st.push(str1[i]);
			i++;
		}
			
		// If top element of the stack is
		// equal to the current character
		else
		{
			st.pop();
			i++;
		}
	}
	
	// If stack is empty
	if (st.empty())
	{
		return ("Empty String");
	}
		
	// If stack is not Empty
	else
	{
		string short_string = "";
		while (!st.empty())
		{
			short_string = st.top() +
						short_string;
			st.pop();
		}
		return (short_string);
	}
}

// Driver Code
int main()
{
	string str1 ="azzxzy";
	
	cout << ShortenString(str1);

	return 0;
}

