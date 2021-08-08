/*
we will find nth real root of any given number m
using binary search

time : n * O(log (m * (10 ^ d )))

*/

#include<bits/stdc++.h>
using namespace std ;


double multiply(double mid , int n ) {
	double prod = 1 ;
	for (int i = 0 ; i < n ; ++i ) {
		prod *= mid ;
	}
	return prod ;
}

void nthRoot(int n , int m ) {
	double low = 1 , high = m ;
	double mid ;
	double diff = 1e-6 ; // correct upto five decimal places , there will be onlydifference at 6th decimal place
	while ((high - low ) > diff) {
		mid = (high + low ) / 2 ;

		if (multiply(mid , n) < m) {
			low = mid ;
		}
		else {
			high = mid ;
		}
	}
	cout << low << "   " << high << endl; // low and high are almost same , difference is very little
	cout << pow(low , n) ; // for verification purpose


}


int main () {

	int m = 16 ;
	int n = 5 ;
	nthRoot(n , m  )  ;


	return 0 ;
}