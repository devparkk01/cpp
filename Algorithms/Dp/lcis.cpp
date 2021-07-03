/* Given two arrays, arr1[] and arr2[] of sizes M and N respectively,
 find the length of the longest common increasing subsequence(LCIS).

*/

int LCIS(int arr1[], int m, int arr2[], int n) {
	int lcis[n ] ; memset(lcis , 0 , sizeof(lcis))  ;

	for (int i = 0 ; i <  m ; ++i ) {
		int temp = 0 ;
		for (int j = 0 ; j < n ; ++j ) {
			if ( arr1[i] == arr2[j]) {
				if ( temp + 1 > lcis[j]) {
					lcis[j] = 1 + temp ;
				}
			}
			else if ( arr1[i] >  arr2[j]) {
				if (lcis[j] > temp ) {
					temp = lcis[j] ;
				}
			}
		}
	}

	return *max_element(lcis , lcis + n  ) ;


}