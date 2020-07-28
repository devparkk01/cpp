/*
You're given an array of non-negative integers where each non zero integer represents the height
of a pillar of width 1 . Imagine water being poured over all of the pillars . Write a function 
that returns the surface area of the water trapped between the pillars . 
*/

#include<bits/stdc++.h>

using namespace std ;
//  time : O(n) , space : O(1) 

int waterArea (int * heights , int n ) {
	int left[n] , right[n] ; 
	left[0] = heights[0] ;
	for (int i = 1 ; i < n; ++i ) left[i] = max(left[i-1] , heights[i]) ;

	right[n-1] = heights[n-1] ;
	for (int i = n-2 ; i >= 0 ; --i) right[i] = max(right[i+1] , heights[i]) ;
	int area  = 0  ;
	for (int i = 0 ; i < n ; i++) 
		area  += ( min (left[i] , right[i]) - heights[i]) ; 
	return area ; 
}

int main () {
	int n ; cin >> n; 
	int heights[n] ;
	for (int i = 0 ; i < n; ++i) cin >> heights[i] ;

	cout << "Water area : " << waterArea(heights , n ) ; 

	return 0 ; 
}