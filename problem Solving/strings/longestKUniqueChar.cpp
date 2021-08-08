/*

https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1#


sliding window method

*/


class Solution {
public:
	int longestKSubstr(string s, int k) {
		unordered_map<char , int > hash ;
		if (s.length() < k ) return -1 ;
		int ans = 0 ;
		int l = 0 ;
		for (int r = 0 ;  r < s.length() ; ++r ) {
			hash[s[r]]++ ;
			if (hash.size() == k ) {
				ans = max(ans , r - l + 1 ) ;
			}
			else if ( hash.size() > k ) {
				while (hash.size() > k ) {
					hash[s[l]]-- ;
					if (hash[s[l]] == 0 ) {
						hash.erase(s[l]) ;
					}
					l++ ;
				}
			}
		}
		return (ans == 0) ? -1  : ans ;


	}
};