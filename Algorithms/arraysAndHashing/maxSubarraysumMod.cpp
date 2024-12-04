/*https://www.hackerrank.com/challenges/maximum-subarray-sum/problem
https://www.youtube.com/watch?v=u_ft5jCDZXk&feature=youtu.be&ab_channel=alGOds

Given an array of n integers, and an integer m , determine the maximum value of the 
'sum of any of its subarrays modulo m ' . 

n = 5 , m =  7
arr[] = {3 3 9 9 5 } 
output : 6 


*/
#include<iostream>
#include<vector>
#include<set> 
using namespace std;  

/* time : O( nlog n ) , space : O(n) */ 

long maximumSum(vector<long>a  , long m ) {
	int n = a.size() ; 
	vector<long>prefixSum(n) ;
	set<long>modularSum ; 

	prefixSum[0] =  a[0] % m ;
	modularSum.insert(prefixSum[0]) ; 
	long ans = prefixSum[0] ; 

	for(int j = 1 ; j < n ; ++j) {
		prefixSum[j] = (prefixSum[j-1] + a[j] ) % m ;
		modularSum.insert(prefixSum[j]) ;
		set<long>::iterator it = modularSum.find(prefixSum[j]) ; 
		it++ ; 
		if ( it != modularSum.end()) {
			ans = max(ans , (prefixSum[j] - *it + m ) %m ) ; 
		}
		else {
			ans = max(ans , prefixSum[j]) ; 
		}
	}

	return ans ; 
}

signed main () {
	vector<long> a = {3 ,3, 9, 9, 5 } ;
	int m = 7 ;
	cout << maximumSum(a , m ) << endl ; 

	return 0 ;
}