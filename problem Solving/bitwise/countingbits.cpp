/*  https://leetcode.com/problems/counting-bits/

Given an integer num, return an array of the number of 1's in the binary representation
 of every number in the range [0, num].

*/

vector<int> countBits(int num) {
	vector<int>ans ; ans.reserve(num + 1 ) ;
	ans.push_back(0) ;

	for (int i = 1 ; i <= num  ; ++i ) {
		ans.push_back(countSetBits(i)) ;
	}

	return ans ;

}
int countSetBits(int n) {
	int c = 0 ;
	while (n != 0 ) {
		c++ ; n = n & ( n - 1 ) ;
	}
	return c ;
}