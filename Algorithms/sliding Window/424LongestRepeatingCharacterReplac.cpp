/*
Very nice sliding window problem 

https://leetcode.com/problems/longest-repeating-character-replacement/description

time: O(26 *n ), space : O(26)

There is an alternate solution which makes time : O(n), I did not understand it fully. 
*/

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(); 
        int maxFreqCount = 0;  // stores max frequency of the character occuring in the window 
        int ans =0 ; 
        int l = 0 ;
        vector<int>freq(26);

        for(int r = 0 ;r < n ; r++) {
            freq[s[r] - 'A']++; // include the character from the right side into the window
            // update maxFreqCount
            maxFreqCount = max(maxFreqCount, freq[s[r] - 'A']);

            // ( r- l + 1) represent the current window length
            // if the difference between the window length and maxFreqCount is more than k 
            while( r- l + 1 - maxFreqCount > k ) {
                // we need to shrink the window from left side 
                freq[s[l] - 'A']--; 
                l++; 

                // update maxFreqCount 
                maxFreqCount = *max_element(freq.begin(), freq.end());
            }
            ans = max(ans, r- l + 1);

        }
        return ans; 
    }
};