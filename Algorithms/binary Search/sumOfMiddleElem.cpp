/*https://practice.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays2305/1/


very similar to median of two sorted arrays
time : O(log n)
*/


class Solution {
public:
	int findMidSum(int a[], int b[], int n) {
		int low = 0 , high = n ;

		while (low <= high) {
			int cut1 = (low + high) / 2 ;
			int cut2 = n - cut1 ;

			int left1 = (cut1 == 0 ) ? INT_MIN  : a[cut1 - 1] ;
			int left2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1] ;
			int right1 = (cut1 == n) ? INT_MAX : a[cut1] ;
			int right2 = (cut2 == n) ? INT_MAX : b[cut2] ;

			if (left1 <= right2 && left2 <= right1) {
				return max(left1 , left2) + min(right1 , right2) ;
			}
			else if ( left1 > right2) high = cut1 - 1 ;
			else if (left2 > right1) low = cut1 + 1 ;
		}

		return 0 ;






	}
};