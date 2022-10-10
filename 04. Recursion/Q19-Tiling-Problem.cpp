/*Given a “2 x n” board and tiles of size “2 x 1”, count the
number of ways to tile the given board using the 2 x 1 tiles.
 A tile can either be placed horizontally i.e., as a 
 1 x 2 tile or vertically i.e., as 2 x 1 tile. 

Examples: 
Input: n = 4
Output: 5

Explanation:
For a 2 x 4 board, there are 5 ways
All 4 vertical (1 way)
All 4 horizontal (1 way)
2 vertical and 2 horizontal (3 ways)
Input: n = 3

Output: 3

Explanation:

We need 3 tiles to tile the board of size  2 x 3.
We can tile the board using following ways
Place all 3 tiles vertically.
Place 1 tile vertically and remaining 2 tiles horizontally (2 ways)

Implementation -:

Let count(n) be the count of ways to place tiles on a “2 x n” grid, we have following two ways to place first tile. 
1) If we place first tile vertically, the problem reduces to “count(n-1)” 
2) If we place first tile horizontally, we have to place second tile also horizontally. So the problem reduces to “count(n-2)” 
Therefore, count(n) can be written as below. 

   count(n) = n if n = 1 or n = 2
   count(n) = count(n-1) + count(n-2) 
   */

  // C++ program to count the
// no. of ways to place 2*1 size
// tiles in 2*n size board.
#include <iostream>
using namespace std;

int getNoOfWays(int n)
{
	// Base case
	if (n <= 2)
	return n;

	return getNoOfWays(n - 1) + getNoOfWays(n - 2);
}

// Driver Function
int main()
{
	cout << getNoOfWays(4) << endl;
	cout << getNoOfWays(3);
	return 0;
}
