/*
https://leetcode.com/problems/distinct-subsequences/


*/


#include<bits/stdc++.h>
using namespace std; 



// top down approach 
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(); 
        int n = t.size(); 
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, -1));
        return util(s, t, m , n, dp );
    }

    int util(string s, string t, int m , int n, vector<vector<int>>&dp) {
        if( n == 0 ) return 1; 
        if ( m == 0) return 0; 
        if ( dp[m][n] != -1) return dp[m][n];
        if (s[m -1] == t[n -1]) {
            dp[m][n] =  util(s, t, m -1 , n -1 , dp)  + util( s, t, m -1, n, dp );
        }
        else {
            dp[m][n] = util(s, t, m -1, n, dp);
        }
        return dp[m][n];
    }
};

// bottom up approach 
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(); 
        int n = t.size(); 
        // dp[i][j] stores the no of times t[1...j] occurs as a subsequence in s[1...i]
        vector<vector<unsigned int >>dp(m + 1, vector<unsigned int>(n + 1));
        // if i == 0, then we don' have any character in s, hence count of subsequences will be 0 
        for(int j = 0 ; j <= n ; ++j) dp[0][j] = 0 ; 
        for(int i = 0 ; i <= m ; ++i) dp[i][0] = 1; 

        for(int i = 1; i <= m ; ++i) {
            for(int j = 1; j <= n ; ++j) {
                if (s[i -1] == t[j -1]) {
                    // 1. count the no of times remaining characters of t occurs as a subsequence in remaining characters of s
                    // 2. count the no of itmes same characters of t occurs as a subsequence in remaining characters of s. 
                    dp[i][j] = dp[i -1][j -1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i -1][j];
                }
            }
        }
        return dp[m][n];
    }

};