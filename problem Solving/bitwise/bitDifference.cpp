/*You are given two numbers A and B. The task is to count the number of bits needed
 to be flipped to convert A to B.


same question : count the number of positions at which the corresponding bits are different

*/


#include<bits/stdc++.h>
using namespace std ;


int countsBitsFlip(int a , int b ) {
	int res = a ^ b ;
	// now count the number of set bits in res
	if ( res == 0 ) return 0 ;
	int c = 0 ;
	while ( res != 0 ) {
		res = res & (res - 1 ) ;
		c++ ;
	}
	return c ;

}

signed main() {
	int a = 30 ;
	int b = 13 ;
	cout << countsBitsFlip(a, b ) << endl;

	return 0 ;

}