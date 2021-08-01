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

vector<long long> printFirstNegativeInteger(long long A[], long long N, long long K) {
	vector<long long> ans ;
	queue<int>q;
	int i = 0 , j = 0 ;
	int window;
	while ( j < N) {
		window = j - i + 1 ;
		if (window < K) {
			if (A[j] < 0) q.push(j) ;
			j++ ;
		}
		else if (window == K ) {
			if (A[j] < 0) q.push(j) ;
			if (!q.empty()) {
				int front = q.front() ;
				ans.push_back(A[front]) ;
			}
			else ans.push_back(0) ;

			if (!q.empty() && q.front() == i) q.pop() ;
			i++ ; j++ ;
		}
	}

	return ans ;


}