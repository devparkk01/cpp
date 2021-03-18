/*Given an array of integers where each element represents the max number of steps that can be made
forward from that element . The task is to find the minimum number of jumps to reach the end of the
array.If it's not possible return -1 .
arr = {1 , 3 ,5 , 8 , 9 , 2 ,6, 7, 6, 8 , 9 }, n = 11 ,   jumps = 3
arr = {3 , 4 , 2 , 1 , 2 , 3 , 7 , 1,1 , 1 ,3  } n = 11  , jumps = 4
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define INF 1e9

using namespace std ;
// dynamic programming approach, time : O(n * n) , space = O(n)

int jump(vector<int>& nums) {

    int n = nums.size() ;
    vector<int>j(n , INF) ;
    j[0] = 0 ;

    int maxpos , k ;
    for (int i = 0 ; i < n ; ++i ) {
        maxpos = i + nums[i] ;
        k = i + 1 ;
        while ( k < n && k <= maxpos ) {
            j[k] = min(j[k] , 1 + j[i]) ;
            k++ ;
        }
    }
    return (j[n - 1 ] == INF ) ? -1 : j[n - 1 ] ;
}

// greedy method  time : O(n) , space : O(1)

int minJumps (int *arr , int n ) {
    if (n <= 1 ) return 0 ;
    if ( arr[0] == 0) return -1 ;

    int i = 0 ;
    int maxReach = arr[i];  int steps = maxReach - i ; int jump = 1 ;
    i++ ;
    for ( i ; i < n ; ++i)  {
        if ( i == n - 1) return jump ;

        steps-- ;
        maxReach = max(maxReach , arr[i] + i ) ;

        if  ( steps == 0 ) {
            if (i == maxReach ) return -1 ;

            jump++ ;
            steps = maxReach - i ;
        }
    }
    return -1 ;
}




int main() {
    int n ; cin >> n;
    int arr[n] ;
    for (int i = 0 ; i < n; ++i ) cin >> arr[i] ;
    cout << minJumps(arr,  n ) << endl ;




}