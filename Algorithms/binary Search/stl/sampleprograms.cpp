#include<bits/stdc++.h>
using namespace std ;
#define endl '\n'

// print the first occurence of x in array , if it does not exist return -1
int firstOccurence(int a[] , int n , int x ) {
	int index = lower_bound(a , a + n , x ) - a ;
	if ( index != n && a[index ] == x ) return index ;
	else return -1 ;
}

// print the last occurence of x in array , if it does not exist return -1
int lastOccurence(int a[] , int n , int x ) {
	int index = upper_bound(a , a + n , x ) - a ;
	index-- ;
	if ( index >= 0 && a[index] == x ) return index ;
	else return -1 ;
}


// find the largest number smaller than x in the sorted array ,if no number exists print -1
int largest(int a[] , int n , int x ) {
	int index = lower_bound( a , a + n , x ) - a  ;
	index-- ;
	if ( index >= 0 ) return a[index] ;
	else return -1 ;
}

// find the smallest number greater than x in the sorted array ,if no number exists print -1
int smallest(int a[] , int n , int x ) {
	int index = upper_bound(a , a + n , x ) - a ;
	if ( index != n ) return a[index] ;
	else return -1 ;
}


signed main () {
	int a[] = {1 , 2 , 2, 2, 2 , 3 , 4, 4 , 8 , 10 , 16  } ;
	int n = sizeof(a) / sizeof(int ) ; // 11
	cout << firstOccurence(a , n , 2 ) << endl;
	cout << firstOccurence(a , n , 7) << endl;
	cout << firstOccurence(a , n , 18 ) << endl;
	cout << firstOccurence(a , n , 0 ) << endl ;
	cout << endl ;
	cout << lastOccurence(a , n , 2 ) << endl;
	cout << lastOccurence(a , n , 7) << endl;
	cout << lastOccurence(a , n , 18 ) << endl;
	cout << lastOccurence(a , n , 0 ) << endl ;
	cout << endl ;
	cout << largest(a , n , 2 ) << endl;
	cout << largest(a , n , 7) << endl;
	cout << largest(a , n , 18 ) << endl;
	cout << largest(a , n , 0 ) << endl ;
	cout << endl ;
	cout << smallest(a , n , 2 ) << endl;
	cout << smallest(a , n , 7) << endl;
	cout << smallest(a , n , 18 ) << endl;
	cout << smallest(a , n , 0 ) << endl ;




}