/*Given an array containing N integers and a positive integer K. The task is to find the 
length of the longest sub array with sum of the elements divisible by the given value K.
A[] = {-2 2 -5 12 -11 -1 7} , k = 3 
output : 5  { 2 , -5 , 12 , -11 , -1 } 
*/ 

/*first technique : brute force , time :O(n*n)
second technique : prefix sum + hashing , time : O(n)

*/

#include<bits/stdc++.h>
using namespace std ;


//One important property:remainder is always non-negative.quotient can be negative.But remainder can't.  

int subarrayLargest(int A[] , int n , int k ) {
	unordered_map<int, int > indices ; 
	int maxLen  = 0 ; 
	int prefixSum = 0 ; 
	indices[0] = -1 ; 
	for(int i = 0; i < n; ++i ) {
		prefixSum+=(A[i] % k) ; 
		prefixSum = (prefixSum + k )% k ; // This is very important 
		// This is to make negative ramainders positive . 

		if (indices.find(prefixSum)!= indices.end() ) {
			maxLen = max(maxLen , i - indices[prefixSum]) ;
		}
		else indices[prefixSum] = i ; 
	}
	return maxLen ; 
}

// count the number of subarrays 
int subarrayCount (int A[] ,int n , int k ) {
	unordered_map<int, int>counts ; 
	int total = 0 ; 
	int prefixSum = 0 ; 
	counts[0] = 1 ; 

	for(int i = 0 ;i < n; ++i ) {
		prefixSum+=(A[i]%k ) ; 
		prefixSum = (prefixSum + k ) % k ; 

		if( counts.find(prefixSum) != counts.end()) {
			total+=(counts[prefixSum])  ; 
		}
		counts[prefixSum]++ ; 
	}
	return total  ; 
}

signed main () {
	int A[] = {-2,2 ,-5, 12 , -11, -1, 7} ; 
	int n = sizeof(A)/ sizeof(int ) ; 
	int k = 3 ; 
	cout << "Largest subarray length : " << subarrayLargest(A , n, k ) << endl; 
	cout << "Total subarrays : " << subarrayCount(A , n , k ) << endl; 

	return 0 ; 

}


