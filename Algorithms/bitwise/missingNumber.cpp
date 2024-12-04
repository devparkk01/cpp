/*
Given an array of size N-1 such that it can only contain distinct integers in the range
of 1 to N. Find the missing element.
N = 5;
a = {1,2,3,5} ;
output : 4
idea is to use bit wise xor operator

a ^ a = 0 , a ^ 0 = a , a ^ b = non zero ( if a != b)

*/

#include<bits/stdc++.h>
using namespace std ;

int missingNumber(vector<int>&a , int N ) {
	int res = 0 ;
	for (int &x : a ) res = res ^ x ;
	for (int i = 1; i <= N ; ++i) res = res ^ i ;

	return res ;
}



signed main () {
	int N = 5;
	vector<int> a = {1, 2, 3, 5} ;
	int res ;
	cout << missingNumber(a , N ) << endl;

	return 0 ;
}