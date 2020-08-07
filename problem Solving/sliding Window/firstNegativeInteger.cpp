/*Given an array and a positive integer k, print the first negative integer for each and every 
window(contiguous subarray) of size k,in case a window does not contain any negative value print  0 .

a[]= {12 -1 -7 8 -15 30 16 28} , k = 3 
output : -1 -1 -7 -15 -15 0

*/

// naive approach , time : O(n*k) 
/* sliding window technique, time : O(n) , space : O(k)
*/

#include<iostream>
#include<queue>

using namespace std ; 

void firstNegativeInteger(int a[] , int n , int k ) {
	queue<int>q; // q stores all the negative elements in the current window being considered .
	for (int i = 0 ;i < k ; ++i ) {
		if (a[i] < 0 ) q.push(a[i]) ; // initializing q for the first window.  
	}
	for(int i = 0 ; i < n-k ; ++i ) {
		if ( !q.empty()) cout << q.front() << " " ; 
		else cout << "0 " ; 
		// prepare q for the next window . 
		if (a[i] < 0 ) q.pop() ;
		if (a[i+k] < 0 ) q.push(a[i+k]) ; 
	}
	if ( q.empty() ) cout << "0 " ; 
	else cout << q.front() << " " ; 
}

signed main () {
	int a[] = {12 , -1 , -7 , 8 , -15, 30 , 16 , 28} ; 
	int n = sizeof(a) / sizeof(int) ; 
	int k = 3; 
	firstNegativeInteger(a , n , k ) ;

	return 0 ;
}