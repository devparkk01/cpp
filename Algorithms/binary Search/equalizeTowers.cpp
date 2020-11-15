/*Given heights h[] of N towers, the task is to bring every tower to the same height by either
adding or removing blocks in a tower. Every addition or removal operation costs cost[] 
a particular value for the respective tower. Find out the Minimum cost to Equalize the Towers.

h[] = {1, 2, 3} 
cost[] = {10, 100, 1000}
Output: 120( for height 3 )

h[] = {9, 12, 18, 3, 10} 
cost[] = {100, 110, 150, 25, 99}
Output: 1623 (for height 12 )

Idea : 
Use binary search 

out equivalent height could be any heights between *min_element(h,h+n) and *max_element(h,h+n)
we will use binary search to find the height for which we will minimum cost .

*/
#include<bits/stdc++.h>
using namespace std ; 

// finds the cost to bring every tower to height 'eqh'
long long findCost(int h[] , int cost[] , int n , int eqh) {
    long long total = 0 ; 
    for(int i = 0 ; i < n ; ++i ) {
        total+=(abs(h[i] - eqh ) * cost[i]) ; 
    }
    return total ; 
    
}

long long equalizeTowers(int h[], int cost[], int n) { 
	int low = *min_element(h , h+n) ; 
	int high = *max_element(h , h+n) ;
	int mid ; 
	long long midCost , nextCost , prevCost ; 
	// midCost for mid , nextCost for mid +1 , prevCost for mid - 1 
	
	while (low <= high ) {
	    mid =  low + (high - low ) / 2 ; 
	    midCost = findCost(h , cost , n , mid ) ; 
	    nextCost = findCost(h , cost , n , mid + 1 ) ; 
	    prevCost = findCost(h , cost , n , mid - 1 ) ; 
	    if ( midCost <= nextCost && midCost <= prevCost ) return midCost ; 
	    else if( midCost < nextCost ) high = mid -1 ; 
	    else if ( midCost< prevCost ) low = mid + 1 ; 
	    
	}
	return -1 ; 

}
signed main () {
	int h[] = {9, 12, 18, 3, 10} ;
	int cost[] = {100, 110, 150, 25, 99} ;
	int n = sizeof(h)/ sizeof(int ) ;
	cout << equalizeTowers(h , cost , n ) << endl  ;

	return 0 ; 
}