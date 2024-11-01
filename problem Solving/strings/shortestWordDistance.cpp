/*
https://leetcode.com/problems/shortest-word-distance/description/


*/

#include<bits/stdc++.h>

class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        // index1 stores word1 indexes, index2 stores word2 indexes
        int index1 = -1, index2 = -1; 
        int minDist = INT_MAX; 

        for(int i = 0 ; i < wordsDict.size(); ++i) {
            if ( wordsDict[i] == word1) {
                index1 = i ; 
            } else if ( wordsDict[i] == word2) {
                index2 = i; 
            }
            if ( index1 != -1 && index2 != -1) {
                minDist = min(minDist, abs(index1 - index2));
            }
        }

        return minDist; 
    }
};