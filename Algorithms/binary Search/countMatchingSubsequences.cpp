/*Given a string s and an array of strings words, return the number of words[i] that is a
subsequence of s.

Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
There are three strings in words that are a subsequence of s: "a", "acd", "ace".
approach is discussed below
*/



class Solution {
public:
	int numMatchingSubseq(string s, vector<string>& words) {
		int count = 0 ;
		vector<vector<int>>freq(26) ;
		int n = s.length() ;
		for (int i = 0 ; i < n ; ++i )  {
			freq[s[i] - 'a'].push_back(i) ;
		}

		for (string &word : words) {
			if (subseq(s , word , freq)) count++ ;
		}
		return count ;


	}
	bool subseq(string &s,  string &word , vector<vector<int>>&freq) {
		int previousMatched = -1 ; int currentIndex ;
		for (char &c : word) {
			if (freq[c - 'a'].size() == 0 ) return 0 ;
			int index = upper_bound(freq[c - 'a'].begin(), freq[c - 'a'].end() , previousMatched) - freq[c - 'a'].begin() ;
			if (index == freq[c - 'a'].size() ) return 0 ;
			currentIndex = freq[c - 'a'][index] ;
			previousMatched = currentIndex  ;

		}
		return 1 ;
	}
};

/*
approach 1 :
use two pointer approach . It will give tle if the given list of words is very large

approach 2 :
use binary search . see notebook

*/

