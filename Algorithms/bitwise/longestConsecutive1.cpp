/* Given a number N. Find the length of the longest consecutive 1s in its binary representation.

Input: N = 222
Output: 4

Binary representation of 222 is   11011110, in which 1111 is the longest consecutive set
bits of length 4.
*/
int maxConsecutiveOnes(int n)
{
	// code here
	if ( n == 0 ) return 0 ;
	int c = 1 ;
	while ( n & (n >> 1) ) {
		c++ ;
		n = (n & (n >> 1)) ;
	}
	return c ;

}