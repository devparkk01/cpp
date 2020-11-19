/*Given two sorted arrays, a[] and b[], task is to find the median of these sorted arrays,
when n is the number of elements in the first array, and m is the number of elements in the
second array.

*/

#include<bits/stdc++.h>
using namespace std ;

// time : O(n + m ) , space : O(1)
float  medianOne(int a[] , int b[] , int n , int m ) {
	int m1 = -1 , m2 = -1 ; 
	int i = 0 , j  = 0 ; 
	for(int count = 0 ; count <= (n +m )/2 ; ++count ) {
		if ( i < n && j < m ) {
			if (a[i] < b[j]) {
				m2 = m1 ; 
				m1 = a[i] ; 
				i++  ; 
			}
			else {
				m2 = m1 ; 
				m1 = b[j] ; 
				j++ ; 
			}
		}
		else if ( i == n ) {
			m2 = m1 ; 
			m1 = b[j] ;
			j++ ; 
		}
		else {
			m2 = m1 ;
			m1 = a[i] ; 
			i++ ; 
		}
	}
	if ( (m+n) & 1 ) return m1 ;
	else return (m1 + m2 )/2.0 ; 

}

signed main () {
	int a[] = {2 , 3 , 6 , 8 , 11} ;
	int n = sizeof(a)/sizeof(int ) ;
	int b[] = {0  } ; 
	int m = sizeof(b)/sizeof(int ) ;

	cout << medianOne(a, b, n , m ) << endl;  

	return 0 ; 
}