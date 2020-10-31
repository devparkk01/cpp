#include<iostream>
using namespace std ; 

int binarySearch (int arr[] , int n ,int key) {
	int low = 0 ; int high = n-1 ; 
	while ( low <= high ) {
		int mid = low + (high - low) / 2 ; 
		if (arr[mid] == key ) return mid ; 
		if ( arr[mid] < key ) low = mid + 1 ; 
		else high = mid-1 ; 
	}
	return -1  ;
}

signed main() {
	int arr[]= {2 , 3, 5 ,8 ,9 ,11 } ;
	int n = sizeof(arr)/sizeof(int ); 
	int key = 18 ;
	cout << binarySearch(arr, n , key ) ;
	return 0 ; 
}