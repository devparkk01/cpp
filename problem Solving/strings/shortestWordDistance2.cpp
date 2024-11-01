/*

https://leetcode.com/problems/shortest-word-distance-ii/description/



*/

#include<bits/stdc++.h>


class WordDistance {

private:
    unordered_map<string, vector<int>> hashmap; 
public:

    WordDistance(vector<string>& wordsDict) {
        for(int i = 0 ; i < wordsDict.size() ; ++i ) {
            hashmap[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int minDiff = INT_MAX; 
        auto array1 = hashmap[word1]; 
        auto array2 = hashmap[word2];

        // i points to values in array1, j points to values in array2
        int i = 0 , j = 0;

        while(i < array1.size() && j < array2.size()) {
            minDiff = min(minDiff, abs(array1[i] - array2[j]));
            // whichever value is smaller, move the pointer corresponding to that 
            if ( array1[i] < array2[j]) {
                i++;
            } else {
                j++;
            }
        }
        return minDiff; 
    }
};
