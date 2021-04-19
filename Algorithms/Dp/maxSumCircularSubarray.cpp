/* Given a circular integer array , find a subarray with the largest sum in it .


This question is a variation of kadane's algorithm
*/

int circularSubarraySum(int arr[], int n) {
	int curmax = arr[0] ;
	int curmin = curmax , maxsum = curmax  , minsum = curmax ;

	int sum = accumulate(arr , arr + n , 0) ;

	for (int i = 1 ; i < n ; ++i ) {
		curmax = max(curmax + arr[i] , arr[i]) ;
		maxsum = max(maxsum , curmax ) ;


		curmin = min(curmin + arr[i] , arr[i]) ;
		minsum = min(minsum , curmin ) ;
	}

	if ( sum == minsum ) return maxsum ;
	else return max(maxsum , sum - minsum )  ;

}