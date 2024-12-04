/*Given an array of integers (a[])  and a number x,
find the smallest subarray with sum greater than the given value.

A[] = {1, 4, 45, 6, 0, 19} ,  x  =  51
Output: 3 ,  subarray is {4, 45, 6}

A[] = {1, 10, 5, 2, 7} ,  x  = 9
Output: 1  ,  subarray is {10}

*/
// time : O(n) , space : O(1) 

#include<bits/stdc++.h>
using namespace std ; 

int smallestSubarray(int a[] , int n , int x ) {
	int minLen = INT_MAX ; int sum = 0 ;
	int l = 0 ; 
	for (int r = 0 ;r < n ; ++r) {
		sum+=a[r] ;

		while ( sum > x) {
			minLen = min(minLen , r-l+1) ; 
			sum-=a[l] ; 
			l++; // shrinking window 
		}
	}
	return minLen ; 
}

signed main () {
	int a[] = {1, 4, 45, 6, 0, 19} ; 
	int n = sizeof(a) / sizeof(int) ; 
	int x = 51 ; 
	cout << smallestSubarray(a , n , x) << endl;
	return 0 ; 
}