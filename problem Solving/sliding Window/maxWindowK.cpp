/*Given an array A and an integer K. Find the maximum for each and every contiguous subarray of size K.
A[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13} , k = 4
output : 10 10 10 15 15 90 90

naive approach : brute force : time : O(n*k)
window sliding method : time : O(n)

*/

#include<bits/stdc++.h>
using namespace std;

vector<int>max_of_subarrays(int arr[], int n, int k)
{
	vector<int>ans ;
	int i = 0 , j = 0 ;
	int window ;
	deque<int>candidate ;
	while (j < n) {
		window = j - i + 1 ;
		if (window < k ) {
			while (!candidate.empty() && arr[candidate.back()] <= arr[j]) candidate.pop_back() ;
			candidate.push_back(j) ;
			j++ ;
		}
		else if (window == k ) {
			while (!candidate.empty() && arr[candidate.back()] <= arr[j]) candidate.pop_back() ;
			candidate.push_back(j) ;

			ans.push_back(arr[candidate.front()]) ;
			if (candidate.front() == i ) candidate.pop_front() ;
			i++ ; j++ ;

		}
	}

	return ans ;

}

signed main () {
	int A[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13} ;
	int n = sizeof(A) / sizeof(int) ;
	int k = 4 ;
	vector<int>ans = max_of_subarrays(A, n , k ) ;
	for (int &x : ans ) {
		cout << x << " " ;
	}
	return 0 ;
}