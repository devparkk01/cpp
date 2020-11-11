/*https://www.hackerrank.com/challenges/lonely-integer/problem

You will be given an array of integers. All of the integers except one occur twice. That one is 
unique in the array.
Given an array of integers, find and print the unique element.

int a[] = { 2 , 1 , 5 , 3 , 2 , 1 , 3 } ; 
output : 5 (it occurs only once )

idea : Use bitwise xor operator 

a ^ a = 0 , a ^ 0 = a ,

*/
#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ; 
using namespace std ; 

int lonelyInteger(vector<int>&a ) {
	int res = 0 ; 
	for(int &x : a ) {
		res = res ^ x ; 
	}
	return res ; 
}


signed main (){
	fastio ; 
	vector<int>a = { 2 , 1 , 5 , 3 , 2 , 1 , 3 } ; 
	cout << lonelyInteger(a) << endl; 
	return 0 ; 
}