/*Given an array A[] consisting 0s, 1s and 2s.The task is to write a function that sorts the given array.
Also called dutch flag problem . 
*/

#include<iostream>

using namespace std ; 

// first approach : sort the array ; time: O(nlogn), space : O(1)
// second approach : count the no of 0s , 1s and 2s (counting sort ), time : O(n) , space : O(1)

// third approach 
/*
Keep three variables :  low , mid , high .

arr[0]---arr[low-1] - > 0's
arr[low]--- arr[mid-1] -> 1's
arr[mid] --- arr[high] -> unknown
arr[high+1] --- arr[n-1] -> 2's 

time : O(n) , space : O(1)
*/

void sort (int arr[] , int n ) {
	int low = 0 ; int mid = 0 ; int high = n-1 ; 
	while ( mid <= high ) {
		if (arr[mid] == 0 ) {
 			swap(arr[mid] , arr[low]) ; 
			low++ ; mid++ ; 
		}
		else if ( arr[mid] == 2 ) {
			swap(arr[mid] , arr[high]); 
			high--;  
		}
		else if ( arr[mid] == 1 ) {
			mid++ ; 
		}
	}
}

void print(int arr[] ,int n ) {
	for (int i = 0 ;i < n; ++i ) {
		cout << arr[i] << " " ; 
	}
	cout << endl; 
}


int main () {
	int arr[] = {2 , 1, 1 , 2 , 1, 1, 0 , 0 , 1, 1, 2, 1, 0 , 0 ,0 } ; 
	int n = sizeof( arr) / sizeof ( int ) ; 

	print(arr , n ) ; 
	sort( arr , n ) ; 
	print ( arr , n ) ; 


	return 0 ; 

}