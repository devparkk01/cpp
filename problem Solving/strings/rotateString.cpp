/*
https://leetcode.com/problems/rotate-string/

All rotations of A are contained in A+A. Thus, we can simply check whether B is a
substring of A+A. We also need to check A.length == B.length, otherwise we will fail cases
like A = "a", B = "aa".


*/


class Solution {
public:
	bool rotateString(string s, string goal) {
		if (s.length() != goal.length()) return false ;
		else {
			string temp = s + s  ;
			if (temp.find(goal) != string::npos) return true ;
			return false ;
		}
	}
};