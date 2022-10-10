/*
Naive algorithm for Pattern Searching

Given a text of length N txt[0..N-1] and a pattern of 
length M pat[0..M-1], write a function search(char pat[], char txt[])
that prints all occurrences of pat[] in txt[]. 
You may assume that N > M.
Examples: 

Input:  txt[] = “THIS IS A TEST TEXT”, pat[] = “TEST”
Output: Pattern found at index 10

Input:  txt[] =  “AABAACAADAABAABA”, pat[] =  “AABA”
Output: Pattern found at index 0, Pattern found at index 9, Pattern found at index 12

*/

// C++ program for Naive Pattern
// Searching algorithm
#include <bits/stdc++.h>
using namespace std;

void search(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	/* A loop to slide pat[] one by one */
	for (int i = 0; i <= N - M; i++) {
		int j;

		/* For current index i, check for pattern match */
		for (j = 0; j < M; j++)
			if (txt[i + j] != pat[j])
				break;

		if (j
			== M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
			cout << "Pattern found at index " << i << endl;
	}
}

// Driver's Code
int main()
{
	char txt[] = "AABAACAADAABAAABAA";
	char pat[] = "AABA";

	// Function call
	search(pat, txt);
	return 0;
}


/*
Output
Pattern found at index 0 
Pattern found at index 9 
Pattern found at index 13 
*/