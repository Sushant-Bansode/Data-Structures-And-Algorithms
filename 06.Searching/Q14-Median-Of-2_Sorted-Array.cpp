/*
Given two sorted arrays, a[] and b[], the task is to find the median of 
these sorted arrays, in O(log n + log m) time complexity, when n is 
the number of elements in the first array, and m is the number of 
elements in the second array. 
This is an extension of median of two sorted arrays of equal 
size problem. Here we handle arrays of unequal size also.

Example: 

Input: ar1[] = {-5, 3, 6, 12, 15}
        ar2[] = {-12, -10, -6, -3, 4, 10}
Output : The median is 3.
Explanation : The merged array is :
        ar3[] = {-12, -10, -6, -5 , -3,
                 3, 4, 6, 10, 12, 15},
       So the median of the merged array is 3

Input: ar1[] = {2, 3, 5, 8}
        ar2[] = {10, 12, 14, 16, 18, 20}
Output : The median is 11.
Explanation : The merged array is :
        ar3[] = {2, 3, 5, 8, 10, 12, 14, 16, 18, 20}
        if the number of the elements are even, 
        so there are two middle elements,
        take the average between the two :
        (10 + 12) / 2 = 11.

*/

#include <bits/stdc++.h>
using namespace std;

// Method to find median Using Binary Search
double Median(vector<int>& A, vector<int>& B)
{
	int n = A.size();
	int m = B.size();
	if (n > m)
		return Median(B, A); // Swapping to make A smaller

	int start = 0;
	int end = n;
	int realmidinmergedarray = (n + m + 1) / 2;

	while (start <= end) {
		int mid = (start + end) / 2;
		int leftAsize = mid;
		int leftBsize = realmidinmergedarray - mid;
		int leftA
			= (leftAsize > 0)
				? A[leftAsize - 1]
				: INT_MIN; // checking overflow of indices
		int leftB
			= (leftBsize > 0) ? B[leftBsize - 1] : INT_MIN;
		int rightA
			= (leftAsize < n) ? A[leftAsize] : INT_MAX;
		int rightB
			= (leftBsize < m) ? B[leftBsize] : INT_MAX;

		// if correct partition is done
		if (leftA <= rightB and leftB <= rightA) {
			if ((m + n) % 2 == 0)
				return (max(leftA, leftB)
						+ min(rightA, rightB))
					/ 2.0;
			return max(leftA, leftB);
		}
		else if (leftA > rightB) {
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	return 0.0;
}

// Driver code
int main()
{
	vector<int> arr1 = { -5, 3, 6, 12, 15 };
	vector<int> arr2 = { -12, -10, -6, -3, 4, 10 };
	cout << "Median of the two arrays are" << endl;
	cout << Median(arr1, arr2);
	return 0;
}


// C++ program for the Naive approach
#include <bits/stdc++.h>
using namespace std;

int Solution(int arr[], int n)
{

	// If length of array is even
	if (n % 2 == 0)
	{
	int z = n / 2;
	int e = arr[z];
	int q = arr[z - 1];
	int ans = (e + q) / 2;
	return ans;
	}
	
	// If length if array is odd
	else
	{
	int z = round(n / 2);
	return arr[z];
	}
}

// Driver Code
int main() {
	
		// TODO Auto-generated method stub
		int arr1[] = { -5, 3, 6, 12, 15 };
		int arr2[] = { -12, -10, -6, -3, 4, 10 };

		int i = sizeof(arr1) / sizeof(arr1[0]);
		int j = sizeof(arr2) / sizeof(arr2[0]);

		int arr3[i+j];
		int l = i+j;
		// Merge two array into one array
		for(int k=0;k<i;k++)
		{
			arr3[k]=arr1[k];
		}
		
		int a=0;
		for(int k=i;k<l;k++)
		{
			arr3[k]=arr2[a++];
		}

		// Sort the merged array
		sort(arr3,arr3+l);

		// calling the method
		cout<<"Median = " << Solution(arr3, l);
}

