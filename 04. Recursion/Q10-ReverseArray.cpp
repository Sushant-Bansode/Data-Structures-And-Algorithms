// REVERSE An ARRAY USING RECURSION.

#include <iostream>
using namespace std;

 void rev(int *arr, int n ){
  if( n == 0 )
  return;
  cout << arr[n-1] << " ";
  rev(arr, n-1 );
 }

int main() {
  int t;
  cin >> t;
  while(t--){
      int n;
      cin >> n;
      int arr[n];
      for(int i = 0; i<n;++i){
          cin >> arr[i];
      }
 rev(arr,n);     
  }
	return 0;
}