/*  https://leetcode.com/problems/delete-operation-for-two-strings/

Given two strings word1 and word2, return the minimum number of steps required to make word1
and word2 the same.
In one step, you can delete exactly one character in either string.

Input: word1 = "sea", word2 = "eat"
Output: 2
*/

/*
approach 1 : use simple dynamic programming

approach 2 : use lcs
It's a variation of lcs problem .
answer will be len(str1) + len(str2) - 2 * lcs(str1 , str2)
*/

// approach 1
int mem[501][501] ;
int util(string x , string y , int m , int n ) {
	if ( m == 0) return n ;
	if ( n == 0 ) return m ;

	if ( mem[m][n] != -1 ) return mem[m][n] ;
	if ( x[m - 1 ] == y[n - 1 ]) mem[m][n] = util(x , y , m - 1 , n - 1 ) ;
	else mem[m][n] = 1 +  min(util(x , y , m - 1 , n) , util(x , y , m , n - 1 )) ;
	return mem[m][n] ;
}

int minDistance(string word1, string word2) {
	memset(mem , -1 , sizeof(mem)) ;
	return util(word1 , word2 , word1.length() , word2.length())  ;
}