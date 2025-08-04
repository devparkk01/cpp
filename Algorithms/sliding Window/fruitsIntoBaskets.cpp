/*
https://leetcode.com/problems/fruit-into-baskets/description/


brute force: O(n*n)
sliding window = o(n)
*/

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxFruits = 0 ; 
        
        // stores the counts of fruits for each fruit type currently in the basket
        unordered_map<int, int >fruitsCount;  // key: fruit type, value: no of fruit of that type 
        int l = 0; // left side of the window 
        
        for(int r = 0; r < fruits.size() ; ++r) {
            fruitsCount[fruits[r]]++; // insert this fruit into the basket

            while(fruitsCount.size() > 2 ) {
                // keep moving the left pointer, ie. keep removing fruits from the basket from 
                // left side 
                fruitsCount[fruits[l]]--;
                if(fruitsCount[fruits[l]] == 0) {
                    fruitsCount.erase(fruits[l]);
                }
                l++; 
            }
            maxFruits = max(maxFruits, r - l + 1); 

        }
        return maxFruits; 
        
    }
};