/*Given an array A[] of size N, construct a Product Array P 
(of same size N) such that 
P[i] is equal to the product of all the elements of A except A[i].

Input:
N = 5
A[] = {10, 3, 5, 6, 2}
Output:
180 600 360 300 900
Explanation: 
For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.
	
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N) */

#include<bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>&, int );

int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        
        vec = productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}

vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
   
    vector<long long int>left(n); 
    vector<long long int>right(n); 
    left[0]=1;
    right[n-1]=1;
    for(int i=1;i<n;i++)
    {
        left[i]=left[i-1]*nums[i-1];
    }
    for(int i=n-2;i>=0;i--)
    {
        right[i]=right[i+1]*nums[i+1];
    }
    vector<long long int>ans(n); 
    for(int i=0;i<n;i++)
    {
        ans[i]=left[i]*right[i];
    }
    return ans;
    
}
