/* A Bitonic Sequence is a sequence of numbers which is first strictly increasing then
after a point strictly decreasing.
Given a bitonic sequence of n distinct elements, write a program to find a
 given element x in the bitonic sequence

*/

#include<iostream>
using namespace std ;

// finds the index of peak element in this bitonic array
int findHighest(int a[] , int n) {
	int low = 0 , high = n - 1 ;
	int mid ;
	while (low < high) {
		mid = low + (high - low ) / 2 ;
		if (a[mid] > a[mid + 1 ]) {
			high = mid ;
		}
		else if (a[mid] < a[mid + 1 ]) {
			low = mid + 1 ;
		}
	}
	return  low ;
}

int binarysearch(int a[] , int n , int low , int high , int x ) {
	int mid ;
	while (low <= high ) {
		mid = low + (high - low ) / 2 ;
		if ( a[mid] == x ) return mid ;
		else if ( a[mid] < x ) low = mid + 1 ;
		else if ( a[mid ] > x ) high = mid - 1;
	}
	return -1 ;
}

int search(int a[] , int n , int x ) {
	int index = findHighest(a , n ) ; // get the index of peak element in this bitonic array
	if ( x == a[index]) return index ; // if the peak element is x then return that index
	if (x > a[index]) return -1 ; // x doesn't exist in this case

	// let's do binary search in the increasing part of this bitonic array ( 0 , index - 1 )
	int low = 0 , high = index - 1 ;

	int ans = binarysearch(a, n, low , high , x ) ;
	if ( ans != -1 ) return ans ;


	// if element is not found
	// do binary search in decreasing part of this bitonic array ( index , n-1 )

	low = index ; high = n - 1;

	ans = binarysearch(a , n , low , high , x ) ;
	return ans ;


}

signed main () {
	int a[] = { 1 , 2 , 3 , 5 , 10 , 8 , 7 , 0} ;
	int n = sizeof(a) / sizeof(int) ;
	int x = 10 ;
	cout << search(a , n , x ) << endl;

	return 0 ;
}
