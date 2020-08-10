/* Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

A[] = {1 2 3 -2 5}
maxSum = 9
A[] =  {-1 -2 -3 -4}
maxSum = -1 
*/
#include<bits/stdc++.h> 
using namespace std ; 


int kadanes(int A[] , int n ) {
	int maxSum = A[0] ; 
	int curSum = A[0] ; 
	for(int i = 1 ; i < n ; ++i ) {
		curSum  = max(curSum + A[i] , A[i]) ; 
		maxSum = max(maxSum , curSum ) ;
	}
	return maxSum ; 

}



int main () {
	int A[] = {1, 2, 3, -2, 5} ; 
	int n = sizeof(A)/sizeof(int ) ; 
	cout <<kadanes(A, n ) << endl; 

	return 0 ; 
}