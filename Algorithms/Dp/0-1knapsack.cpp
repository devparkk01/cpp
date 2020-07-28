/*
Given weights and values ( profits ) of n items, put these item in a knapsack of max capacity
`W` to get the maximum total value in the knapsack . 0/1 property here is that , we can not break 
an item , we can either pick  the complete item or don't pick it .  return the maxvalue of the knapsack 
and as well as the items which have been selected to be put in the knapsack . 
*/
/*
n = 4 
val[] = {1 , 4 ,5 , 7}
wt[] = {1 , 3 , 4 ,5 } 
W = 7 
answer = 7 , {4 , 3 }

*/

#include<iostream>
#include<vector>
#include<algorithm>  // for max() function 
#define endl '\n'

using namespace std ; 

// // using typical array 

// void knapSack (int *wt , int * val , int W , int n ) {
//     int dp[n+1][W+1] ; 
//     for ( int i = 0 ; i<= n; ++i ) {
//         for (int j = 0 ; j <= W ; ++j) {
//             if ( i == 0 || j == 0 ) {
//                 dp[i][j] = 0 ; 
//             }
//             else if ( wt[i-1] <= j) {
//                 dp[i][j] = max(dp[i-1][j] , val[i-1 ] + dp[i-1][j-wt[i-1]] ) ; 
//             }
//             else {
//                 dp[i][j] = dp[i-1][j] ;
//             }
//         }
//     }
//     int maxVal = dp[n][W] ; 
//     cout << "Max value : " << maxVal << endl; 

//     int i = n , j = W ; 
//     cout << "Items : " ; 
//     while ( maxVal > 0 ){
//         if ( dp[i][j]  != dp[i-1][j]) {
//             cout << wt[i-1] << " " ; 
//             maxVal-= val[i-1] ;
//             j-=wt[i-1] ; 
//         }
//         i-- ; 
//     }

// }


// using vector 

void knapSack(int * wt , int * val , int W , int n  ) {
    /*  initializing vector */
    vector<int> dp[n+1] ;  
    // vector<vector<int>>dp(n+1) ; 
    for ( int i = 0 ;i <=n ; ++i ) {
        dp[i] = vector<int>(W+1) ; 
    }
    // find maxVal 
    for (int i = 1 ; i <= n; ++i ) {
        for (int j = 1 ;j <= W; ++j ) {
            if ( wt[i-1] <= j ) {
                dp[i][j] = max(dp[i-1][j] , val[i-1] + dp[i-1][j-wt[i-1]] ) ; 
            }
            else { 
                dp[i][j] = dp[i-1][j]; 
            }
        }
    }
    int maxVal = dp[n][W] ;
    cout <<"Max value : " << maxVal << endl; 
    int i = n , j = W ; 

    cout << "Items : " ;
    while (maxVal > 0 ) {
        if ( dp[i][j] != dp[i-1][j]) {
            cout << wt[i-1] << "  "; 
            maxVal-=val[i-1] ;
            j-=wt[i-1] ; 
        }
        i--  ; 
    }

}

int main () {
    int n  ; 
    cout << "Enter n : " ; 
    cin >> n ; 
    int wt[n]; int val[n] ;
    cout << "Enter val and weights  : " << endl ;
    for ( int i = 0 ;i <n ; ++i ) {
        cin >> val[i] >> wt[i] ; 
    }
    cout << "Enter max capacity : " << endl; 
    int W ; 
    cin >> W ; 


    knapSack(wt , val , W , n) ;

    return 0 ; 


}
