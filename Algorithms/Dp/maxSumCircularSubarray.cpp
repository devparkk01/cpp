/* Given a circular integer array , find a subarray with the largest sum in it .


This question is a variation of kadane's algorithm
time :O(n) , space : O(1)
*/

int circularSubarraySum(int arr[], int n) {
	int curmax = arr[0] ;
	int curmin = curmax , maxsum = curmax  , minsum = curmax ;
	// maxsum : max subarray sum , minsum : min subarray sum

	int sum = accumulate(arr , arr + n , 0) ;

	for (int i = 1 ; i < n ; ++i ) {
		curmax = max(curmax + arr[i] , arr[i]) ;
		maxsum = max(maxsum , curmax ) ;

		curmin = min(curmin + arr[i] , arr[i]) ;
		minsum = min(minsum , curmin ) ;
	}
	/*if sum == minsum,then it means all elements in the array are negative.when all elements are
	negative then max subarray sum would be largest element or smallest negative element .
	so , maxsum will store that value .
	but if we do max(maxsum , sum - minsum ) then it will become max(maxsum , 0 ) and since
	maxsum is negative , our answer will become 0 . that's y we simply return answer as maxsum
	in that case .

	*/
	if ( sum == minsum ) return maxsum ;
	else return max(maxsum , sum - minsum )  ;

}