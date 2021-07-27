/*
https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1#
*/


class Solution {
public:
	vector<vector<string>> allPalindromicPerms(string S) {
		// code here
		vector<vector<string>>res ;
		vector<string>path ;
		findAll(S , 0 , path , res ) ;
		return res ;
	}
	void findAll(string &S , int start , vector<string>&path , vector<vector<string>>&res ) {
		if (start == S.length()) res.push_back(path) ;
		else {
			for (int k = start ; k < S.length() ; ++k) {
				if (ispal(S , start , k )) {
					path.push_back(S.substr(start , k - start + 1 )) ;
					findAll(S , k + 1, path , res ) ;
					path.pop_back() ;
				}
			}
		}
	}
	bool ispal(string &s , int i , int j ) {
		while (i < j ) {
			if (s[i] != s[j]) return false ;
			else {
				i++ ; j-- ;
			}
		}
		return true ;
	}

};