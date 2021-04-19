/*https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#



*/

ll merge(ll arr[] , int low , int high , int mid ) {
	ll invert = 0 ;
	ll temp[high - low + 1 ] ;
	int i = low , j = mid + 1 , k = 0 ;
	while ( i <= mid && j <= high) {
		if ( arr[i] <= arr[j]) {
			temp[k] = arr[i] ;
			k++ ; i++ ;
		}
		else {
			temp[k] = arr[j] ;
			invert += (mid - i + 1 ) ;
			k++ ; j++ ;
		}
	}
	// if ( i <= mid ) {ans += (mid - i ) ; }
	while ( i <= mid ) {
		temp[k] = arr[i] ;
		k++ ; i++ ;
	}
	while (j <= high) {
		temp[k] = arr[j] ;
		k++ ; j++ ;
	}
	k = 0 ;
	for (int i = low ; i <= high ; ++i ) {
		arr[i] = temp[k] ; k++ ;
	}
	return invert ;

}
ll mergesort(ll arr[] , int low , int high ) {
	ll invert = 0 ;
	if ( low < high ) {
		int mid = low + ( high - low) / 2 ;
		invert += mergesort(arr , low , mid ) ;
		invert += mergesort(arr , mid + 1 , high ) ;
		invert += merge(arr , low , high , mid ) ;
	}
	return invert ;
}

long long int inversionCount(long long arr[], long long n)
{
	// Your Code Here
	ll ans = mergesort(arr , 0 ,  n - 1 ) ;
	return ans;

}