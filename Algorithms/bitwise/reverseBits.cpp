/* https://leetcode.com/problems/reverse-bits/
Input: n = (4294967293)11111111111111111111111111111101
Output:   (3221225471 )10111111111111111111111111111111


*/

// time : O(32) 32 operations are being performed , so O(1)

uint32_t reverseBits(uint32_t n) {
	uint32_t r = 0 ;
	int i = 0 ;
	while (i < 32) {
		r = r << 1 ;
		if ( n & 1 ) { r = r + 1 ; }
		n = n >>  1 ;
		i++ ;
	}
	return r ;
}