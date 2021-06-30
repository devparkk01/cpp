/*
https://practice.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1

*/


int mem[501][501] ;

class Solution {
public:
	int countWays(string S1, string S2) {
		// code here
		memset(mem , -1 , sizeof(mem)) ;
		return util(S1 , S2 , S1.length() , S2.length()) ;
	}

	int util(string s , string p , int n , int m ) {
		if (m == 0 ) return 1 ;
		if (n == 0   )return 0 ;
		if (mem[n][m] != -1 ) return mem[n][m] ;

		if (s[n - 1 ] == p[m - 1 ]) {
			mem[n][m] = util(s , p , n - 1 , m - 1 ) + util(s , p , n - 1 , m) ;
		}
		else mem[n][m] = util(s , p , n - 1 , m ) ;
		return mem[n][m] ;

	}

};