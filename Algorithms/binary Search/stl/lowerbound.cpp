#include<bits/stdc++.h>
using namespace std ;
#define endl '\n'
#define f(i , k , n ) for(int i = k ; i < n ; ++i )

/*
lower_bound(a ,a + n ,x ) returns the iterator pointing to the first occurencee of
x , if x exists in the array , else it returns the iterator pointing to the next greater
element
*/


signed main () {
	int a[] = { 1 , 2 , 4 , 4 , 5 , 5 , 5 , 7 } ;
	int n = sizeof(a) / sizeof(int ) ;
	cout << lower_bound(a, a + n , 4) - a << endl;  // 2
	cout << lower_bound( a, a + n , 2 ) - a  << endl ; // 1
	cout << lower_bound(a , a + n , 5) - a  << endl  ; // 4
	cout << lower_bound(a , a + n , 12 ) - a << endl ; // 8

	vector<int>v = { 1,  3 , 5 , 5,  6 ,  22} ;

	cout << lower_bound(v.begin() , v.end() , 5) - v.begin() << endl; // 2
	cout << lower_bound(v.begin() , v.end() , 0 ) - v.begin() << endl; // 0


	return 0 ;



}