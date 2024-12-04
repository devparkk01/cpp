/*   https://leetcode.com/problems/single-number-iii/
Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs
whereas the other two number occur exactly once and are distinct. Find the other two numbers.
return the elements in ascending order
*/

// time : O(n)
vector<int> singleNumber(vector<int> nums)
{
	int n = nums.size() ;
	int res = 0 ;
	for (int &e : nums ) res = res ^ e ;

	int x = 0, y = 0; // x is the first missing number , y is the second missing number

	int k = 1 ; // k represents position of rightmost set bit  in res
	while ( (res & 1) != 1  ) {
		k++ ; res = res >> 1 ;
	}

	for (int &e : nums ) {
		if ( e & ( 1 << (k - 1 ))) x = x ^ e ;
		else y = y ^ e ;
	}

	return { min(x , y) , max(x , y ) } ;
}
