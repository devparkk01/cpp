/*
https://leetcode.com/problems/minimum-window-substring/

Given two strings s and t of lengths m and n respectively, return the minimum window substring
 of s such that every character in t (including duplicates) is included in the window. If there
 is no such substring, return the empty string "".


 time : O([s] + [t ])

*/



class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char , int > hasht ;
		for (char &c : t )hasht[c]++ ;

		int distinct = hasht.size() ;
		int count = 0 ;
		int start ;
		int windowLength = INT_MAX ;
		int l = 0 ;

		unordered_map<char , int> hashs ;
		for (int r = 0 ; r < s.length() ; ++r) {
			hashs[s[r]]++ ;
			if (hashs[s[r]] == hasht[s[r]]) {
				count++ ;
			}
			if (count == distinct ) {
				while (hasht.find(s[l]) == hasht.end() || (hashs[s[l]] > hasht[s[l]] ) ) {
					hashs[s[l]]-- ;
					l++ ;
				}

				int curwindow = r - l + 1 ;
				if (curwindow < windowLength ) {
					windowLength = curwindow ;
					start = l ;
				}

			}


		}

		if (windowLength == INT_MAX) return "" ;
		else return s.substr(start , windowLength) ;


	}
};