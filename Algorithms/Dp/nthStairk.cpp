/*Given N number of stairs. Also given the number of steps that one can cover at most
in one leap (K). The task is to find the number of possible ways one
can climb to the top of the building in K leaps or less from the ground floor.

*/

#include<bits/stdc++.h>
using namespace std ;
#define f(i , k , n ) for(int i = k ; i <= n ; ++i )


int stairCase(int n , int k ) {
	int dp[n + 1 ] = {0} ;
	dp[0] = 1 ;
	f(i , k , n ) dp[i] += dp[i - 1 ] ;


}



signed main () {
	int n = 10 ; int k = 5 ;
	cout << stairCase(n , k ) << endl ;
}