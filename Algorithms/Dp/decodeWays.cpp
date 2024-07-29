/*
https://leetcode.com/problems/decode-ways/description/
*/


#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(); 
        vector<int>ways(n + 1, -1);

        return util(s, n , ways);

    }

    int util(string &s, int n , vector<int>&ways) {
        if( n == 0) return 1;
        if ( n == 1) {
            if ( s[0] == '0') return 0 ;
            return 1; 
        }
        if (ways[n] != -1) return ways[n];

        int ans = 0 ;
        int num = s[n-1] - '0'; 
        if ( num == 0) {
            if ( s[n -2] - '0' == 1 || s[n -2] - '0' == 2) {
                ans = util(s, n -2 , ways); 
            }
        }
        else {
            ans = util(s, n - 1, ways);
            string temp = s.substr(n-2, 2);
            if ( stoi(temp) <= 26 && stoi(temp) > 10) {
                ans += util(s, n -2, ways);
            }
        } 
        ways[n] = ans ;
        return ways[n];
    }
};