/*
There are N stairs, and a person standing at the bottom wants to reach the top.
The person can climb either 1 stair or 2 stairs at a time. Count the number of ways,
the person can reach the top (order does not matter).
Note: Order does not matter means for n=4 {1 2 1},{2 1 1},{1 1 2} are considered same.

this problem is same as ways coin change where order does not matter
*/


long long countWays(int m)
{
	long long dp[m + 1] = {0};

	dp[0] = 1;
	dp[1] = 1;

	for (int steps : {1 , 2 }) {
		for (int i =  2 ; i <= m ; ++i ) {
			dp[i] += (dp[i - steps]) ;
		}
	}

	return dp[m];
}