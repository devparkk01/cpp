/*Given two strings X and Y. The task is to find the length of the longest common substring.also print 
the common substring . 
 

Input:
First line of the input contains number of test cases T. Each test case consist of three lines, 
first of which contains 2 space separated integers N and M denoting the size of string X and Y strings
respectively. The next two lines contains the string X and Y.

Output:
For each test case print the length of longest  common substring of the two strings .

ABCDGH
ACDGHR
output : 4 (CDGH)

*/


/* we ll use dynamic programming . 
The idea is to find length of the longest common suffix for all substrings of both strings
and store these lengths in a table.

time : O(m * n ) , space : O(m * n ) where m , n is size of the two strings 

*/

#include<iostream>
#include<vector>

using namespace std ; 

int longestCommonSubstring(string x , string y ) {
	int m  = x.length() ; int n = y.length() ; 
	vector<int> dp[m+1] ;
	for (int i = 0  ; i <= m ; ++i ) {
		dp[i] = vector<int>(n+1) ; 
	}
	int row , column ; int length = 0  ;

	for (int i = 1 ;  i  <= m ; ++i ){
		for (int j = 1 ; j <= n ; ++j ) {
			if ( x[i-1] == y[j-1 ]) {
				dp[i][j] = 1 + dp[i-1][j-1] ; 
				if (dp[i][j] > length) {
					length = dp[i][j] ;
					row = i ; column =  j ; 
				}
			}
			else 
				dp[i][j] = 0 ; 
		}
	}
	if (length == 0 ) return 0 ; 
	
//  for printing the substring . 
	int i = row ; int j = column ; string substring = ""  ;  substring.reserve(length) ; 
	while ( dp[i][j] > 0 ) {
		substring = x[i-1] + substring ; i-- ; j-- ; 
	}
	cout << substring<<  endl ; 
	return length ; 
}


int main () {
	string x = "ABCDGH" ; 
	string y = "ACDGHR" ;
	// string x = "tupptli" ; 
	// string y = "tipret" ; 
	cout << longestCommonSubstring(x , y ) << endl; 
	return 0 ; 

}






