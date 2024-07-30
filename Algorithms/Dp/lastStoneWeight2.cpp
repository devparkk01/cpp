/*
https://leetcode.com/problems/last-stone-weight-ii/description/


variation of subset sum problem which in turn is a variation of knapsack problem.


Think of this as dividing the stones in two piles. first pile and second pile.
We smash stones from the first pile with the stones from the second pile. 
The idea is to minimise the resultant stones after smashing. 

Ideally, we would want to divide the stones in two piles, in such a way that both the piles 
have equal weight, so that we are left with no stones at the end. But this won't be possible always to 
divide all stones into equal half. We start the algorithm with if it is possible to divide the stones
into two pile such that both have equal weight, that means, if first pile has half the weights then 
consequently second pile will have other half. 

*/

#include<bits/stdc++.h>
using namespace std; 

// top down 
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totalStones = accumulate(stones.begin(), stones.end(), 0);
        int firstPile = maximisePile(stones, totalStones); 
        int secondPile = totalStones - firstPile; 
        return abs(secondPile - firstPile);

    }

    int maximisePile(vector<int>&stones, int totalStones ) {
        int n = stones.size(); 
        int pile = totalStones / 2; 
        // dp[i][j] stores if it is possible to get the pile weight of j when we have first i elements to choose from. 
        vector<vector<bool>>dp(n + 1, vector<bool>(pile+1));

        // when there are no elements, then there is no way to get any pile weight. 
        for(int j = 0 ; j <= pile ; ++j) {
            dp[0][j] = false; 
        }
        // when the pile weight is 0, then it is possible to get this 0 pile weight with any no of elements, by simply not choosing
        // any element from the set 
        for(int i = 0 ; i <= n ; ++i) {
            dp[i][0] = true; 
        }

        for(int i = 1 ; i <= n ; ++i) {
            for(int j = 1 ; j <= pile ; ++j) {
                if( stones[i - 1] <= j) {
                    bool include = dp[i -1][j - stones[i - 1]];
                    bool exclude = dp[i -1][j];
                    dp[i][j] = include || exclude ;  
                } else {
                    dp[i][j] = dp[i -1][j];
                }
            }
        }

        for(int j = pile ; j >= 0 ; --j) {
            if ( dp[n][j] == 1) return j;
        }
        return -1; 
    }
};

// bottom up 
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totalStones = accumulate(stones.begin(), stones.end(), 0);
        int firstPile = maximisePile(stones, totalStones); 
        int secondPile = totalStones - firstPile; 
        return abs(secondPile - firstPile);

    }

    int maximisePile(vector<int>&stones, int totalStones ) {
        int n = stones.size(); 
        int pile = totalStones / 2; 
        // dp[i][j] stores if it is possible to get the pile weight of j when we have first i elements to choose from. 
        vector<vector<bool>>dp(n + 1, vector<bool>(pile+1));

        // when there are no elements, then there is no way to get any pile weight. 
        for(int j = 0 ; j <= pile ; ++j) {
            dp[0][j] = false; 
        }
        // when the pile weight is 0, then it is possible to get this 0 pile weight with any no of elements, by simply not choosing
        // any element from the set 
        for(int i = 0 ; i <= n ; ++i) {
            dp[i][0] = true; 
        }

        for(int i = 1 ; i <= n ; ++i) {
            for(int j = 1 ; j <= pile ; ++j) {
                // if the weight of the ith stone is less than j
                // we can either put in our first pile, or not put it
                if( stones[i - 1] <= j) {
                    bool include = dp[i -1][j - stones[i - 1]];
                    bool exclude = dp[i -1][j];
                    dp[i][j] = include || exclude ;  
                } else {
                    dp[i][j] = dp[i -1][j];
                }
            }
        }

        for(int j = pile ; j >= 0 ; --j) {
            if ( dp[n][j] == 1) return j;
        }
        return -1; 
    }
};