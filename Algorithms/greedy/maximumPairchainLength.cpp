/*
https://leetcode.com/problems/maximum-length-of-pair-chain/

You are given n pairs of numbers. In every pair, the first number is always smaller than the
second number.  Now, we define a pair (c, d) can follow another pair (a, b) if and only
if b < c. Chain of pairs can be formed in this fashion.
Given a set of pairs, find the length longest chain which can be formed.
You needn't use up all the given pairs. You can select pairs in any order.

Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]


time : O(nlogn) ,space : O(1)


*/

class Solution {
public:
	static bool compare(vector<int>&a, vector<int>&b) {
		return a[1] < b[1] ;
	}

	int findLongestChain(vector<vector<int>>& pairs) {
		int n = pairs.size() ;
		if ( n == 0 || n == 1  ) return n ;
		sort(pairs.begin() , pairs.end() , compare ) ;
		int secondnum = pairs[0][1] ; // first pair is always included in the chain
		int count = 1 ;
		for (int i = 1 ; i < n ; ++i ) {
			// if first number of this pair is strictly larger than second number of
			// the previously selected pair  ,then include this pair
			if ( pairs[i][0] > secondnum ) {
				count++ ;
				secondnum = pairs[i][1] ;
			}
		}
		return  count ;

	}
};