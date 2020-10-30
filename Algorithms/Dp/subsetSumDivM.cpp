/*Given a set of non-negative integers , and a value m , determine if there is a subset of 
the given set with sum divisible by m . 
variation of subset sum problem .
*/

#include<bits/stdc++.h>
using namespace std ; 

// space efficient bottom up dp approach ,time : O(n *m ) , space : O(m)

// bool subsetSumDivM(int set[] , int n , int m ) {
// 	if (n > m ) return true ; 
// 	bool dp[m]; 
// 	memset(dp , false , sizeof(dp)) ; 
// 	bool temp[m] ; 

// 	for(int i = 0; i < n ; ++i ) {
// 		if ( dp[0] == true ) return true ; 

// 		memset(temp , false , sizeof(temp )) ; 

// 		for(int j = 0 ; j < m ; ++j ) {
// 			if ( dp[j] == true ) {
// 				int newMod = (j + set[i]) % m ; 
// 				if ( dp[newMod] == false ) 
// 					temp[newMod] = true ; 
// 			}
// 		}

// 		temp[set[i] % m ] = true ; 

// 		for(int j =0 ; j < m ; ++j ) {
// 			if ( temp[j] == true ) dp[j] = true ; 
// 		}
// 	}
// 	return dp[0] ; 

// }


//  top down dp approach , time : O(n *m ) , space : O(n *m )

bool subsetSumDivMUtil(int set[] , int n , int m , int modulo , int dp[101][101]) {
	if ( n == 0 ) return false ; 
	if (set[n-1] % m == modulo ) return true ; 
	if ( dp[n][modulo] != -1 ) return dp[n][modulo] ; 
	else {
		int nextModulo = modulo - (set[n-1] % m ) ; 
		if ( nextModulo < 0 ) nextModulo+=m ; 
		int include = subsetSumDivMUtil(set , n-1 , m , nextModulo , dp) ;
		int exclude = subsetSumDivMUtil(set , n-1 , m , modulo , dp) ; 
		dp[n][modulo] = include || exclude ; 
		return dp[n][modulo] ; 
	}

}

bool subsetSumDivM(int set[] , int n , int m ) {
	if ( n > m ) return true; 
	int dp[101][101] ;
	memset(dp , -1, sizeof(dp) ) ;
	return subsetSumDivMUtil(set , n , m , 0 , dp ) ; 
}



signed main() {
	int set[] = {3 ,1 , 7  , 2 };
	int n = sizeof(set)/sizeof(int) ;
	int m = 6 ; 
	cout << subsetSumDivM(set , n , m ) << endl; 


	return 0 ; 
}