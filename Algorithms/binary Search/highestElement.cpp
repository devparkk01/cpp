/*Given an array in such a way that the elements stored in array are in increasing order
initially and then after reaching to a peak element , elements stored are in decreasing order.
(This is called a bitonic array)
Find the highest element.   Note: A[i] != A[i+1]
*/

#include<iostream>
#include<vector>
using namespace std ;

int highestElement(vector<int>&a )  {
	int n = a.size() ;
	int low = 0 , high = n - 1 ;
	int mid ;
	while ( low < high ) {
		mid = low + (high - low) / 2 ;
		if ( a[mid] < a[mid + 1 ]) low = mid + 1 ;
		else if ( a[mid] > a[mid + 1 ]) {
			high = mid ;
		}
	}
	return a[low] ;
}

int findMaximum(int arr[], int n) {
	// code here
	
	int low = 0, high = n -1, mid ;
	int ans = -1; 
	
	while ( low <= high) {
		mid = low + (high - low) / 2; 
		if ( arr[mid] > arr[mid - 1]) {
			ans = mid; 
			low = mid + 1; 
			
		} 
		else {
			high = mid -1; 
		}
	}
	return arr[ans]; 
	
}

signed main() {
	vector<int>a = { 2 , 3, 4, 5 , 8 , 4 , 1 } ;
	cout << highestElement(a) << endl;
	a = { 3 , 4 , 5 , 7 };
	cout << highestElement(a) << endl;
	return 0 ;
}