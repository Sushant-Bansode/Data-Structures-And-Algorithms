/*Given two matrices A and B having (n1 x m1) and (n2 x m2) dimensions
 respectively. Add A and B. 

Input:
n1 = 2, m1 = 3
A[][] = {{1, 2, 3},
         {4, 5, 6}}

n2 = 2, m2 = 3
B[][] = {{1, 3, 3},
         {2, 3, 3}}

Output: 2 5 6 6 8 9
Explanation:
The summation matrix of A and B is:
res[][] = {{2, 5, 6},
           {6, 8, 9}}
The output is generated by traversing each
row sequentially.

Expected Time Complexity: O(n1 * m1)
Expected Auxiliary Space: O(n1 * m1) for the resultant matrix only.

vector:: assign() is an STL in C++ which assigns new values to the vector 
elements by replacing old ones. It can also modify the size of the vector if necessary.

The syntax for assigning constant values: 

vectorname.assign(int size, int value)

Parameters: 
size - number of values to be assigned
value - value to be assigned to the vectorname 
*/

#include <bits/stdc++.h> 
using namespace std; 

class Solution
{   
public:
    vector<vector<int> > sumMatrix( const vector<vector<int> >& A, const vector<vector<int> >& B)
    {
        int n1 = A.size();
        int m1 = A[0].size();
        int n2 = B.size();
        int m2 = B[0].size();
        vector<vector<int> > result;
        if(n1 == n2 && m1 == m2)
        {
            result.resize(n1);
            for(int i=0; i<n1; i++){
                result[i].assign(m1,0);
                for(int j=0; j<m1; j++)
                    result[i][j] = A[i][j] + B[i][j];
            }
        }
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > A(row); 
        for(int i=0; i<row; i++)
        {
            A[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>A[i][j];
            }
        }
        cin>> row>> col;
        vector<vector<int> > B(row);
        for(int i=0; i<row; i++)
        {
            B[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>B[i][j];
            }
        }
        Solution ob;
        vector<vector<int> > result = ob.sumMatrix(A,B);
        if(result.size() == 0)
            cout<<"-1";
        else
        {
            for (int i = 0; i < result.size(); ++i)
            {
                for (int j = 0; j < result[0].size(); ++j)
                {
                    cout<<result[i][j]<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
