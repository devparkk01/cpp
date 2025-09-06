/*
https://leetcode.com/problems/decode-ways/description/
*/


#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(); 
        vector<int>ways(n + 1); 
        // ways[i] stores no of ways to decode characters till (i-1)th character in the string 
        // ways[n] stores no of ways to decode characters till (n -1)the character in the string 

        if (s[0] == '0') return 0; 

        ways[0] = 1;
        ways[1] = 1; 

        for(int i = 2; i <=n ; ++i) {
            int ch = s[i - 1] ;
            // check if single digit decode is possible 
            if (ch != '0') { // ch = {1, 9}
                ways[i] = ways[i - 1];
            }
            // check if this character and last character helps us make a double digit group
            int lastTwo = stoi(s.substr(i -2, 2));
            if ( lastTwo >= 10 && lastTwo <= 26) {
                ways[i] += ways[i - 2];
            }
        }

        return ways[n];

    }
};