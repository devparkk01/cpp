/* We define f (X, Y) as number of different corresponding bits in binary representation of X and Y.
For example, f (2, 7) = 2, since binary representation of 2 and 7 are 010 and 111, respectively.
 The first and the third bit differ, so f (2, 7) = 2.

You are given an array A of N integers, A1, A2 ,…, AN. Find sum of f(Ai, Aj) for all
pairs (i, j) such that 1 ≤ i, j ≤ N. Return the answer modulo 10^9+7.

Input: N = 3
A = {1, 3, 5}
Output: 8
Explaination: We return
f(1, 1) + f(1, 3) + f(1, 5) +
f(3, 1) + f(3, 3) + f(3, 5) +
f(5, 1) + f(5, 3) + f(5, 5) =
0 + 1 + 1 +
1 + 0 + 2 +
1 + 2 + 0 = 8.
*/
/*approach 1 :
for any pair count the number of bit differences , time : O(n * n )
*/
/* approach2 2 :


*/

#define mod 1000000007
int countBits(int n, long long int a[])
{
	// code here
	int ans = 0 ;
	for (int i = 0 ; i < 32 ; ++i ) {
		int f = 1 << i ;
		int set = 0 , unset = 0 ;
		for (int i = 0 ; i < n ; ++i ) {
			if ( a[i] & f) set++ ;
			else unset++   ;
		}
		ans = (ans + (2 * set * unset ) ) % mod ;
		// ans += (2 * set * unset) % mod ;
	}
	return ans  ;
}

