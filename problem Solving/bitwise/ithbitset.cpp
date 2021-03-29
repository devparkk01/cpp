/*
find whether the ith bit is set or not
*/
// time : O(1 )
bool solve(int n , int i ) {
	int f = 1 ;
	f = f << ( i - 1 ) ;
	// f will have only ith bit as 1 , rest bits will be 0

	if ( n & f ) return true ;
	else return false;
}