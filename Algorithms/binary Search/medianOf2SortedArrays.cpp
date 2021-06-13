/*


time : O(log(min(n , m )))

*/


class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2 , nums1) ;

		int n = nums1.size() ;
		int m = nums2.size() ;
		int half = (n + m ) / 2 ;
		int l = 0 , h = n ;

		while (l <= h) {
			int cut1 = (l + h ) / 2 ;
			int cut2 = half - cut1 ;

			int left1 = (cut1 != 0 ) ? nums1[cut1 - 1 ] : INT_MIN ;
			int left2 = (cut2 != 0  ) ? nums2[cut2 - 1] : INT_MIN ;
			int right1 = ( cut1 != n ) ? nums1[cut1 ] : INT_MAX ;
			int right2 = (cut2 != m ) ? nums2[cut2] : INT_MAX ;

			if (left1 <= right2 && left2 <= right1) {
				if ((n + m) % 2 == 0 ) {
					return (max(left1, left2) + min(right1 , right2)) / 2.0  ;
				}
				else return min(right1 , right2) ;

			}
			else if (left1 > right2) h = cut1 - 1;
			else if (left2 > right1) l = cut1 + 1 ;

		}
		return 1.0 ;



	}
};