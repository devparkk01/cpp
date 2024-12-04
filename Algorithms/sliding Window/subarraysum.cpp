/*Given an unsorted array A of size N of non-negative integers, find a continuous 
sub-array which adds to a given number S.

*/

/* brute force ,check all subarray , time : O(n*n)*/
/* second technique : sliding window , time : O(n) */


#include<iostream>
using namespace std ; 


/*This function prints only first subarray that adds up to sum  */
void subarraySum(int a[] ,int n ,  int sum) {
	int curSum = 0 ; 
	int l = 0 ; // l : left index of the window 
	for (int r = 0 ;r < n ; ++r ) {// r : right index of the window 
		curSum+=a[r] ;

		while ( curSum > sum ) {
			curSum-=a[l] ; 
			l++ ; 
		}
		if ( curSum == sum ) {
			while (l <= r ) {
				cout << a[l] << " " ; 
				l++ ; 
			}
			cout << endl ; 
			break ; 
		}
	}
}

// This function prints all subarrays satisfying the criteria 
void subarraySumAll (int a[] , int n , int sum ) {
	int curSum = 0 ; 
	int l = 0 ; 
	for (int r=0 ;r < n ; ++r) {
		curSum+=a[r] ;

		while (curSum > sum) {
			curSum-=a[l] ;
			l++ ; 
		}
		if ( curSum == sum) {
			int index = l ;
			while ( index <= r ) {
				cout << a[index] << " " ; 
				index++ ; 
			}
			cout << endl ; 
		}
	}
}

// This function gives the length of the largest subarray 
void subarraySumLargest(int a[] , int n , int sum) {
	int curSum = 0 ; int l = 0 ; 
	int maxLen = 0 ; 

	for(int r = 0 ; r < n ; ++r) {
		curSum+=a[r] ; 

		while(curSum > sum ) {
			curSum-=a[l] ; 
			l++ ; 
		}
		if ( curSum == sum ) {
			maxLen = max(maxLen , r-l+1) ; 
		}
	}
	cout << maxLen << endl; 
}


signed main () {
	int a[] = {2 ,3 ,4, 6, 7, 9, 8, 10 , 5} ;
	int n = sizeof(a)/sizeof(int) ; 
	int sum = 15 ; 
	cout << "First subarray : " << endl; 
	subarraySum(a , n , sum ) ; 
	cout << "All subarrays : " << endl; 
	subarraySumAll(a , n , sum ); 
	cout << "Length of the largest subarray : " ; 
	subarraySumLargest(a ,n , sum ) ;

	return 0 ;
}