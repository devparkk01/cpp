/*
A child is running up a staircase with n steps and can hop either 1 step,
2 steps, or 3 steps at a time. Implement a method to count how many possible ways
the child can run up the stairs. Order does  matter .

*/

/*
*/
#include<bits/stdc++.h>
using namespace std ;

// solution 1
// Recursive solution , time : O(3 ^ n )

/*
int stairCase(int n ) {
	if ( n == 0 || n == 1 ) return 1 ;
	if ( n == 2 ) return 2 ;
	else return stairCase(n - 1 ) + stairCase(n - 2 ) + stairCase(n - 3 ) ;

}
*/

// top down approach , time : O(n) , space : O(n )
/*
int stairCaseUtil (int n , int mem[] ) {
	if ( mem[n] != -1) return mem[n];
	else mem[n] = stairCaseUtil(n - 1, mem) + stairCaseUtil(n - 2, mem) + stairCaseUtil(n - 3, mem ) ;
	return mem[n] ;
}
int stairCase(int n ) {
	int mem[n + 1] ;
	memset(mem , -1 , sizeof(mem)) ;
	mem[0] = 1 ; mem[1] = 1 ; mem[2] = 2 ;
	return stairCaseUtil(n , mem) ;
}
*/

// bottom up approach . time : O(n) , space : O(n)
/*
int stairCase(int n) {
	int dp[n + 1 ] ;
	dp[0] = 1 ; dp[1] = 1 ; dp[2] = 2  ;
	for (int i = 3 ; i <= n ; ++i ) {
		dp[i] = dp[i - 1 ] + dp[i - 2] + dp[i - 3] ;
	}
	return dp[n] ;
}
*/

// beautiful solution , space efficient , time : O(n) , space : O(1)
// same as fibonacci sequence

int stairCase(int n ) {
	if ( n == 0 || n == 1  ) return 1 ;
	else if ( n == 2) return 2 ;
	int first = 2 , second = 1 , third = 1 ;
	for (int i = 3 ; i <= n ; ++i )  {
		int temp = first + second + third ;
		third = second ;
		second = first ;
		first = temp  ;
	}
	return first ;
}

int main () {
	int n = 5 ;
	cout << stairCase(n ) << endl ;
	return 0 ;

}

