/*
Given an array of integers of size ‘n’.Our aim is to calculate the maximum sum of ‘k’ 
consecutive elements in the array.
first technique would be to use brute force . That'll take O(n * k) time . 
Second technique is sliding window technique which takes O(n) time . 

*/

#include<bits/stdc++.h> 
using namespace std ; 
int maxKSum ( int arr[] , int n , int k ) {
	int windowSum = 0  ; 
	for (int i = 0 ; i < k ; ++i ) {
		windowSum+=arr[i] ; 
	}
	int maxSum = windowSum ; 
	for (int i = k ; i < n; ++i ) {
		windowSum += (arr[i] - arr[i-k]) ; 
		maxSum = max(maxSum , windowSum) ; 
	}
	return maxSum ; 
}



int main () {
	int arr[] = {4,5,-1, 0, -3, 2, 3, 5 }; 
	int n = sizeof ( arr) /sizeof ( int ) ;
	int k = 3 ; 
	cout << maxKSum(arr , n , k ) << endl ; 
	return 0 ; 
}