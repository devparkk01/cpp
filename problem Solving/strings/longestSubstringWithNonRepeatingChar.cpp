/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0 ;
        int n = s.length(); 
        int maxLen = 0 ; 

        unordered_set<char> seen;
        char c ;  

        for(int r = 0; r < n ; ++r){
            c = s[r];
            if ( seen.find(c) != seen.end() ) { 
                while( seen.find(c) != seen.end()) {
                    seen.erase(s[l]);
                    l++; 
                }
            }
            seen.insert(c);
            maxLen = max(maxLen , r - l + 1);
        }
        return maxLen; 
    }
};

