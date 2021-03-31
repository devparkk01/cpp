/* https://leetcode.com/problems/single-number-ii/

Given an integer array nums where every element appears three times except for one, which appears
exactly once. Find the single element and return it.

*/

/*  approach 1 : sort the array , and find out the element occuring once
time : O(n logn  + n ) , space : O(1)
*/


/* appraoch 2 : count the frequency of each element and store it in a hashmap
time : O(n) , space : O(n)
*/
int singleNumber(vector<int>& nums) {
	unordered_map<int , int > ump ;
	for (int &x : nums ) {
		ump[x]++ ;
	}
	// for(auto it = ump.begin() ; it != ump.end() ; ++it ) {
	// 	if ( it->second == 1 ) return it->first ;
	// }
	for (auto &it : ump) {
		if ( it.second == 1 )return it.first ;
	}
	return -1 ;
}

/* approach 3 :



*/
int singleNumber(vector<int>& nums) {
	int ans = 0 ;
	int c ;
	for (int  i = 0 ; i < 32 ; ++i  ) {
		unsigned  f = 1 << i ; // try taking it unsigned
		c = 0 ;
		for (int &x : nums ) {
			if ( (x & f ) > 0 ) {// ith bit is set in x
				c++  ;
			}
		}
		if (c % 3 == 1 ) ans += f ;
	}
	return ans ;
}