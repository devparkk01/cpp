#include<bits/stdc++.h>
using namespace std ;
#define endl '\n'
#define f(i , k , n ) for(int i = k ; i < n ; ++i )

/* binary_search( a, a+n , x ) , returns true if x exists in the array
else returns false

*/


signed main () {
	int a[] = { 1 , 2 , 4 , 4 , 5 , 7 } ;
	int n = sizeof(a) / sizeof(int ) ;
	cout << binary_search(a, a + n , 1 ) << endl;
	cout << binary_search(a , a + n , 3 ) << endl;
	cout << binary_search(a , a + n , 10) << endl;


	vector<int>v = { 1,  3 , 5 , 6 ,  22} ;
	cout << binary_search(v.begin() , v.end() , 3) << endl;
	cout << binary_search(v.begin() , v.end() , 20) << endl;
	cout << binary_search(v.begin() , v.end() , 1) << endl;


	return 0 ;



}