/* Given an array a[] of N positive and negative numbers. 
 Find if there is a subarray (of size at-least size one) with 0 sum. 

a[] = {4 2 -3 1 6 }  output : Yes
a[] = {6 , -5 , 3 , -2} ouput : No

*/

/* brute force :time :  O(n*n) */
/*Second method is prefix sum + hashing. 
This question is similar to the question where we are given an array of 0's and 1's and we have to find the 
largest subarray having equal no of 0's and 1's. 
Think in what way this question is similar to that . 

*/
#include<bits/stdc++.h> 
using namespace std; 

void subarray(int A[] , int n ) {
	unordered_set<int>uset ; 
	uset.insert(0) ; // initialising with 0 
	int prefixSum = 0 ; 

	for(int i = 0 ; i < n; ++i ) {
		prefixSum+=A[i] ; 

		if ( uset.find(prefixSum) != uset.end() ) {
			cout << "Yes" << endl; 
			return; 
		}
		uset.insert(prefixSum) ; 
	}
	cout << "No" << endl; 
}


//  length of the largest subarray with sum 0.
/* This part is almost similar to above mentioned problem which contains array of 0's and 1's */

int subarrayLargestLength(int A[] , int n ) {
	unordered_map<int, int > indices ;
	//indices stores the index where we encountered each prefixSum for the first time 
	int prefixSum = 0 ; 
	int maxLen = 0 ; 
	indices[0] = -1 ; //initializing 

	for(int i = 0 ;i < n; ++i ) {
		prefixSum+=A[i] ; 

		if ( indices.find(prefixSum) != indices.end()) {
			maxLen = max(maxLen , i - indices[prefixSum]) ; 
		}
		else indices[prefixSum] = i ; 
	}
	return maxLen  ;
}



//  total count of sub-arrays having their sum equal to 0
/* It's a little bit different . 
A[] = {0 0 5 5 0 0} ,  total subarrays = 6  
A[] = {6  -1 -3 4 -2 2 4 6 -12 -7} ,  total subarrays = 4

*/

int subarrayCount (int A[] , int n ) {
	unordered_map<int , int > counts; 
	int prefixSum = 0 ; 
	int total = 0 ; // stores no of subarrays 
	counts[0] = 1; 
	
	for(int i = 0 ; i < n ; ++i ) {
		prefixSum+=A[i] ; 

		if (counts.find(prefixSum) != counts.end() ) {
			total+=(counts[prefixSum]) ; 
		}
		counts[prefixSum]++ ; 
	}
	return total ; 

}



int main () {
	int A[] = {15 , -2 , 2,  -8, 1, 7, 10 ,23} ;
	// int A[] = {6 , -1 ,-3 ,4 ,-2 ,2 ,4 ,6 ,-12 ,-7}; 
	int n = sizeof(A) /sizeof(int)  ; 

	subarray(A , n ) ; 
	cout << "Length of the largest subarray : " << subarrayLargestLength(A , n ) << endl; 
	cout << "Total subarray count : " << subarrayCount(A , n ) << endl; 

	return 0 ; 
}