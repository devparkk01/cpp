// A Dynamic Programming based 
// solution for 0-1 Knapsack problem 
#include<iostream> 
using namespace std ; 
  
int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 
  
// Returns the maximum value that 
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
    int i, w; 
    int **dp = new int*[n+1] ; 
    for (int i = 0 ; i <= n ; ++i) {
        dp[i] = new int[W+1] ; 
        for (int j = 0 ; j <= n ; ++j ) {
            dp[i][j] = 0  ; 
        }
    }

  
    // Build table dp[][] in bottom up manner 
    for (i = 0; i <= n; i++) { 
        for (w = 0; w <= W; w++) { 
            if (i == 0 || w == 0) 
                dp[i][w] = 0; 
            else if (wt[i - 1] <= w) 
                dp[i][w] = max( val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]); 
            else
                dp[i][w] = dp[i - 1][w]; 
        } 
    } 
  
    return dp[n][W]; 
} 
  
int main() 
{ 
    int n ; 
    cout << "Enter no of objects : " << endl; 
    cin >> n; 
    int *wt = new int[n] ; 
    int *pt = new int[n] ; 
    cout << "Enter weight of objects : "  << endl ; 
    for ( int i = 0 ; i< n ; ++i ) {
        cin >> wt[i] ; 
    }
    cout << "Enter profit of objects : "  << endl ; 
    for ( int i = 0 ; i< n ; ++i ) {
        cin >> pt[i] ; 
    }
    int W ; 
    cout << "Enter minimum weight : " << endl; 
    cin >> W ; 

    // int val[] = { 60, 100, 120 }; 
    // int wt[] = { 10, 20, 30 }; 
    // int W = 50; 
    // int n = sizeof(val) / sizeof(val[0]); 
    cout << knapSack(W , wt , pt , n )  ; 
    // printf("%d", knapSack(W, wt, val, n)); 
    return 0; 


} 