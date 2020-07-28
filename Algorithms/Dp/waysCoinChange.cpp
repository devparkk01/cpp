/*
Given an array of positive integers representing coin denomination and a single non negative integer n 
representing a target amount of money , write a function that returns the number of ways to make change
for that target amount using the given coin denominations . 	

denoms = { 2 ,5 ,3 ,6 } , n = 10 
total ways = 5 

*/
// we used dynamic programming here . 
#include<iostream>
#include <vector>
#define endl '\n' 

using namespace std;

// time : O(n) , space : O(n) 
int numberOfWaysToMakeChange(int n, vector<int> denoms) {
	vector<int> ways (n+1) ; // ways[i] stores total different ways we can make change for i cents . 
	ways[0] = 1 ; //we can make change for 0 in only 1 way. 
	for (int denom : denoms ) {
		for (int i = denom ; i <= n ; ++i ) {
			ways[i] += ways[i- denom] ; 
		}
	}
	return ways[n] ; 

}

int main () {
	int coins, n ;  cin >>coins >> n  ; 
	vector<int> denoms(coins); 
	for (int i = 0 ; i < coins ; ++i ) cin >> denoms[i] ;

	cout << numberOfWaysToMakeChange(n , denoms) ;
	return 0 ; 
}