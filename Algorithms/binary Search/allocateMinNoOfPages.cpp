
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm> 
using namespace std ; 

bool isvalid(int arr[] , int n , int k , long maxPages ) {
	int students = 1 ;
	long sum = 0 ;
	for(int i = 0 ; i < n ; ++i ) {
		if ( arr[i] > maxPages) return false ; 
		else if ( sum + arr[i] > maxPages ) {
			students++ ; 
			sum = arr[i]  ; 
			if ( students > k ) return false ; 
		}
		else sum += arr[i] ; 
	}
	return true ; 
}

int MinNoOfPages(int arr[] , int n , int k ) {
	if (k > n ) return -1 ; 
	long low = 0 ; 
	long high = accumulate(arr , arr + n, 0 ) ; 
	long mid ; long res = high ; 
	
	while ( low <= high ) {
		mid = low + (high - low )/ 2 ; 
		if (isvalid(arr , n , k , mid )) {
			res = min(res , mid) ;
			high = mid - 1 ; 
		}
		else 
			low = mid + 1 ; 
	}
	return res ; 
}

signed main () {
	// int arr[] = {20 ,10 , 30 , 50} ; 
	int arr[] = {10 , 20 , 30 , 40} ; 
	int n = sizeof(arr)/sizeof(int) ; 
	int k = 3 -1  ; 	
	cout << MinNoOfPages(arr , n , k ) << endl; 

	return 0 ;  
}