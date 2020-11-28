/*Given a sorted array, find the element in the array which has minimum difference
 with the given number k . Return this difference
*/

/* if k is found in the array , then return 0 ,
else , keep doing normal binary search , in the end low will point to an element just
greater than k , and high will point to an element just lesser than k  .

return minimum of differences between these elements and k .
*/

#include<iostream>
#include<vector>
using namespace  std ;


int minimumDifference(vector<int>&arr , int k) {
	int n = arr.size() ;

	if ( k < arr[0]) return arr[0] - k ;
	else if ( k > arr[n - 1 ]) return k - arr[n - 1 ] ;

	int low = 0 , high = n - 1 ;
	int mid ;



	while (low <= high ) {
		mid = low + (high - low ) / 2 ;
		if (arr[mid] == k ) return 0 ;
		else if (k < arr[mid] )
			high = mid - 1;
		else if (k > arr[mid])
			low = mid + 1 ;
	}
	return min(abs (arr[low] - k ), abs(arr[high] - k )) ;
}


signed main () {
	vector<int>nums = {1 , 2 , 3 , 5 , 6, 10 , 15  } ;
	int k = 8 ;
	cout << minimumDifference(nums , k ) << endl;

	return 0 ;

}