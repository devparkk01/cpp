/*

https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1#

*/

int mod = 1e9 + 7 ;
int countFriendsPairings(int n)
{
	int count[ n + 1 ] ;
	count[0] = 1 , count[1] = 1 ;
	long long temp ;
	for (int i = 2 ; i <= n ; ++i) {
		temp = (long long ) (i - 1) * count[i - 2 ] ;
		temp = temp % mod ;
		count[i] = (count[i - 1 ]  + temp ) % mod  ;
	}
	return count[n] ;
}
