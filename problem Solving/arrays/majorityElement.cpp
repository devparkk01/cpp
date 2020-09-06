/*Given an array A of N elements. Find the majority element in the array. 
A majority element in an array A of size N is an element that appears more than [N/2] times in
the array.
*/

#include<bits/stdc++.h>
using namespace std ;  

int majority_element (vector<int>&nums ) {
	int maj_elem = -1 ; int count = 1 ; 
	for(int num : nums ) {
		if ( maj_elem == num ) count++ ; 
		else count-- ; 
		if (count == 0 ) {
			maj_elem = num ; 
			count = 1 ; 
		}
	}
	count = 0 ; 
	for(int num : nums ) {
		if ( maj_elem == num ) count++ ; 
	}
	return ( count > nums.size() /2 ) ? maj_elem : -1 ; 
}

int main () {
	vector<int> nums  = {4,5 ,2, 5, 4, 5, 3 } ; 
	cout << majority_element(nums ) << endl; 
	return 0 ;
}