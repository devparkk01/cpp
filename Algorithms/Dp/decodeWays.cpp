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
        // handle the case when first character is 0
        if ( s[0] == '0') {
            return 0;
        }
        ways[0] = 1;
        ways[1] = 1; 

        for(int i = 2 ;  i < ways.size() ; ++i)  {
            char ch = s[i - 1];
            // if the character is not '0'
            if ( ch != '0') {
                ways[i] = ways[i - 1];
            }
            string lastTwo = s.substr(i - 2, 2);
            if ( lastTwo >= "10" && lastTwo <= "26") {
                ways[i] += ways[i - 2];
            }
        }
        return ways[n];
    }
};