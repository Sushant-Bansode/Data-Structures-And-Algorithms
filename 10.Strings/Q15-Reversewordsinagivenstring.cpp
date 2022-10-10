/*
Let the input string be “i like this program very much”. 
The function should change the string to 
“much very program this like i”
*/

// C++ program to reverse a string
#include <bits/stdc++.h>
using namespace std;

// Function to reverse words*/
void reverseWords(string s)
{
	
	// temporary vector to store all words
	vector<string> tmp;
	string str = "";
	for (int i = 0; i < s.length(); i++)
	{
		
		// Check if we encounter space
		// push word(str) to vector
		// and make str NULL
		if (s[i] == ' ')
		{
			tmp.push_back(str);
			str = "";
		}

		// Else add character to
		// str to form current word
		else
			str += s[i];
	}

	// Last word remaining,add it to vector
	tmp.push_back(str);

	// Now print from last to first in vector
	int i;
	for (i = tmp.size() - 1; i > 0; i--)
		cout << tmp[i] << " ";
	// Last word remaining,print it
	cout << tmp[0] << endl;
}

// Driver Code
int main()
{
	string s = "i like this program very much";
	reverseWords(s);
	return 0;
}

// C program to reverse a string
#include <stdio.h>

// Function to reverse any sequence
// starting with pointer begin and
// ending with pointer end
void reverse(char* begin, char* end)
{
	char temp;
	while (begin < end) {
		temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}
}

/*Time complexity: O(N)
Auxiliary Space: O(N)

The above code doesn’t handle the cases when the string starts with space.
 The following version handles this specific case and doesn’t make
  unnecessary calls to reverse function in the 
  case of multiple spaces in between.
*/
// C program for above approach
void reverseWords(char* s)
{
	char* word_begin = NULL;

	// /* temp is for word boundary */
	char* temp = s;

	/*STEP 1 of the above algorithm */
	while (*temp)
	{

		/*This condition is to make sure that the
		string start with valid character (not
		space) only*/
		if ((word_begin == NULL) &&
				(*temp != ' '))
		{
			word_begin = temp;
		}
		if (word_begin && ((*(temp + 1) == ' ') ||
			(*(temp + 1) == '\0')))
		{
			reverse(word_begin, temp);
			word_begin = NULL;
		}
		temp++;
	} /* End of while */

	/*STEP 2 of the above algorithm */
	reverse(s, temp - 1);
}

// Driver Code
int main()
{
	char s[] = "i like this program very much";
	char* temp = s;
	reverseWords(s);
	printf("%s", s);
	return 0;
}
