/*  Input:
r = 4, c = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10  */

void spiralOrderTraversal(int end_row, int end_col, int A[R][C]) 
{ 
  int i
  int start_row = 0
  int start_col = 0
   
  while(start_row < end_row && start_col < end_col)
  {
      for(i = start_col to end_col-1; i=i+1)
      {
         print(A[start_row][i])
      }   
      start_row = start_row + 1
      
      for(i = start_row to end_row-1; i=i+1)
      {
         print(A[i][end_col - 1])
      }
      end_col = end_col - 1
      
      if(start_row < end_row)
      { 
        for(i = end_col-1 to start_col; i=i-1) 
           print(A[end_row-1][i])
        end_row = end_row - 1
      } 
    
      if(start_col < end_col) 
      { 
        for(i = end_row-1 to start_row; i=i-1) 
           print(A[i][start_col]
        start_col = start_col + 1
     } 
  } 
}
/*
We are traversing and printing each element of the matrix once.

Time Complexity: O(R*C)(Here R refers to the number of rows and C refers to the number of columns in a matrix)

Space Complexity: O(1)
*/