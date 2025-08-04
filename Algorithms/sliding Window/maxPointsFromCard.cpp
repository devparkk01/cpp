/* https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/


Here , we can use sliding window approach to find minimum sum of subarray of n-k size  .
*/


class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int windowSum = 0 ; 
        int n = cardPoints.size();
        // include first k element into the windowSum
        for(int start = 0 ; start < k ; ++start) {
            windowSum += cardPoints[start];
        }
        int maxSum = windowSum ;

        for(int start= k -1 ; start >= 0 ; --start) { 
            int endIndex = ( n- k + start); // element to be added from the end 
            windowSum += (-cardPoints[start] + cardPoints[endIndex]);
            maxSum = max(maxSum, windowSum);
        }

        return maxSum;
    }
};