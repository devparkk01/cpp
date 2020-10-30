/*
Given weights and values ( profits ) of n items, put these item in a knapsack of max capacity
`w` to get the maximum total value in the knapsack . 0/1 property here is that , we can not break 
an item , we can either pick  the complete item or don't pick it . return the max profit of the 
knapsack and as well as the items which have been selected to be put in the knapsack . 
*/

/*
n = 4 
wt[] = {1 , 3 , 4 ,5 } 
profit[] = {1 , 4 ,5 , 7}
w = 7 
answer = 9 , weights of the items included : 3 , 4 

*/

#include<bits/stdc++.h>
#define endl '\n'

using namespace std ; 

// Recursive appraoch , time : O(2 ^n )
// int knapSack(int wt[] , int profit[] , int n , int w ) {
//     if ( n== 0 || w == 0 ) return 0 ;
//     if ( wt[n-1] > w) 
//         return knapSack(wt , profit, n-1 , w) ; 
//     else {
//         int include = profit[n-1] + knapSack(wt , profit, n-1 , w - wt[n-1]) ; 
//         int exclude = knapSack(wt , profit , n-1 , w ) ;
//         return max(include , exclude) ; 
//     }
// }

// Dynamic programming approach , time : O(n * w)
/* top down */

// int knapSackUtil(int wt[] , int profit[] , int n , int w , int dp[101][101]) {
//     if (n == 0 || w == 0 ) return 0 ; 
//     if (dp[n][w] != -1) return dp[n][w] ; 
//     if ( wt[n-1] > w)
//         dp[n][w] = knapSackUtil(wt , profit , n-1 , w , dp) ;
//     else {
//         int include = profit[n-1] + knapSackUtil(wt ,profit , n-1 , w - wt[n-1] , dp) ; 
//         int exclude = knapSackUtil(wt , profit , n-1, w ,dp) ; 
//         dp[n][w] = max(include , exclude) ;
//     }
//     return dp[n][w] ; 
// }

// int knapSack(int wt[] , int profit[], int n , int w ) {
//     int dp[101][101] ;
//     memset(dp , -1,  sizeof(dp)) ; 
//     return knapSackUtil(wt , profit , n , w , dp) ; 
// }

/* bottom up approach  */

void knapSack(int wt[] , int profit[] , int n , int w) {
    int dp[n+1][w+1] ; 
    for(int i = 0 ; i <= n ; ++i ) {
        for(int j = 0 ; j <= w ; ++j ) {
            if ( i == 0 || j == 0 ) dp[i][j] = 0 ;
            else if (wt[i-1] > j ) dp[i][j] = dp[i-1][j] ; 
            else 
                dp[i][j] = max(profit[i-1] + dp[i-1][j-wt[i-1]] , dp[i-1][j]); 
        }
    }
    int maxProfit = dp[n][w] ; 
    cout << "Max profit : " << maxProfit << endl ; 

    int i = n , j = w ;
    while(maxProfit > 0 ) {
        if ( dp[i][j] != dp[i-1][j] ) {
            cout << wt[i-1] << endl; 
            maxProfit -= profit[i-1] ; 
            j-=wt[i-1] ; 
        }
        i-- ; 
    }

}


int main () {
    int n  ; cin >> n ; 
    int wt[n]; int profit[n] ;

    for(int i = 0 ; i < n; ++i ) cin >> wt[i] ; 

    for(int i = 0 ; i < n ; ++i ) cin >> profit[i] ; 

    int w ; cin >> w ; 

    // cout << knapSack(wt , profit , n , w) ;
    knapSack(wt , profit , n ,w )  ; 

    return 0 ; 


}
