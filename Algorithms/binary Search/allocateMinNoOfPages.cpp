/*You are given N number of books. Every ith book has A[i] number of pages. 
You have to allocate books to k number of students. There can be many ways or permutations
to do so. In each permutation, one of the k students will be allocated the maximum number 
of pages. Out of all these permutations, the task is to find that particular permutation in 
which the maximum number of pages allocated to a student is minimum of those in all the other 
permutations and print this minimum value. 

Each book will be allocated to exactly one student. Each student has to be allocated at 
least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous 
order (see the explanation for better understanding).

Input:
N = 4
A[] = {12,34,67,90}
k = 2 
Output: 113

Allocation can be done in following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90}  Maximum Pages =113
Therefore, the minimum of these cases is 
113, which is selected as the output.

  
*/

#include<bits/stdc++.h>

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