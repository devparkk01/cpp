/*There are N stairs, a person standing at the bottom wants to reach the top.
The person can climb either 1 stair or 2 stairs at a time. Count the number of ways,
the person can reach the top (order does matter).
INPUT : 
 The first line contains an integer 'T' denoting the total number of test cases. 
 In each test cases, an integer N will be given.
Output:
For each testcase, in a new line, print number of possible ways to reach Nth stair.
Answer your output % 10^9+7.
1<=N<=100000
Generally this type of problem takes a lot of time , so don't forget to use fastio . 

*/
/*



*/

#include<iostream>
#include<math.h>
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL)  ; cout.tie(NULL) ; 
#define f(i,a,n) for(i = a ; i<=n ; i++)
#define endl '\n'

using namespace std ; 

int main () {
	fastio ;
	int t ; cin >> t; 
	// first we will find the solution for N = 100000 , then we will simply print the solution for each N 
	long long dp[100001] ; dp[0] = 1 ; dp[1] = 1 ; 
	int i ;int  m = pow(10 ,9) + 7 ; 
	f(i , 2 , 100000) dp[i] = (dp[i-1]%m + dp[i-2]%m)%m ; 
	while(t--) {
		int n ; cin >> n ; 
		cout << dp[n] << endl ; 
	}
	return 0 ; 

}