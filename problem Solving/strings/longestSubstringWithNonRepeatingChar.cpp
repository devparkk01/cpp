/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/



class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_set <char > hash ;
		int ans = 0 ;

		int n = s.size() ; int l = 0 ;
		for (int r = 0 ; r < n ; ++r) {
			char c = s[r] ;
			if (hash.find(c) == hash.end()) {
				// not found
				hash.insert(c) ;
				ans = max(ans , r - l + 1 ) ;
			}
			else {
				while (s[l] != c ) {
					hash.erase(s[l]) ;
					l++ ;
				}
				l++ ;

			}
		}
		return ans ;
	}
};

