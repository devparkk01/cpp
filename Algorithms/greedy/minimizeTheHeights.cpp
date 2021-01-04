/* Given an array arr[] denoting heights of N towers and a positive integer K, you have to
modify the height of each tower either by increasing or decreasing them by K only once.
After modifying, height should be a non-negative integer.
Find out what could be the possible minimum difference of the height of shortest and
longest towers after you have modified each tower.

https://stackoverflow.com/questions/32233916/minimum-difference-between-heights-of-towers/63220955#63220955

*/


int getMinDiff(int arr[], int n, int k) {
	if ( n == 1 ) return 0 ;
	sort(arr , arr + n ) ;
	int maxTower = arr[n - 1 ] ,  minTower = arr[0] ;
	int result = maxTower - minTower ;
	for (int i = 1 ; i < n;  ++i ) {
		if ( arr[i] - k >= 0 ) {
			maxTower = max(arr[i - 1] + k , arr[n - 1] - k ) ;
			minTower = min(arr[0] + k , arr[i] - k);
			result = min(result , maxTower - minTower ) ;
		}
	}
	return result ;
}


