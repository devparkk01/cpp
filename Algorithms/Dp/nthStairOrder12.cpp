/*There are N stairs, a person standing at the bottom wants to reach the top.
The person can climb either 1 stair or 2 stairs at a time. Count the number of ways,
the person can reach the top (order does matter).

This problem is same as ways coin change where order does matter .

*/


#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL)  ; cout.tie(NULL) ;
#define f(i,a,n) for(i = a ; i<=n ; i++)
#define endl '\n'

using namespace std ;


// Recursive solution . time : O(2 ^n)
/*
int stairCase(int n ) {
	if ( n == 0 || n == 1 ) return 1 ;
	else return stairCase(n - 1 ) + stairCase(n - 2 )  ;

}
*/


// top down approach , time : O(n) , space : O(n )

/*
int stairCaseUtil (int n , int mem[] ) {
	if ( mem[n] != -1) return mem[n];
	else mem[n] = stairCaseUtil(n - 1, mem) + stairCaseUtil(n - 2, mem) ;
	return mem[n] ;
}
int stairCase(int n ) {
	int mem[n + 1] ;
	memset(mem , -1 , sizeof(mem)) ;
	mem[0] = 1 ; mem[1] = 1 ;
	return stairCaseUtil(n , mem) ;
}
*/

// bottom up approach . time : O(n) , space : O(n)

/*
int stairCase(int n) {
	int dp[n + 1 ] ;
	dp[0] = 1 ; dp[1] = 1 ;
	for (int i = 2 ; i <= n ; ++i ) {
		dp[i] = dp[i - 1 ] + dp[i - 2] ;
	}
	return dp[n] ;
}
*/

// beautiful solution , space efficient , time : O(n) , space : O(1)
// same as fibonacci sequence

int stairCase(int n ) {
	if ( n == 0 || n == 1) return 1 ;

	int first = 1 , second = 1 ;
	for (int i = 2 ; i <= n ; ++i )  {
		int temp = first + second ;
		second = first ;
		first = temp  ;
	}
	return first ;

}

int main () {
	fastio ;
	int n = 5 ;
	cout << stairCase(n) << endl;
	return 0 ;

}