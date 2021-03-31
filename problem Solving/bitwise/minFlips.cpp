/*
https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

time of both approaches is O(32) which is same as 0(1)

*/

// here , we are modifying a, b , c
int minFlips(int a, int b, int c) {
	// need to extract last bit from each of a  ,b , c
	int x , y ,  z , f  = 1 ; int flipscount = 0 ;

	for (int i = 0 ; i < 32 ; ++i ) {
		x = (a & f ) ;
		y = (b & f ) ;
		z = (c & f ) ;
		a = a >> 1 ; b = b >> 1 ; c = c >> 1 ;
		// flipping begins
		if ( z == 1 ) {
			if ( x == 0 &&  y == 0 ) flipscount++ ;
		}
		else {
			if ( x != 0 ) flipscount++ ;
			if ( y != 0 ) flipscount++ ;
		}
	}
	return flipscount ;
}

// here we aren't modifying a, b , c
int minFlips(int a, int b, int c) {
	// need to extract ith bit from each of a  ,b , c
	int x , y ,  z ; int flipscount = 0 ;
	// x , y , z stores ith bit of a, b and c respectively

	for (int i = 0 ; i < 32 ; ++i ) {
		int f = 1 ; f = f << i ;
		x = (a & f ) ;
		y = (b & f ) ;
		z = (c & f ) ;
		// flipping begins
		if ( z  ) { // if z is set
			if ( x == 0 &&  y == 0 ) flipscount++ ;
		}
		else { // z is not set
			if ( x != 0 ) flipscount++ ;
			if ( y != 0 ) flipscount++ ;
		}
	}
	return flipscount ;
}
