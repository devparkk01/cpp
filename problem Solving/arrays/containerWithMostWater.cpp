
/* Given N non-negative integers a1,a2,....an where each represents a point at coordinate (i, ai).
N vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i,0).
 Find two lines, which together with x-axis forms a container, such that it contains the most water.


first approach : take two loops . time : O(n * n )

second approach : using  two pointer , time : O(n)
*/

long long maxArea(long long a[], int len)
{
	int i  = 0 , j = len - 1 ;
	long long ans = 0 ;
	while (i  < j ) {
		ans = max(ans , min(a[i] , a[j]) * (j - i ) ) ;
		if ( a[i] < a[j]) i++;
		else j-- ;
	}
	return ans;
}