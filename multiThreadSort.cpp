#include<iostream>
#include<algorithm>
#include<vector>
#include<execution>

using namespace std ;


signed main () {
	vector<int>v = {2 , 5 , 2 , 1 , 9 , 3 , 7} ;
	sort(execution::par , v.begin() , v.end() ) ;
	for (int &x : v ) cout << x << "  " ;


	return 0 ;
}