/*
https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1#
*/

class Solution {
public:

	string longestCommonPrefix (string arr[], int N)
	{
		string ans = arr[0]  ;
		int length = ans.length() ;

		for (int i = 1 ; i < N ; ++i) {
			length = match(arr[i] , ans , length) ;
		}
		if (length >= 1 ) return ans.substr(0 , length) ;
		else return "-1" ;

	}
	int match(string &a , string &p , int length) {
		int i = 0 ;
		while (i < a.length() && i < length) {
			if (a[i] == p[i])i++ ;
			else break ;
		}
		return i ;

	}
};