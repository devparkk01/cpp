/* Given an array of length N consisting of only 0s and 1s in random order. sort this array .

*/

void segregate0and1(int arr[], int n) {
	int i = 0 , j = n - 1 ;
	while (i < j ) {
		if ( arr[i] == 0 ) i++ ;
		else if ( arr[j] == 1) j-- ;
		else if ( arr[i] == 1 && arr[j] == 0 ) {
			swap(arr[i] , arr[j]) ;
			i++ ; j-- ;
		}
	}
}