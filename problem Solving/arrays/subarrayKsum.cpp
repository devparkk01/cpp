/*Given an unsorted array arr[] of N integers and a sum. 
The task is to count the number of subarrays which add to a given number.

A[] = {10 2 -2 -20 10} , sum = -10
output :  3
A[] = { 1 4 20 3 10 5 }  sum = 33 
output : 1

*/
// first technique is to use brute force : O(n*n) 

//  Second technique is to use prefix sum + hashing 

#include<bits/stdc++.h>

using namespace std ; 

int subarrayCount(int A[] , int n , int sum ) {
	unordered_map<int ,int > counts ; 
	int prefixSum = 0 ;
	int total = 0 ; 
	counts[0] = 1 ; 

	for(int i = 0 ; i < n; ++i ) {
		prefixSum+=A[i] ;

		if (  counts.find(prefixSum - sum ) != counts.end() ) {
			total+=counts[prefixSum - sum] ; 
		}
		counts[prefixSum]++ ; 
	}
	return total;  
}
// finding the largest length of the subarray 

int subarrayLargestLength (int A[] , int n , int sum ) {
	unordered_map<int , int > indices ; 
	int prefixSum = 0 ; 
	int maxLen = 0  ;
	indices[0] = -1 ; 
	for(int i = 0 ; i< n ;++i ) {
		prefixSum+=A[i] ;

		if( indices.find(prefixSum - sum ) != indices.end() ) {
			maxLen = max(maxLen , i - indices[prefixSum - sum ]) ; 
		}
		if (indices.find(prefixSum) == indices.end() ) 
				indices[prefixSum] = i ; 
	}
	return maxLen ; 
}



signed main() {
	int A[] = {10 , 2 , -2 , -20 , 10}  ; 
	// int A[] = { 1 , 4 , 20 , 3, 10 , 5} ;
	int n = sizeof(A) /sizeof(int ) ; 
	int sum = -10 ; 

	cout<< "Total count of the subarray : " <<  subarrayCount(A , n , sum) << endl ; 
	cout << "Largest length of the subarray : " << subarrayLargestLength(A , n , sum) << endl; 
	return 0 ; 
}