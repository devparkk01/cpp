/* https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

Given an array nums[] , return the max absolute sum of any subarray of nums[]

Approach : This question is a variation of kadane's algo .

*/

// time : O(n) , space : O(1)
int maxAbsoluteSum(vector<int>& nums) {
	int cursum1 = nums[0] ; // current max sum of the subarray
	int cursum2 = nums[0] ; // current min sum of the subarray

	int maxsum = cursum1 ; // global max sum
	int minsum = cursum2 ; // global min sum

	for (int i = 1 ; i < nums.size() ; ++i ) {
		cursum1 = max(cursum1 + nums[i] , nums[i]) ;
		maxsum = max(maxsum , cursum1 ) ;

		cursum2 = min(cursum2 + nums[i] , nums[i]) ;
		minsum = min(cursum2 , minsum) ;
	}

	return max(maxsum , abs(minsum)) ;
}



