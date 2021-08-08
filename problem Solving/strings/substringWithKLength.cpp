/*
https://practice.geeksforgeeks.org/problems/substrings-of-length-k-with-k-1-distinct-elements/1/

Given a String S and an integer K. Find the count of all substrings of length K which
 have exactly K-1 distinct characters.

*/


class Solution {
public:
	int countOfSubstrings(string S, int K) {
		int count = 0 ;
		unordered_map<char , int > hash ;

		int l = 0 ;
		for (int r = 0 ; r < S.length() ; ++r ) {
			int window = r - l + 1 ;
			char c = S[r] ;
			if (window < K ) {
				hash[c]++ ;
			}
			else if (window == K ) {
				hash[c]++ ;
				if (hash.size() == K - 1 ) {
					count++ ;
				}
				hash[S[l]]-- ;
				if (hash[S[l]] == 0 ) {
					hash.erase(S[l]) ;
				}
				l++ ;
			}
		}
		return count ;

	}
};