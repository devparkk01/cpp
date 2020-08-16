/*Given an array A and an integer K. Find the maximum for each and every contiguous subarray of size K.
A[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13} , k = 4 
output : 10 10 10 15 15 90 90

naive approach : brute force : time : O(n*k)
window sliding method : time : O(n) 

*/

#include<bits/stdc++.h>
using namespace std; 

void maxSubarrayK (int A[] , int n , int k ) {
	deque<int>q(k) ; 
	for(int i = 0 ;i < k ; ++i ) {
		while(!q.empty() && A[i] >= A[q.back()] ) {
			q.pop_back() ; 
		}
		q.push_back(i) ; 
	}
	for(int i = 0 ; i < n-k; ++i ) {
		cout << A[q.front()] << " " ;
	// ----------sliding the window  ----------
		// removing first element from the window 
		if( q.front() == i) q.pop_front() ; 
		// adding new element into the window 
		while(!q.empty() && A[i+k] >= A[q.back()]) {
			q.pop_back() ; 
		}
		q.push_back(i+k) ; 
	}
	cout << A[q.front()] << endl; 
}

signed main () {
	int A[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13} ;
	int n = sizeof(A) /sizeof(int) ;
	int k = 4 ; 
	maxSubarrayK(A,n , k ) ; 
	return 0 ; 
}