/*
 // TIME COMPLEXITIES -: Time Complexity: The time complexity of an 
 algorithm quantifies the amount of time taken by an algorithm 
 to run as a function of the length of the input. No
 te that the time to run is a function of the length 
 of the input and not the actual execution time of the 
 machine on which the algorithm is running on.

 O(n)
 // Here c is a constant
for (int i = 1; i <= c; i++) {
    // some O(1) expressions
}
 
 O(n^2)
 for (int i = 1; i <= n; i += c) {
    for (int j = 1; j <= n; j += c) {
        // some O(1) expressions
    }
}
 
for (int i = n; i > 0; i -= c) {
    for (int j = i + 1; j <= n; j += c) {
        // some O(1) expressions
    }
 
 O(Logn)
 for (int i = 1; i <= n; i *= c) {
    // some O(1) expressions
}
for (int i = n; i > 0; i /= c) {
    // some O(1) expressions
}
// Recursive function
void recurse(n)
{
    if (n == 0)
        return;
    else {
        // some O(1) expressions
    }
    recurse(n - 1);
}

O(Log(Logn))
// Here c is a constant greater than 1
for (int i = 2; i <= n; i = pow(i, c)) {
    // some O(1) expressions
}
// Here fun is sqrt or cuberoot or any other constant root
for (int i = n; i > 1; i = fun(i)) {
    // some O(1) expressions
}

Algorithm	   Best Case	Average Case	Worst Case
Selection Sort  	O(n^2)	O(n^2)	O(n^2)
Bubble Sort	         O(n)  O(n^2)	O(n^2)
Insertion Sort	     O(n)  O(n^2)   O(n^2)
Tree Sort	       O(nlogn)	O(nlogn) O(n^2)
Radix Sort	         O(dn)	O(dn)	O(dn)
Merge Sort	       O(nlogn)	O(nlogn)	O(nlogn)
Heap Sort	       O(nlogn)	O(nlogn)	O(nlogn)
Quick Sort	       O(nlogn)	O(nlogn)	O(n^2)
Bucket Sort	          O(n+k)	O(n+k)	O(n^2)
Counting Sort	      O(n+k)	O(n+k)	O(n+k)


Input Length Worst Accepted Time Complexity	
Usually type of solutions
10 -12
O(N!)
Recursion and backtracking

15-18
O(2N * N)
Recursion, backtracking, and bit manipulation

18-22
O(2N * N)
Recursion, backtracking, and bit manipulation

30-40
O(2N/2 * N)	
Meet in the middle, Divide and Conquer

100
O(N4)
Dynamic programming, Constructive

400
O(N3)
Dynamic programming, Constructive

2K
O(N2* log N)
Dynamic programming, Binary Search, Sorting, 
Divide and Conquer

10K
O(N2)
Dynamic programming, Graph, Trees, Constructive

1M
O(N* log N)
Sorting, Binary Search, Divide and Conquer

100M
O(N), O(log N), O(1)
Constructive, Mathematical, Greedy Algorithms

Space Complexity: The space complexity of an algorithm quantifies the 
amount of space taken by an algorithm to run as a function of the 
length of the input.

There is also auxiliary space, which is different from space complexity. 
The main difference is where space complexity quantifies 
the total space used by the algorithm, auxiliary space quantifies 
the extra space that is used in the algorithm apart from the given input.

*/
