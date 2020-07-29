/*
Given an array of length n which contains elements from 0 to n-1 , both inclusive 
you need to find all the elements occurring more than once in the given array.
if there is no element then return -1 
The order of the output should be in sorted order.

arr = [2,3,5,3,2,1]  len = 6 
for above array , returned value is  { 2 , 3  }

arr = [3,2,3,5,3,0,1,2,4]   returned  value = { 2 , 3 } 
arr = [1,4,3,2,5]  returned value = -1 , since there are no duplicates 

Time complexity should be O(n) and space complexity should be O(1) 
Note : The extra space is only for the array to be returned.

*/
#include<iostream>
#include<vector>
using namespace std ; 

vector<int> findDuplicates(int arr[] , int n ) {
	for (int i = 0 ; i < n ; ++i ) {
		int index=  arr[i] % n; 
		arr[index] += n ;

	}
	vector<int> v; v.reserve(n) ;
	for (int i =0 ; i < n  ; ++i) {
		if (arr[i]/n > 1 ) v.push_back(i) ; 
	}
	if (v.size() == 0 ) v.push_back(-1) ;

	return v; 
}


int main () {
	int arr[] = {4,5,4,6,2,0,2,3,3,1} ; 
	// int arr[] = {2,3,4,5,6,1,0} ; 
	int n = sizeof(arr )/ sizeof(int) ; 
	vector<int> v =  findDuplicates(arr ,n ) ;
	for (int i = 0 ; i < v.size() ; ++i ) cout << v[i]<< " "  ; 

	return 0 ; 
}