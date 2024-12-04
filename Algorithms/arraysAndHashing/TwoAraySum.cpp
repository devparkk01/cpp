/* 
given an array A[] of n numbers and another number x, determine whether or not
there exist two elements in S whose sum is exactly x.
1 4 45 6 10 8  , sum = 16 
{ 6 , 10 }  

*/
#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std ; 

//first method , time : O(n) , space : O(n)
void twoSum (vector<int> arr , int sum ) {
	unordered_set<int>uset ; 
	for (int elem : arr) {
		if ( uset.count(sum - elem) == 0 ) uset.insert(elem) ;
		else {
			cout << "YES" << endl; 
			return ; 
		}
	}
	cout << "NO" << endl ;
}

// second method , time: O(nlogn) , space : O(1)
void twoSum (vector<int> arr , int sum ) {
	sort(arr.begin() , arr.end()) ; 
	int l = 0 ; int r = arr.size() -1 ; 
	while ( l < r ) {
		int temp = arr[l] + arr[r] ;
		if ( temp == sum) {
			cout << "Yes" << endl; return ; 
		}
		else if ( temp < sum ) {
			l++ ;
		}
		else {
			r-- ; 
		}
	}
	cout << "No" << endl;
}