#include<bits/stdc++.h>
using namespace std;  

/*Time : O(m*n) , space : O(m*n) */

int LCSUtil (string x, string y , int m , int n , vector<vector<int>>&lookUp ) {
	if ( m == 0 || n == 0 ) return 0 ; 

	if (lookUp[m][n] == -1 ) {
		if( x[m-1] == y[n-1]) 
			lookUp[m][n] = 1 + LCSUtil(x , y , m-1, n-1 , lookUp) ; 
		else 
			lookUp[m][n] = max(LCSUtil(x, y , m-1 , n , lookUp),LCSUtil(x ,y ,m , n-1 , lookUp)) ; 
		return lookUp[m][n] ; 
	}
	else 
		return lookUp[m][n] ; 
}


string printLCS(string x , string y , int m , int n, vector<vector<int>>&lookUp ) {
	if ( m == 0 || n == 0 ) return string("") ; 

	if ( x[m-1] == y[n-1])
		return printLCS(x , y , m-1 , n-1 ,lookUp ) + x[m-1] ; 

	if (lookUp[m-1][n] > lookUp[m][n-1])
		return printLCS(x , y , m-1 , n , lookUp) ; 
	else 
		return printLCS(x , y , m , n-1 , lookUp) ; 
}

int LCS(string x , string y ) {
	int m = x.length() ;
	int n = y.length() ; 
	vector<vector<int>>lookUp(m+1 , vector<int>(n+1 , -1)) ; 

	int length = LCSUtil(x , y , m , n , lookUp) ; 
	
	cout << printLCS(x , y , m , n , lookUp) << endl; 
	return length ; 
}


signed main () {
	// string x = "GXTXAYB" ; string y = "AGGTAB" ; 
	// string x = "ZXVVYZW" , y = "XKYKZPW" ; 
	string x = "ABCBDAB" , y = "BDCABA" ; 
	cout << LCS(x , y ) << endl; 
	return 0 ; 
}