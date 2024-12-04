/*Given an array of 0s and 1s. Find the length of the largest subarray with equal number of 0s and 1s.
*/

/* Brute force technique would be to find all subarrays and count the number of 0s and 1s in each of them 
time : O(n*n )

*/

/* prefix sum + hashing 
Better solution is to hash the values 
time : O(n) , space : O(n)

*/

#include<iostream>
#include<unordered_map>

using namespace std ; 


int longestSubarray (int a[] , int n ) {
	unordered_map<int , int >indices ; // hashes the index where we have encountered each count for the first time . 
	int count = 0 ; // stores the relative number of 0's and 1's encountered so far 
	int maxLen = 0 ; // stores the max length of the subarray 
	indices[0] = -1 ; // initializing with 0 

	for (int i = 0 ;i < n; ++i ) {
		count+= (a[i] == 0 ) ? -1 : 1 ; 

		if (indices.find(count) != indices.end() ) {
			maxLen = max(maxLen , i - indices[count ]) ; 
		}
		else indices[count] = i ; 
	}
	return maxLen ; 

}


signed main () {
	int a[] = {1, 0 , 1, 1 ,0 , 1, 0 , 0 , 1, 1 } ; 
	int n = sizeof(a)/sizeof(int) ;

	cout << longestSubarray(a , n ) << endl; 

	return 0 ; 
}