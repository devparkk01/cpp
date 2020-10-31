/*Given a positive integer num, write a function which returns True if num is a 
perfect square else False.
*/

#include<iostream>
using namespace std;  

bool perfectSquare(int num ) {
	if ( num == 0 || num == 1 ) return true ; 
	int low = 0 ,  high = num /2 ; 
	long mid ;
	while ( low <= high ) {
		mid = low + (high - low)/ 2 ; 
		if (mid * mid == num ) return true ; 
		else if ( mid * mid < num ) 
			low = mid + 1 ; 
		else if ( mid * mid > num )
			high = mid - 1 ; 
	}
	return false ; 

}

signed main() {
	int num = 16  ; 
	cout << perfectSquare(num) << endl; 

	return 0 ; 
}