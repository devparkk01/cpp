/*Given an array A and an integer K. Find the minimum for each and every contiguous subarray of size K.
A[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13} , k = 4 
output : 5 

naive approach : brute force : time : O(n*k)
window sliding method : time : O(n) 

*/

#include<bits/stdc++.h>
using namespace std ; 


void minSubarrayK(int a[] , int n , int k ) {
	deque<int>q(k) ; 
	for(int i = 0 ; i < k  ; ++i ) {
		while(!q.empty() && a[q.back()] >= a[i]) {
			q.pop_back() ; 
		}
		q.push_back(i) ; 
	}

	for(int i = k ; i < n;  ++i ) {
		cout << a[q.front()] << " " ;
		if (q.front() == i - k ) q.pop_front() ; 
		while (!q.empty() && a[q.back()] >= a[i]) {
			q.pop_back() ; 
		}
		q.push_back(i) ; 
	}
	cout << a[q.front()] << endl; 
}


signed main () {
	int A[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13} ;
	int n = sizeof(A) /sizeof(int) ;
	int k = 4 ; 
	minSubarrayK(A,n, k ) ; 
	return 0 ; 
}