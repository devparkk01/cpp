#include<bits/stdc++.h>
using namespace std ;
#define endl '\n'
#define f(i , k , n ) for(int i = k ; i < n ; ++i )

/*
upper_bound(a ,a + n ,x ) returns the iterator pointing to the element just greater than x
*/


signed main () {
	int a[] = { 1 , 2 , 4 , 4 , 5 , 5 , 5 , 7 } ;
	int n = sizeof(a) / sizeof(int ) ;
	cout << upper_bound(a, a + n , 4) - a << endl;  // 4
	cout << upper_bound( a, a + n , 2 ) - a  << endl ; // 2
	cout << upper_bound(a , a + n , 5) - a  << endl  ; // 7
	cout << upper_bound(a , a + n , 12 ) - a << endl ; // 8

	vector<int>v = { 1,  3 , 5 , 5,  6 ,  22} ;

	cout << upper_bound(v.begin() , v.end() , 5) - v.begin() << endl; // 4
	cout << upper_bound(v.begin() , v.end() , 0 ) - v.begin() << endl; // 0


	return 0 ;



}