/*Given two strings X and Y. The task is to find the length of the longest common substring.also print
the common substring .

ABCDGH
ACDGHR
output : 4 (CDGH)

*/

/* we ll use dynamic programming .
The idea is to find length of the longest common suffix for all substrings of both strings
and store these lengths in a table.

time : O(m*n) , space : O(m*n) where m , n is size of the two strings

*/

#include<bits/stdc++.h>
using namespace std ;

int longestCommonSubstring(string x , string y ) {
	int m  = x.length() ; int n = y.length() ;

	int LCSuffix[m + 1][n + 1] ;
	memset(LCSuffix , 0 , sizeof(LCSuffix )) ;

	int len = 0 ; // stores the length of the longest common substring
	int endIndex ;// stores the (end Index + 1) of the longest common substring

	for (int i = 1 ; i <= m ; ++i ) {
		for (int j = 1 ; j <= n; ++j ) {
			if (x[i - 1] == y[j - 1]) {
				LCSuffix[i][j] = 1 + LCSuffix[i - 1][j - 1] ;
				if ( LCSuffix[i][j] > len) {
					len = LCSuffix[i][j] ;
					endIndex = i ;
				}
			}
			else
				LCSuffix[i][j] = 0 ;
		}
	}

	if (len == 0 ) {
		cout << "Longest common Substring : " << "" << endl;
		return 0 ;
	}
	else {
		cout << "Longest common substring : " << x.substr(endIndex - len , len ) << endl ;
		return len ;
	}
}


int main () {
	// string x = "ABCDGH" ;
	// string y = "ACDGHR" ;
	string x = "tupptli" ;
	string y = "tipret" ;
	// string x = "ab" ;
	// string y = "rd" ;

	cout << longestCommonSubstring(x , y ) << endl;
	return 0 ;

}






