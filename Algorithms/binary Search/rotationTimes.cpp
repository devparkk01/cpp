/*Given an ascending sorted rotated array Arr of distinct integers of size N. The array is 
right rotated K times. Find the value of K.

Arr[] = {5, 1, 2, 3, 4}  ,  Output: 1
Arr[] = {4 ,5, 1 , 2 ,3 }  , output : 2 
Arr[] = { 1 , 2 , 4 } , out put : 0 ; 

The idea is to find the index of the minimum element in this array.This will be our final answer
*/

#include<iostream>
#include<vector>
using namespace std ; 


int findMinIndex(vector<int>&a) {
	int n= a.size() ; int low = 0 , high = n-1 ; int mid ; 
	while (low <= high ) {
		mid = low + (high - low ) /2 ; 
		if (a[mid] > a[mid + 1 ]) return mid + 1 ; 
		else if( a[mid] < a[mid - 1 ]) return mid ; 
		else if( a[mid] > a[0]) low = mid + 1 ; 
		else if (a[mid] < a[0])  high = mid- 1 ; 
	}
	return -1 ; // just for returning purpose 
}


int rotationTimes(vector<int>&a ) {
	int n = a.size() ;
	if (n == 1 ) return 0 ;  // no need to check if there is only one element 
	if ( a[0] < a[n-1 ]) return 0 ; // array is sorted already (no rotation)
	// find the index of minimum element in this array

	int index = findMinIndex (a) ;
	return index ; 
}


signed main () {
	vector<int>a = { 4 , 5 , 1 ,2 ,3 } ; 
	cout << rotationTimes(a ) << endl; 

	return 0 ; 
}