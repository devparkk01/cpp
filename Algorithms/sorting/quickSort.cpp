/* Let's implement quick sort 
	space : O(1)
	time : worst case : O(n*n) , average case : O(nlogn)
*/
#include<bits/stdc++.h>
using namespace std ; 

int partition(int arr[] , int low , int high) {
	int pivot = arr[high] ;
	int i = low-1 ; 

	for(int j = low ; j < high ; ++j ) {
		if ( arr[j] < pivot ) {
			i++ ; 
			swap(arr[i] , arr[j]) ; 
		}
	}
	swap(arr[i+1] , arr[high]) ;
	return i+1 ; 
}

void quickSort(int arr[] , int low , int high ) {
	if (low < high ) {
		int pi = partition(arr , low , high) ; 
		quickSort(arr , low , pi-1 ) ; 
		quickSort(arr, pi+1 , high ) ; 
	}
}

void print(int arr[] , int low , int high ) {
	for(int i = low ; i <= high ; ++i ) 
		cout << arr[i] << " " ; 
	cout << endl; 
}

signed main() {
	int arr[] = {10 ,80 ,30 , 90 , 40 , 50 , 70 } ; 
	int n = sizeof(arr)/sizeof(arr[0]) ; 
    cout << "Before sorting : " << endl ; 
	print(arr, 0 , n-1 ) ; 
	quickSort(arr , 0 , n-1 ) ;
	cout << "After sorting  : " << endl; 
	print(arr , 0 , n-1 ) ;
	return 0 ; 

}