/*
https://practice.geeksforgeeks.org/problems/longest-valid-parentheses5657/1

Given a string S consisting of opening and closing parenthesis '(' and ')'.
Find length of the longest valid parenthesis substring.


time : O(n) , space : O(n)

*/


class Solution {
public:
	int maxLength(string S) {
		if (S.length() <= 1 ) return 0 ;
		stack<int > st ;
		st.push(-1) ; // provides base for the next valid substring
		int maxLen = 0 ;
		for (int i = 0 ; i < S.length() ; ++i) {
			if (S[i] == '(') st.push(i) ;
			else {
				st.pop() ;
				if (st.empty()) {
					st.push(i) ; // provides base for the next valid substring
				}
				else {
					maxLen = max(maxLen , i - st.top()) ;
				}
			}
		}
		return maxLen ;



	}
};