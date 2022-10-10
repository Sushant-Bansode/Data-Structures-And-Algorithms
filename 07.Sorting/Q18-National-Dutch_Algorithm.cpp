/*
The Dutch national flag (DNF) problem is 
one of the most popular programming problems proposed by Edsger Dijkstra.
The flag of the Netherlands consists of three colors: white, red, 
and blue. The task is to randomly arrange balls of white, red, and
blue such that balls of the same color are placed together.

Consider this problem on an array; the task is to sort arrays of 0, 1, 
and 2 in linear time without any extra space. Since the array is only
traversed once, the time complexity of the algorithm given below is O(n).

Note: this algorithm can be implemented on an array that has three 
unique elements.
*/

// C++ program to sort an array  
#include<bits/stdc++.h>  
using namespace std;  

// Function to sort the input array, 
// the array is assumed  
// to have values in {0, 1, 2}  
void DNFS(int arr[], int arr_size)  
{  
    int low = 0;  
    int high = arr_size - 1;  
    int mid = 0;  
      
    // Iterate till all the elements 
    // are sorted  
    while (mid <= high)  
    {  
        switch (arr[mid])  
        {  
              
            // mid is 0  
        case 0:  
            swap(arr[low++], arr[mid++]);  
            break;  
              
            // mid is 1 .  
        case 1:  
            mid++;  
            break;  
              
            // mid is 2  
        case 2:  
            swap(arr[mid], arr[high--]);  
            break;  
        }  
    }  
}  
  
  
  
// Function to print array arr[]  
void printArray(int arr[], int arr_size)  
{  
    // Iterate and print every element  
    for (int i = 0; i < arr_size; i++)  
        cout << arr[i] << " ";  
  
}  
  
// Driver Code  
int main()  
{  
    int arr[] = {0,0,1,2,0,1,2};  
    int n = sizeof(arr)/sizeof(arr[0]);  

    cout << "Array before running the algorithm: ";  
      
    printArray(arr, n);   
    
    DNFS(arr, n);  
  
    cout << "\nArray after DNFS algorithm: ";  
      
    printArray(arr, n);  
  
    return 0;  
}  