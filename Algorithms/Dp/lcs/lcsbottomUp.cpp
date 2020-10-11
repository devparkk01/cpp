/*Given two sequences, find the length of longest common subsequence present in both of them.
also print the subsequence 
A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.

x = “ABCDGH” , y = “AEDFHR”  = > LCS is “ADH” of length 3.
x = “AGGTAB” , y = “GXTXAYB” = > LCS is “GTAB” of length 4.
*/

// time : O(m*n) , space : O(m * n) 

#include<iostream>
#include<vector>

using namespace std ; 

int LCS (string x ,string y ) {
	int m = x.length() ; int n = y.length() ;
	vector<int>dp[m+1] ;
	for(int i  = 0 ;i <= m ;++i ) {
		dp[i] = vector<int>(n+1) ;
	}

	for (int i = 1 ; i <=m ; ++i ) {
		for (int j = 1; j <= n ; ++j ) {
			if (x[i-1] == y[j-1]) {
				dp[i][j] = 1  + dp[i-1][j-1] ; 
			}
			else 
				dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);  
		}
	}
	// printing the subsequence 
	int index = dp[m][n] ; 
	char subsequence[index + 1] ;  subsequence[index] = '\0' ; 
	int i = m ; int j = n  ;
	while ( i > 0 && j > 0 ) {
		if ( x[i-1] == y[j-1]) {
			subsequence[--index] = x[i-1]; 
			i-- ; j-- ; 
		}
		else {
			if ( dp[i-1][j] > dp[i][j-1]) i-- ; 
			else j-- ; 
		}
	}
	cout << subsequence << endl; 

	return dp[m][n] ; 

}


int main () {
	// string x = "GXTXAYB" ; string y = "AGGTAB" ; 
	string x = "ZXVVYZW" , y = "XKYKZPW" ; 
	cout << LCS(x , y ) << endl; 
	return 0 ; 
}