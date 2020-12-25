/* https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/


Here , we can use sliding window approach to find minimum sum of subarray of n-k size  .
*/


class Solution {
public:
	int maxScore(vector<int>& cardPoints, int k) {
		int n = cardPoints.size() ;
		int sum = accumulate(cardPoints.begin() , cardPoints.end() , 0 ) ;
		int window = n - k ;
		int winSum = 0 ;
		for (int i = 0  ; i < n - k ; ++i ) {
			winSum += cardPoints[i] ;
		}
		int minSum = winSum ;

		for (int i = n - k ; i < n; ++i ) {
			winSum += (cardPoints[i] - cardPoints[i - window ]) ;
			minSum = min( minSum , winSum ) ;
		}
		return sum - minSum ;
	}
};