/*Given arrival and departure times of all trains that reach a railway station.
Find the minimum number of platforms required for the railway station so that no train
is kept waiting.Consider that all the trains arrive on the same day and leave on the same
day. Arrival and departure time can never be the same for a train but we can have arrival
time of one train equal to departure time of the other. At any given instance of time,
same platform can not be used for both departure of a train and arrival of another
train. In such cases, we need different platforms,

*/

/* naive solution
Brute force approach given on gfg is wrong
*/

#include<bits/stdc++.h>
using namespace std ;
/*  greedy approach
sort both arr[] and dep[] , now follow the process similar to merge sort . we've two sorted arrays and
we need to merge them . see the notebook for explanation

*/

int findPlatform(int arr[], int dep[], int n) {
	sort(arr, arr +  n) ;
	sort(dep , dep + n ) ;
	int currentNoOfPlatforms = 0 ; // stores the no of platforms at that point of time
	int ans = 0 ; // our final answer
	int i = 0 , j = 0 ;
	while (i < n && j < n ) {
		if ( arr[i] <= dep[j]) {
			currentNoOfPlatforms++ ;
			i++ ;
			ans = max(ans , currentNoOfPlatforms) ;
		}
		else {
			currentNoOfPlatforms-- ;
			j++  ;
		}
	}
	return ans ;
}
signed main () {
	int n = 6 ;
	int arr[] = { 0200, 0210, 0300, 0320, 0350, 0500 };
	int dep[] = { 0230, 0340, 0320, 0430, 0400, 0520 };
	cout << findPlatform(arr , dep , n ) << endl ;

	return 0 ;
}

