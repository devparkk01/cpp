
/*
https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#



This question is very similar to finding median of two sorted arrays. We used binary search there .
We will use binary search here too .

just we need to be careful while choosing the right values of 'low' and 'high'
during initialization
time : O(log(min(n , m )))



*/
#include<bits/stdc++.h>
using namespace std;


int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
	if (k == 1 ) return min(arr1[0] , arr2[0]) ;
	if (n > m) return kthElement(arr2 , arr1 , m , n , k) ;

	// if k <= m , then minimum we can select (0) elements in left partition from nums1
	// if k > m , then minimum we can select (k-m) elements in left partition from nums1
	int low = max(0 , k - m )  ;
	// if k <= n, then maximum we can select (k) elements in left partition from nums1
	// if k > n, then maximum we can select (n) elements in left partition from nums1
	int high = min(k , n ) ;

	while (low <= high ) {
		int cut1 = (low + high) / 2 ;
		int cut2 = k - cut1 ;
		int left1 = (cut1 == 0 ) ? INT_MIN : arr1[cut1 - 1 ] ;
		int left2 = (cut2 == 0 ) ? INT_MIN : arr2[cut2 - 1 ] ;
		int right1 = ( cut1 == n ) ? INT_MAX : arr1[cut1] ;
		int right2 = (cut2 == m ) ? INT_MAX : arr2[cut2] ;

		if (left1 <= right2 && left2 <= right1) {
			return max(left1 , left2) ;
		}
		else if (left1 > right2) high = cut1 - 1 ;
		else if (left2 > right1) low = cut1 + 1 ;
	}
	return 1 ;
}