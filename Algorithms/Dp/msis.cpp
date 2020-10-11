/*Given an array of n positive integers. Write a program to find the sum of maximum sum 
subsequence of the given array such that the integers in the subsequence are sorted in
increasing order

time : O(n*n) , space : O(n)

*/

#include<bits/stdc++.h>
using namespace std ; 

int MSIS(int arr[] , int n ) {
	if ( n == 0 ) return 0 ; 
	int msis[n] = {0} ;//msis[i] stores the sum of increasing subsequence with max sum ending at ith index.
	int maxSum ;

	for(int i = 0 ; i < n; ++i ) {
		maxSum = 0 ; 
		// find the increasing subsequence with max sum ending at jth index where arr[j] < arr[i]
		for(int j = 0 ; j < i ; ++j ) {
			if( arr[j] < arr[i]) { //since, we want increasing subsequence 
				maxSum = max(maxSum , msis[j]) ; 
			}
		}
		msis[i] = maxSum + arr[i] ; // add the current element 
	}

	return *max_element(msis, msis+n) ; 
}


signed main() {

	int arr[] = {1, 101 , 2, 3 , 100 , 4 , 5 } ; 
	int n = sizeof( arr) / sizeof(arr[0]) ; 
	cout << MSIS(arr, n ) << endl; 


	return 0 ; 
}