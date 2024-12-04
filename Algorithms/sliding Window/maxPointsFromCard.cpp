/* https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/


Here , we can use sliding window approach to find minimum sum of subarray of n-k size  .
*/


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int windowSum = 0 ;

        for(int i = 0 ; i < k ; ++i) {
            windowSum += cardPoints[i];
        }
        int ans = windowSum; 

        for(int i = k - 1 ; i >= 0 ; --i) {
            windowSum += (-cardPoints[i] + cardPoints[i + n - k]);
            ans = max(ans, windowSum);
        }
    
        return ans;
    }
};