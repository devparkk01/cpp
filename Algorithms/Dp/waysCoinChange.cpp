/*
Given an array of positive integers representing coin denomination and a single non negative integer n 
representing a target amount of money , write a function that returns the number of unique ways to make 
change for that target amount using the given coin denominations . 	

denoms = { 2 ,5 ,3 ,6 } , n = 10 
total ways = 5 

*/
// we used dynamic programming here . 
#include<bits/stdc++.h>
#define endl '\n' 

using namespace std;

// for unique ways ( [1,2] and [2,1] are considered same )
// order of coins doesn't matter 

// time : O(n*d) , space : O(n)
int uniqueWaysToMakeChange(int n, vector<int> denoms) {
	vector<int> ways (n+1) ; // ways[i] stores total different ways we can make change for i cents . 
	ways[0] = 1 ; //we can make change for 0 in only 1 way. 
	for (int &denom : denoms ) {
		for (int i = denom ; i <= n ; ++i ) {
			ways[i] += ways[i- denom] ; 
		}
	}
	return ways[n] ; 

}

// gives total no of ways ([1,2] and [2,1] are considered different )
// order of coins matter 
int WaysToMakeChange(int n, vector<int> denoms) {
	vector<int>ways(n+1) ; 
	ways[0] = 1 ;
	for(int amount = 0 ; amount <= n ; ++amount ) {
		for(int &denom : denoms ) {
			if ( denom <= amount ) {
				ways[amount] += ways[amount-denom] ; 
			}
		}
	}
	return ways[n] ; 

}

int main () {
	int coins, n ;  cin >>coins >> n  ; 
	vector<int> denoms(coins); 
	for (int i = 0 ; i < coins ; ++i ) cin >> denoms[i] ;

	cout << uniqueWaysToMakeChange(n , denoms) << endl; 
	cout << WaysToMakeChange(n , denoms) << endl; 
	return 0 ; 
}