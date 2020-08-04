/* prefix sum algorithm  
It's a nice algorithm . Given an array , we produce another array ,sum , such that 
sum[i] = arr[0] + arr[1] + arr[2] + ... arr[i-1] +arr[i] ;
*/

#include<iostream>
using namespace std ; 


int main () {
	int arr[] = {2, 3 , 2, -1  , -10 , 4, -3 , 9,12 } ; 
	int n= sizeof( arr) / sizeof(int) ; 

	int sum[n] ; sum[0] = arr[0] ; 
	for (int i = 1 ; i < n ; ++i ) {
		sum[i] = sum[i-1] + arr[i] ; 
	}
	for (int i = 0 ;i < n ; ++i ) {
		cout << sum[i] << " " ; 
	}
	cout << endl; 

// sum of the elements of arr between index 2 and 6 (both inclusive ) will be sum[6] - sum[1] 
// sum[6]:sum of the elements of arr till sixth index,sum[1]:sum of the elements of arr till 1st index.
// so , sum[6] - sum[1] = arr[2] + arr[3] + arr[4] + arr[5] + arr[6]

	cout << "Sum of elements of arr between(2, 6) : " << sum[6] - sum[1] << endl; 
	cout << "Sum of elements of arr between(4, 7) : " << sum[7] - sum[3] << endl;  
	cout << "Sum of elements of arr till(5) : " << sum[5] << endl; 


	cout << endl; 


	return 0; 
}